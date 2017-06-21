#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, count, numprocs;	
	int numbers[3] = { 97, 40, 5}, buffer;
	MPI_Status Stat;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){
		int i,j;
		fprintf(stdout,"Process %d: Sending Number Array \n", rank);
		fflush(stdout);
		for(j=0; j<3; j++)		
			for(i = 1; i < numprocs; i++)			
				MPI_Send(&numbers[j], 1, MPI_INT, i, tag, MPI_COMM_WORLD); 
	}
	else{
		buffer = 0;
		while(buffer!=5){
			MPI_Recv(&buffer, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
			MPI_Get_count(&Stat, MPI_INT, &count);	
			fprintf(stdout,"Process %d: %d Received %d integers from Process %d\n",
			rank, buffer, count, Stat.MPI_SOURCE);
			fflush(stdout);
		}
	}	

	
	MPI_Finalize();
	return 0;
}