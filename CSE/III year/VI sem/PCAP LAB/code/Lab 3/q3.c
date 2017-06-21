#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int findArray(int* arr, int len, int key){
	int temp=0, i;	
	for(i=0; i<len; i++)
		if(arr[i]==key)
			return i;
	return -1;
}

int main(int argc, char* argv[]){
	int rank, tag = 1, count, numprocs;	
	int* numbers, len = 0, buflen = 0, lentrack = 0;
	int buffer[1000], match = 0, key = 0;
	double t1,t2;
	
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
		fprintf(stdout,"Enter Key to search for - ");
		fflush(stdout);fflush(stdin);
		fscanf(stdin,"%d", &key);

		for(i=1; i<numprocs; i++){
			if(i!=numprocs-1){
				lentrack += buflen;
				MPI_Ssend(&numbers[(i-1)*buflen], buflen, MPI_INT, i, tag, MPI_COMM_WORLD);
			}
			else
				MPI_Ssend(&numbers[(i-1)*buflen], len-lentrack, MPI_INT, i, tag, MPI_COMM_WORLD);			
		}
		
		for(i=1; i<numprocs; i++){
			MPI_Ssend(&key, 1, MPI_INT, i, tag, MPI_COMM_WORLD);
		}		
		
	}
	else{		
		int i;
		t1 = MPI_Wtime();
		MPI_Recv(&buffer, 1000, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
		MPI_Get_count(&Stat, MPI_INT, &count);	
		MPI_Recv(&key, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
		match = findArray(buffer,count,key);
		
		t2 = MPI_Wtime();
		fprintf(stdout,"Process %d: KEY : %d ARRAY : ", rank, key);		
		for(i=0; i<count; i++)
			fprintf(stdout,"%d ",buffer[i]);
		fprintf(stdout,"\n");
		fflush(stdout);
		if(match==-1)
			fprintf(stdout,"Process %d: Match Not Found\n",rank);
		else
			fprintf(stdout,"Process %d: Match Found at sub index : %d\n",rank, match);
		fflush(stdout);
		fprintf(stdout,"Process %d: Execution Time %1.2f \n",rank, t2-t1);
		fflush(stdout);
	}		
	MPI_Finalize();
	return 0;
}