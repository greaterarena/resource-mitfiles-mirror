#include "mpi.h"
#include <stdio.h>
#include <string.h>
#define bsize 50

int main(int argc,char* argv[])
{
	int rank,size;	char buffer[bsize];
	MPI_Status status1, status2;	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Buffer_attach(buffer,bsize);
	if(rank==0)
	{
		char* msg_send="BUFFER!", *msg_recv2;
		MPI_Bsend(&msg_send, 6, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
		MPI_Recv(&msg_recv2, 6, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &status2);
		fprintf(stdout, "PROC %d : %s",rank, msg_recv2);fflush(stdout);
	}
	if(rank==1)
	{
		char* msg_recv;
		MPI_Recv(&msg_recv, 6, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status1);
		fprintf(stdout, "PROC %d : %s",rank, msg_recv);
		fflush(stdout);
		MPI_Bsend(&msg_recv, 6, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
	}
	MPI_Finalize();
}