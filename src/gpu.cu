#include <iostream>
#include "gpu.h"

void printCudaVersion()
{
	std::cout << "CUDA Compiled version: " << __CUDACC_VER__ << std::endl;

	int runtime_ver;
	cudaRuntimeGetVersion(&runtime_ver);
	std::cout << "CUDA Runtime version: " << runtime_ver << std::endl;

	int driver_ver;
	cudaDriverGetVersion(&driver_ver);
	std::cout << "CUDA Driver version: " << driver_ver << std::endl;
}

/** 
 * @brief Sample Kernel function to add the elements of two arrays on the GPU. Each element
 * of x and y will be added together, with the result being stored in y
 * 
 * @param x first input array
 * @param y second input array
 * @param numElements number of elements in array x and y
 */
__global__ void addArraysKernel(double *x, double *y, int numElements)
{
	const auto idx = blockIdx.x * blockDim.x + threadIdx.x;
	
	if(idx < numElements)
	{
		y[idx] = x[idx] + y[idx];
	}
}

void addArraysGPU(double *x, double *y, int numElements, cudaStream_t stream)
{
	const int threads = 1024;
	const int blocks = (numElements + threads - 1) / threads;
	const int sharedMemory = 0;

	addArraysKernel<<<blocks, threads, sharedMemory, stream>>>(x, y, numElements);
}
