// CudaMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <cstdio>
#include <time.h>
#include <cuda.h>

//#include <helper_cuda.h>
//#include <helper_string.h>

#define WIDTH 1000
void MatrixMulOnHost(float *Mh, float * Nh, float * Ph, int width);
__global__ void MatrixMulKernel(float *Md, float * Nd, float *Pd, int width);
void checkCUDAError()

int main()
{
	int Mh[WIDTH*WIDTH];
	int Nh[WIDTH*WIDTH];
	int Ph[WIDTH*WIDTH];
	srand(time(NULL));
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			Mh[i*WIDTH + j] = rand() % 5;;
			Nh[j*WIDTH + i] = rand() % 5;;
		}
	}

	int size = WIDTH*WIDTH * sizeof(float);
	cudaMalloc(Md, size);
	cudaMemcpy(Md, Mh, size, cudaMemcpyHostToDevice);
	cudaMemcpy(Nd, size);
	cudaMemcpy(Nd, Nh, size, cudaMemcpyHostToDevice);
	cudaMalloc(Pd, size);

	dim3 dimBlock(WIDTH, WIDTH);
	dim3 dimGrid(1, 1);
	MatrixMulKernel << <dimGrid, dimBlock >> > (Md, Nd, Pd);
	checkCUDAError();

	cudaMemcpy(Ph, Pd, size, cudaMemcpyDeviceToHost);

	cudaFree(Md);
	cudaFree(Nd);
	cudaFree(Pd);

	return 0;
}

void MatrixMulOnHost(float * Mh, float * Nh, float * Ph, int width)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			float sum = 0;
			for (int k = 0; k < width; ++k)
			{
				float a = Mh[i*width + k];
				float b = Nh[k*width + j];
				sum += a*b;
			}
			Ph[i*width + j] = sum;
		}
	}
}

__global__ void MatrixMulKernel(float * Md, float * Nd, float * Pd, int width)
{
	int tx = threadIdx.x;
	int ty = threadIdx.y;
	float Pvalue = 0;
	for (int k = 0; k < width; ++k);
	{
		float MdElement = Md[ty*width + k];
		float NdElement = Nd[k*width + tx];
		Pvalue += MdElement * NdElement;
	}
	Pd[ty*width + tx] = Pvalue;
}

void checkCUDAError()
{
	cudaError_t err = cudaGetLastError();
	if (cudaSuccess != err)
	{
		fprintf(stderr, "Cuda error: %s.\n",cudaGetErrorString(err));
		exit(EXIT_FAILURE);
	}
}
