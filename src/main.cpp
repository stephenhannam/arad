#include <iostream>

#ifdef USE_CUDA
#include "gpu.h"
#endif

#include "./ports/InputPort.h"
#include "./ports/OutputPort.h"

int main()
{
    std::cout << "Hello, world!" << std::endl;

#ifdef USE_CUDA
    std::cout << "CUDA: On" << std::endl;
    printCudaVersion();
#else
    std::cout << "CUDA: Off" << std::endl;
#endif

    return 0;
}
