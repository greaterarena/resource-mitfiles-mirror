#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, tag = 1, count, numprocs;	
	char message[50] = "You shall not PASS!", buffer[500];
	MPI_Status Stat;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){
		int i;
		fprintf(stdout,"Process %d: I am the OVERLORD \n", rank);
		fflush(stdout);
		for(i = 1; i < numprocs; i++)
			MPI_Send(&message, strlen(message), MPI_CHAR, i, tag, MPI_COMM_WORLD); 
	}
	else{
		MPI_Recv(&buffer, 500, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &Stat);
		MPI_Get_count(&Stat, MPI_CHAR, &count);	
		buffer[count] = '\0';
		fprintf(stdout,"Process %d: MESSAGE - %s Received %d char(s) from Process %d\n",
        rank, buffer, count, Stat.MPI_SOURCE);
		fflush(stdout);
	}	

	
	MPI_Finalize();
	return 0;
}