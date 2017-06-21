#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, numprocs;	
	int* numbers = NULL, len = 0;
	int temp[2];
	
	MPI_Status Stat;	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){	
		int i;
		fprintf(stdout,"Array Size = %s\n", argv[1]);
		len = atoi(argv[1]) * 2;
		fflush(stdout);
		numbers = (int*) malloc(sizeof(int)*len);
		for(i=0; i<len; i++){
			fprintf(stdout,"Element %d = ", i+1);
			fflush(stdout);fflush(stdin);
			fscanf(stdin,"%d", &numbers[i]);
		}	
		fprintf(stdout,"\nInitiating Scatter\n\n");
		fflush(stdout);		
	}

	MPI_Scatter(numbers, 2, MPI_INT, temp, 2, MPI_INT, 0, MPI_COMM_WORLD);

	fprintf(stdout,"PROC %d - Received %d", rank, temp[1]);
	fflush(stdout);	

	MPI_Finalize();
	return 0;
}