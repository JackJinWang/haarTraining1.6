#pragma once
#include"MyMat.h"
void GetGrayIntegralImage(unsigned char *Src, int *Integral, int Width, int Height, int Stride); //求解积分图
void GetGraySqImage(unsigned char *Src, int *Integral, int Width, int Height, int Stride); //求解平方积分图
void bubbleSort(int* pData, int *idx, int length);
void quickSort(int *s, int *b, int l, int r);
void quickSort(float *s, int l, int r);//单纯快速排序