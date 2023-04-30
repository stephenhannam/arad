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

	return 0;
}
