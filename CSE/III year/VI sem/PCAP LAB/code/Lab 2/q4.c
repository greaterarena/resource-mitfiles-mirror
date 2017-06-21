#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int addArray(int* arr, int len){
	int temp=0, i;	
	for(i=0; i<len; i++)
		temp += arr[i];
	return temp;
}

int main(int argc, char* argv[]){
	int rank, tag = 1, count, numprocs;	
	int* numbers, len = 0, buflen = 0, lentrack = 0;
	int buffer[1000], sum = 0, fsum = 0;
	
	MPI_Status Stat;	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){	
		int i;
		fprintf(stdout,"Enter Array Size - ");
		fflush(stdout);fflush(stdin);
		fscanf(stdin,"%d", &len);
		numbers = (int*) malloc(sizeof(int)*len);
		buflen = len/(numprocs-1);
		for(i=0; i<len; i++){
			fprintf(stdout,"Element %d = ", i+1);
			fflush(stdout);fflush(stdin);
			fscanf(stdin,"%d", &numbers[i]);
		}	

		for(i=1; i<numprocs; i++){
			if(i!=numprocs-1){
				lentrack += buflen;
				MPI_Send(&numbers[(i-1)*buflen], buflen, MPI_INT, i, tag, MPI_COMM_WORLD);
			}
			else
				MPI_Send(&numbers[(i-1)*buflen], len-lentrack, MPI_INT, i, tag, MPI_COMM_WORLD);			
		}
		
		for(i=1; i<numprocs; i++){
			MPI_Recv(&sum, 1, MPI_INT, i, tag, MPI_COMM_WORLD, &Stat);
			fsum += sum;
		}		
		fprintf(stdout,"Process %d: Final Sum = %d \n", rank, fsum);
		fflush(stdout);
	}
	else{		
		int i;
		MPI_Recv(&buffer, 1000, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
		MPI_Get_count(&Stat, MPI_INT, &count);	
		sum = addArray(buffer,count);
		fprintf(stdout,"Process %d: ",rank);		
		for(i=0; i<count; i++)
			fprintf(stdout,"%d ",buffer[i]);
		fflush(stdout);
		fprintf(stdout,"Process %d: Sum %d\n",rank, sum);
		fflush(stdout);
		MPI_Send(&sum, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}	
	
	MPI_Finalize();
	return 0;
}