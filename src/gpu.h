#pragma once

#include <cuda_runtime_api.h>
#include <cuda.h>

void printCudaVersion();

/** 
 * @brief Sample function to add the elements of two arrays on the GPU. Each element
 * of x and y will be added together, with the result being stored in y
 * 
 * @param x first input array
 * @param y second input array
 * @param numElements number of elements in array x and y
 * @param stream the cuda stream to use
 *
 */
void addArraysGPU(double *x, double *y, int numElements, cudaStream_t stream);
