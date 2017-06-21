/* Please Write the OpenCL Kernel(s) code here*/
__kernel void sum(__global int *A,__global int *B,__global int *C,int m,int n)
{
    
    int id=get_global_id(0);
    B[id]=0; C[id]=0;
    if(id<m)
    {
     for(int i=0;i<n;i++)
       {
           B[id]+=A[id*n+i];
       }   
    }
    else
    {
        for(int i=0;i<n;i++)
       {
           C[id-m]+=A[i*n+(id-m)];
       } 
    }
}