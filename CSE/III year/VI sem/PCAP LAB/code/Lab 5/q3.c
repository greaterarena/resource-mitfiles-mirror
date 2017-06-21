#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int factorial(int x){
	int temp = 1, i;
	for(i=1;i<=x;i++)
		temp *= i;
	return temp;
}

int main(int argc, char* argv[]){
	int rank, tag = 1, numprocs, i;	
	int in = NULL, loc = 0, sum = 0;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	

	loc = factorial(rank+1);
	fprintf(stdout,"PROC %d - factorial of %d = %d", rank, rank+1, loc);fflush(stdout);

	MPI_Reduce(&loc, &sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);	

	if(rank==0){
		fprintf(stdout,"\nPROC %d - FINAL SUM - %d", rank, sum);
	}

	MPI_Finalize();
	return 0;
}