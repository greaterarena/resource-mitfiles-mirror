__kernel void string_rev(__global char *A,__global int* B, __global char *C)
{
int tid=get_global_id(0);
int i;
int pos=0;
for(i=0;i<tid;i++)
{
pos=pos+B[i];
pos=pos+1;
}
for(i=0;i<B[tid];i++)
{
C[pos+i]=A[pos-i-1+B[tid]];
}
C[pos+i]=' ';
}