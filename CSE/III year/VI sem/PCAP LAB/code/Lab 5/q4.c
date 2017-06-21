#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, numprocs, i;	
	int in = NULL, loc = 0, sum = 0, t=1;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	t = rank+1;
	MPI_Scan ( &t, &loc, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

	fprintf(stdout,"PROC %d - factorial of %d = %d", rank, rank+1, loc);fflush(stdout);

	MPI_Reduce(&loc, &sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);	

	if(rank==0){
		fprintf(stdout,"\nPROC %d - FINAL SUM - %d", rank, sum);
	}

	MPI_Finalize();
	return 0;
}