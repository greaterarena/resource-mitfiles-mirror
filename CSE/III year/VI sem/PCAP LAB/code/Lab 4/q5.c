#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

float averager(float* x, float len){
	float sum = 0;
	int i;
	for(i=0;i<len;i++)
		sum += x[i];
	sum = sum/len;	
	return sum;
}

int main(int argc, char* argv[]){
	int rank, tag = 1, numprocs, i;	
	float* numbers = NULL, n = 0, m = 0;
	float* savg = NULL; float* temp = NULL;
	float iavg = 0;
	
	MPI_Status Stat;	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	

	if(rank == 0){	
		int i, j, c=0;		
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		fprintf(stdout,"n = %d\n", n); fflush(stdout);
		fprintf(stdout,"m = %d\n", m); fflush(stdout);
		numbers = (float*) malloc(sizeof(float)*(n*m));
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				fprintf(stdout,"Element %d for Proc %d = ", j,i+1);
				fflush(stdout);fflush(stdin);
				fscanf(stdin,"%f", &numbers[c++]);
			}
		}
		for(i = 1; i < numprocs; i++)
			MPI_Send(&m,1,MPI_INT,i,tag,MPI_COMM_WORLD);
		savg = (float*) malloc(sizeof(float)*m);
	}
	else{
		MPI_Recv(&m,1,MPI_INT,0,tag,MPI_COMM_WORLD,&Stat);
	}
	temp = (float*) malloc(sizeof(float)*m);

	MPI_Scatter(numbers, m, MPI_FLOAT, temp, m, MPI_FLOAT, 0, MPI_COMM_WORLD);

	iavg = averager(temp, m);

	fprintf(stdout,"PROC %d - Average - %f", rank, iavg);
	fflush(stdout);

	MPI_Gather(&iavg, 1, MPI_FLOAT, savg, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

	if(rank==0){
		float tempy = averager(savg, n);
		fprintf(stdout,"PROC %d - FINAL AVERAGE - %f", rank, tempy);
		fflush(stdout);
	}	

	MPI_Finalize();
	return 0;
}