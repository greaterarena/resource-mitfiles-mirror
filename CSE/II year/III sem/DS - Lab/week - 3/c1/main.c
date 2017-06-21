#include<stdio.h>

int fact(int x){
	if(x<=1){
			return 1;
	}
	else
		return x*fact(x-1);
}

int main(){
	int f;
	printf("enter a number -> ");
	scanf("%d", &f);
	int z = fact(f);
	printf("\nfactorial of %d -> %d", f, z);
}
