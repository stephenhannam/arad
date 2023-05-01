#include <iostream>

#include "gpu.h"

// function to add the elements of two arrays
void addArraysCPU(double *x, double *y, int numElements)
{
	for (int i = 0; i < numElements; i++)
	{
		y[i] = x[i] + y[i];
	}
}


int main()
{
	std::cout << "Hello, world!" << std::endl;

	printCudaVersion();

	// Code to show how to add two arrays on the GPU 

	int N = 10;

	double *x_h = new double[N];
  	double *y_h = new double[N];

	// initialize x and y arrays on the host
	for (int i = 0; i < N; i++) {
		x_h[i] = 1.0;
		y_h[i] = 2.0;
	}

	// Allocate Unified Memory – accessible from CPU or GPU
	double *x_d;
  	double *y_d;
	cudaMalloc(&x_d, N*sizeof(double));
	cudaMalloc(&y_d, N*sizeof(double));

	// Copy data from host to device array
	cudaMemcpy(x_d, x_h, N*sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(y_d, y_h, N*sizeof(double), cudaMemcpyHostToDevice);

	// Run kernel on 1M elements on the GPU
	addArraysGPU(x_d, y_d, N, 0);

	// Wait for GPU to finish before accessing on host
	cudaDeviceSynchronize();

	// Copy values back to host arrays
	cudaMemcpy(x_h, x_d, N*sizeof(double), cudaMemcpyDeviceToHost);
	cudaMemcpy(y_h, y_d, N*sizeof(double), cudaMemcpyDeviceToHost);

	// Check for errors (all values should be 3.0f)
	for (int i = 0; i < N; i++)
	{
		std::cout << y_h[i] << std::endl;
	}

	// Free host memory
	free(x_h);
	free(y_h);

	// Free device memory
	cudaFree(x_d);
	cudaFree(y_d);
  


	return 0;
}
