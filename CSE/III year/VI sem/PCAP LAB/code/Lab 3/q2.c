#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, count, numprocs;	
	int* numbers, len = 0, buflen = 0, lentrack = 0;
	int buffer=0, ans = 0;
	
	MPI_Status Stat;	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){	
		int i;
		fprintf(stdout,"Array Size = %s\n", argv[1]);
		len = atoi(argv[1]);
		fflush(stdout);
		numbers = (int*) malloc(sizeof(int)*len);
		for(i=0; i<len; i++){
			fprintf(stdout,"Element %d = ", i+1);
			fflush(stdout);fflush(stdin);
			fscanf(stdin,"%d", &numbers[i]);
		}	
		fprintf(stdout,"Process %d: Square of %d = %d\n",rank, numbers[0], numbers[0]*numbers[0]);
		fflush(stdout);
		for(i=1; i<numprocs; i++){
			if(i%2==0)
				MPI_Ssend(&numbers[i], 1, MPI_INT, i, tag, MPI_COMM_WORLD);
			else
				MPI_Ssend(&numbers[i], 1, MPI_INT, i, tag, MPI_COMM_WORLD);			
		}
	}
	else{		
		int i;
		MPI_Recv(&buffer, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
		MPI_Get_count(&Stat, MPI_INT, &count);	
		if(rank%2==0){
			ans = buffer*buffer;
			fprintf(stdout,"Process %d: Square of %d = %d\n",rank, buffer, ans);
		}
		else{
			ans = buffer*buffer*buffer;
			fprintf(stdout,"Process %d: Cube of %d = %d\n",rank, buffer, ans);
		}
		fflush(stdout);
	}	
	
	MPI_Finalize();
	return 0;
}