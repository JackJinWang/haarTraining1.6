#pragma once
#include"MyMat.h"
void GetGrayIntegralImage(unsigned char *Src, int *Integral, int Width, int Height, int Stride); //������ͼ
void GetGraySqImage(unsigned char *Src, int *Integral, int Width, int Height, int Stride); //���ƽ������ͼ
void bubbleSort(int* pData, int *idx, int length);
void quickSort(int *s, int *b, int l, int r);
void quickSort(float *s, int l, int r);//������������