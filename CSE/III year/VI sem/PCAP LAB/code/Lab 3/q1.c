#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int rank, dest, src, tag, count;	
	char p1_message[50] = "zebra";
	char p2_message[50], buffer[500];
	MPI_Status Stat;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){
		src = 0; dest = 1; tag = 1;
		MPI_Ssend(&p1_message, strlen(p1_message), MPI_CHAR, dest, tag, MPI_COMM_WORLD); 

		src = 1; dest = 0; tag = 1;
		MPI_Recv(&p1_message, 50, MPI_CHAR, src, tag, MPI_COMM_WORLD, &Stat);
		MPI_Get_count(&Stat, MPI_CHAR, &count);	
		p1_message[count] = '\0';
		fprintf(stdout,"Process %d: MESSAGE - %s Received %d char(s) from Process %d with tag %d \n",
        rank, p1_message, count, Stat.MPI_SOURCE, Stat.MPI_TAG);
		fflush(stdout);
	}
	else if(rank == 1){
		src = 0; dest = 1; tag = 1; 
		MPI_Recv(&p2_message, 50, MPI_CHAR, src, tag, MPI_COMM_WORLD, &Stat);
		MPI_Get_count(&Stat, MPI_CHAR, &count);	
		p2_message[count] = '\0';
		fprintf(stdout,"Process %d: MESSAGE - %s Received %d char(s) from Process %d with tag %d \n",
        rank, p2_message, count, Stat.MPI_SOURCE, Stat.MPI_TAG);
		fflush(stdout);

		src = 1; dest = 0; tag = 1;
		MPI_Ssend(&p2_message, strlen(p2_message), MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	}	

	
	MPI_Finalize();
	return 0;
}