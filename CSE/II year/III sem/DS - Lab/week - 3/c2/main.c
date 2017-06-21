#include<stdio.h>

int gcd(int x, int y){
	int q = x%y;
	if(q == 0){
			return y;
	}
	else
		return gcd(x,q);
}

int main(){
	int f, g, z;
	printf("enter two numbers -> ");
	scanf("%d %d", &f, &g);
	if(g > f){z = gcd(g, f);}
	else{z = gcd(f, g);}
	printf("\ngcd of %d and %d -> %d", f, g, z);
}
