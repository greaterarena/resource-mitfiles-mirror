#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, numprocs, i;	
	int in = NULL, loc = 0, sum = 0;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	

	if(rank == 0){	
		int i, j, c=0;		
		fprintf(stdout,"Enter Number - "); fflush(stdout);
		fflush(stdin);
		fscanf(stdin,"%d", &in);		
		fprintf(stdout,"\nBroadcast Initiate\n\n");
		fflush(stdout);			
		MPI_Bcast(&in, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}
	else{
		MPI_Bcast(&in, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}

	loc = in*in;
	fprintf(stdout,"PROC %d - square - %d", rank, loc);fflush(stdout);

	MPI_Reduce(&loc, &sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);	
	
	if(rank==0){
		fprintf(stdout,"PROC %d - GLOBAL SUM - %d", rank, sum);
	}

	MPI_Finalize();
	return 0;
}