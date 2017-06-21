#include<stdio.h>
#include<stdlib.h>
#include<CL/cl.h>
#include<string.h>
#include<conio.h>
#define MAX_SOURCE_SIZE (0x100000)

int main(void)
{ int m,n;
printf("Enter the dimensions:");
scanf("%d%d",&m,&n);
printf("Enter the elements:");
int i;
int *A=(int *)malloc(m*n*sizeof(int));
int *B=(int *)malloc(m*sizeof(int));
int *C=(int *)malloc(n*sizeof(int));
for(i=0;i<m*n;i++)
{scanf("%d",&A[i]);}
FILE *fp;
char *source_str;
size_t source_size;
fp=fopen("RowColumnSum.cl","r");
if(!fp)
{
fprintf(stderr,"Failed to load kernal");
getchar();
exit(1);
}
source_str=(char*)malloc(MAX_SOURCE_SIZE);
source_size=fread(source_str,1,MAX_SOURCE_SIZE,fp);
fclose(fp);

cl_platform_id platform_id=NULL;
cl_device_id device_id=NULL;
cl_uint ret_num_devices;
cl_uint ret_num_platforms;
cl_int ret=clGetPlatformIDs(1,&platform_id,&ret_num_platforms);

ret=clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_GPU,1,&device_id,&ret_num_devices);

cl_context context=clCreateContext(NULL,1,&device_id,NULL,NULL,&ret);

cl_command_queue command_queue=clCreateCommandQueue(context,device_id,CL_QUEUE_PROFILING_ENABLE,&ret);

cl_mem a_mem_obj= clCreateBuffer(context,CL_MEM_READ_ONLY,m*n*sizeof(int),NULL,&ret);

cl_mem b_mem_obj= clCreateBuffer(context,CL_MEM_WRITE_ONLY,m*sizeof(int),NULL,&ret);

cl_mem c_mem_obj= clCreateBuffer(context,CL_MEM_WRITE_ONLY,n*sizeof(int),NULL,&ret);

ret=clEnqueueWriteBuffer(command_queue,a_mem_obj,CL_TRUE,0,m*n*sizeof(int),A,0,NULL,NULL);

cl_program program=clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t*)&source_size,&ret);

ret=clBuildProgram(program,1,&device_id,NULL,NULL,NULL);
cl_kernel kernel=clCreateKernel(program,"sum",&ret);
ret=clSetKernelArg(kernel,0,sizeof(cl_mem),(void *)&a_mem_obj);
ret=clSetKernelArg(kernel,1,sizeof(cl_mem),(void *)&b_mem_obj);
ret=clSetKernelArg(kernel,2,sizeof(cl_mem),(void *)&c_mem_obj);
cl_int cm=m;
cl_int cn=n;
ret=clSetKernelArg(kernel,3,sizeof(cl_int),(void *)&cm);
ret=clSetKernelArg(kernel,4,sizeof(cl_int),(void *)&cn);

size_t global_item_size=m+n;
size_t local_item_size=1;;

cl_event event;
ret=clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,&global_item_size,&local_item_size,0,NULL,&event);
cl_ulong time_start; cl_ulong time_stop;
double total_time;
ret=clFinish(command_queue);
clGetEventProfilingInfo(event,CL_PROFILING_COMMAND_START,sizeof(time_start),&time_start,NULL);
clGetEventProfilingInfo(event,CL_PROFILING_COMMAND_END,sizeof(time_start),&time_stop,NULL);
ret=clEnqueueReadBuffer(command_queue,b_mem_obj,CL_TRUE,0,m*sizeof(int),B,0,NULL,NULL);
ret=clEnqueueReadBuffer(command_queue,c_mem_obj,CL_TRUE,0,n*sizeof(int),C,0,NULL,NULL);
total_time=(double)(time_stop-time_start);
total_time/=1000000;
printf("\nDone");

printf("\nRow sums are\n");

for(i=0;i<m;i++)
{
	printf("%d ",B[i]);
}
printf("%\n");
printf("\nColumn sums are\n");

for(i=0;i<n;i++)
{
	printf("%d ",C[i]);
}
;
printf("\nTime taken=%f ms",total_time);
getchar();
ret=clFlush(command_queue);

ret=clReleaseKernel(kernel);
ret=clReleaseProgram(program);
ret=clReleaseMemObject(a_mem_obj);
ret=clReleaseMemObject(b_mem_obj);
ret=clReleaseMemObject(c_mem_obj);
ret=clReleaseCommandQueue(command_queue);
ret=clReleaseContext(context);

getch();

return 0;
}
