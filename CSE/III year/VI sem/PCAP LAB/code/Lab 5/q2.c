#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, numprocs, i;	
	int* numbers = NULL, n = 0, m = 0;
	int* temp = NULL, loc=0, sum=0;
	
	MPI_Status Stat;	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	

	if(rank == 0){	
		int i, j, c=0;		
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		numbers = (int*) malloc(sizeof(int)*(n*m));
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				fprintf(stdout,"Element %d for Proc %d = ", j,i+1);
				fflush(stdout);fflush(stdin);
				fscanf(stdin,"%d", &numbers[c++]);
			}
		}
		for(i = 1; i < numprocs; i++)
			MPI_Send(&m,1,MPI_INT,i,tag,MPI_COMM_WORLD);
		fprintf(stdout,"\nInitiating Scatter\n\n");
		fflush(stdout);	
	}
	else{
		MPI_Recv(&m,1,MPI_INT,0,tag,MPI_COMM_WORLD,&Stat);
	}

	temp = (int*) malloc(sizeof(int)*m);

	MPI_Scatter(numbers, m, MPI_INT, temp, m, MPI_INT, 0, MPI_COMM_WORLD);

	fprintf(stdout,"PROC %d - Received - ", rank);
	for(i=0; i<m; i++)
		fprintf(stdout,"%d ",temp[i]);
	fprintf(stdout,"\n");
	fflush(stdout);

	for(i=0;i<m;i++)
		loc += temp[i];

	fprintf(stdout,"PROC %d - SUM - %d", rank, loc);fflush(stdout);

	MPI_Reduce(&loc, &sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);	
	
	if(rank==0){
		fprintf(stdout,"PROC %d - GLOBAL SUM - %d", rank, sum);
	}


	MPI_Finalize();
	return 0;
}