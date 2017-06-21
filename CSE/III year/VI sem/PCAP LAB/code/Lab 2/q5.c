#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(int argc, char* argv[]){
	int myrank, error_code, c = 0;
	MPI_Init(&argc, &argv);
	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	error_code = MPI_Comm_rank(c, &myrank);
	if(error_code != MPI_SUCCESS){
		char error_string[BUFSIZ];
	   int length_of_error_string, error_class;
	   MPI_Error_class(error_code, &error_class);
	   MPI_Error_string(error_class, error_string, &length_of_error_string);
	   fprintf(stderr, "Error Class: %s\n", error_string);
	   MPI_Error_string(error_code, error_string, &length_of_error_string);
	   fprintf(stderr, "Error Code: %s\n", error_string);
	   return 0;
	}
	if(floor(sqrt((double)myrank)) == sqrt((double)myrank) && myrank != 0){
		printf("%d: Hello, World!", myrank);
		printf("\n%d: Input - %d %s %s",myrank, argc, argv[0], argv[1]);
	}
	MPI_Finalize();
	return 0;
}