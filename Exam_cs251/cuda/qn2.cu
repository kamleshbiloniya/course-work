#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>




#define CUDA_ERROR_EXIT(str) do{\
                                    cudaError err = cudaGetLastError();\
                                    if( err != cudaSuccess){\
                                             printf("Cuda Error: '%s' for %s\n", cudaGetErrorString(err), str);\
                                             exit(-1);\
                                    }\
                             }while(0);
#define TDIFF(start, end) ((end.tv_sec - start.tv_sec) * 1000000UL + (end.tv_usec - start.tv_usec))
__global__ void XOR(int *in,int *out){
  extern __shared__ int sm[];             //shared memory
	
  unsigned int tid=threadIdx.x;
  unsigned int i=blockIdx.x*blockDim.x+threadIdx.x;
	//printf("i=%d\n",i);
  sm[tid]=in[i];
  __syncthreads();                              //snchronizes all threads in a block
  for(unsigned int j=1;j<blockDim.x;j*=2){    //ech thread loads one element from global to shared memory
    if(tid%(2*j)==0){
      sm[tid]=sm[tid]^sm[tid+j];
    }
  }
    __syncthreads();
  
	//printf("till now ??\n");
  if(tid==0){//printf("debuger\n");
	out[blockIdx.x]=sm[0];
	//printf("from block: %d\n",out[0]);
	}
}


int main(int argc, char **argv){
  struct timeval start,end,t_start,t_end;
  unsigned int num_ele,seed;
  int *harr,*darr;
   int result=0;
  int *hout,*dout;
  int th_p_block=10;
  int b_p_grid;



  num_ele=atoi(argv[1]);
  seed=atoi(argv[2]);
  b_p_grid=(num_ele+th_p_block-1)/th_p_block;

  harr=(int*)malloc(num_ele*sizeof(int));
   if(!harr){
        perror("malloc");
        exit(-1);
   }



  hout=(int*)malloc(b_p_grid*sizeof(int));
 

  srand(seed);
  for(int i=0;i<num_ele;i++){
   //harr[i]=i+1;
   harr[i]=random()%100;
  }

  gettimeofday(&t_start,NULL);

  cudaMalloc(&darr,num_ele*sizeof(int));
  CUDA_ERROR_EXIT("cudaMalloc");

  cudaMalloc(&dout,b_p_grid*sizeof(int));
  CUDA_ERROR_EXIT("cudaMalloc");

	//printf("ok\n");
  cudaMemcpy(darr,harr,num_ele*sizeof(int),cudaMemcpyHostToDevice);
  CUDA_ERROR_EXIT("cudaMemcpy");
    //printf("after memcpy\n");
  //int th_p_block=10;
  //int b_p_grid=(num_ele+th_p_block-1)/th_p_block;
  gettimeofday(&start,NULL);
  XOR<<<b_p_grid, th_p_block,2048>>>(darr,dout);
  CUDA_ERROR_EXIT("kernel invocation");
	gettimeofday(&end,NULL);
    //printf("before memcpy2 D to H\n");
  cudaMemcpy(hout,dout,b_p_grid*sizeof(int),cudaMemcpyDeviceToHost);
   CUDA_ERROR_EXIT("memcpy");
	//printf("done\n");
  
for(int i=0;i<b_p_grid;i++){
     result=result^hout[i];
	//printf("res=%d harr=%d\n",result,harr[i]);
}
   printf("xor=%d\n", result);
   gettimeofday(&t_end,NULL);
printf("Total time = %ld microsecs Processsing =%ld microsecs\n", TDIFF(t_start, t_end), TDIFF(start, end));

   free(harr);
   free(hout);
   cudaFree(darr);
   cudaFree(dout);

  return 0;
}
