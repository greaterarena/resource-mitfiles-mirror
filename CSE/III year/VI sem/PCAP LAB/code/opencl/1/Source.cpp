# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<string.h>
# include <CL/cl.h>
# include <conio.h>
#define MAX_SOURCE_SIZE (0x100000)




int main(void)
{
	char tempstr[20486];

	int i,j=0;
	printf("\nEnter the string : ");
    gets(tempstr);
	int l=strlen(tempstr);
	tempstr[l]='\0';
	tempstr[l+1]='\0';
	printf("\nlength=%d",l);
	int len[10],ls;
	i=0;
	while(tempstr[i]!='\0')
	{
		printf("\nouter %d",j);
		ls=0;
		while(tempstr[i]!=' ' && tempstr[i]!='\0')
		{
			printf("\ninner %d",i);
			ls++;
			i++;
		}
		len[j]=ls;
		j++;
		i++;
	}
	printf("\nj=%d",j);
	int n=j;
	printf("\nn=%d",n);
	int *lp=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("\n%d",len[i]);
		lp[i]=len[i];
	}



	char *str=(char*)malloc(l*sizeof(char));
	strcpy(str,tempstr);
	FILE *fp;
	char *source_str;
	size_t source_size;
	fp=fopen("string.cl", "r");
	if(!fp)
	{
		fprintf(stderr,"Failed to load kernel \n");
		getchar();
		exit(1);
	}
	source_str=(char*)malloc(MAX_SOURCE_SIZE);
	source_size=fread(source_str,1,MAX_SOURCE_SIZE, fp);
	fclose(fp);


	cl_platform_id platform_id=NULL;
	cl_device_id device_id=NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int ret=clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret= clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU,1 ,&device_id, &ret_num_devices);

	cl_context context= clCreateContext( NULL,1, &device_id,NULL,NULL,&ret);


	cl_command_queue command_queue=clCreateCommandQueue(context, device_id,0, &ret);

	cl_mem a_mem_obj= clCreateBuffer(context, CL_MEM_READ_ONLY, (l+1)*sizeof(char), NULL, &ret);
	cl_mem b_mem_obj= clCreateBuffer(context, CL_MEM_READ_ONLY, (n)*sizeof(int), NULL, &ret);
	cl_mem c_mem_obj= clCreateBuffer(context, CL_MEM_WRITE_ONLY, (l)*sizeof(char), NULL, &ret);

	ret=clEnqueueWriteBuffer(command_queue, a_mem_obj,CL_TRUE,0, (l)*sizeof(char), str, 0,NULL,NULL);
	ret=clEnqueueWriteBuffer(command_queue, b_mem_obj,CL_TRUE,0, n*sizeof(int), lp, 0,NULL,NULL);


	cl_program program=clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);

	ret=clBuildProgram(program,1, &device_id,NULL,NULL,NULL);


	cl_kernel kernel= clCreateKernel(program, "string_rev", &ret);
	ret=clSetKernelArg( kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
	ret=clSetKernelArg( kernel, 1, sizeof(cl_mem), (void*)&b_mem_obj);
	ret=clSetKernelArg( kernel, 2, sizeof(cl_mem), (void*)&c_mem_obj);


	size_t global_item_size= n;
	size_t local_item_size= 1;

	char *str1=(char*)malloc(sizeof(char)*(l));
	cl_event event;
	ret= clEnqueueNDRangeKernel(command_queue, kernel, 1,NULL, &global_item_size, &local_item_size,0,NULL,NULL);

	ret= clFinish(command_queue);
	ret=clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0 ,(l)*sizeof(char), str1, 0, NULL,NULL);

	printf("\nDONE");
	str1[l]='\0';
	printf("\nresultant string %s",str1);
	getchar();
	ret= clFlush(command_queue);
	ret= clReleaseKernel(kernel);
	ret= clReleaseProgram(program);
	ret= clReleaseMemObject(a_mem_obj);
	ret= clReleaseMemObject(b_mem_obj);
	ret= clReleaseMemObject(c_mem_obj);
	ret= clReleaseCommandQueue(command_queue);
	ret= clReleaseContext(context);
	getch();
}
