#pragma once
#include"myIntergal.h"
#include"basic.h"
#include"basicStruct.h"
/****************************************************************************************\
*                                �������ͼ                                              *
\****************************************************************************************/

/*
*������ͼ
*/
void GetGrayIntegralImage(unsigned char *Src, int *Integral, int Width, int Height, int Stride)
{
	int *ColSum = (int *)calloc(Width, sizeof(int));        //    �õ�calloc�������Զ��ڴ���0
	memset(Integral, 0, (Width + 1) * sizeof(int));
	for (int Y = 0; Y < Height; Y++)
	{
		unsigned char *LinePS = Src + Y * Stride;
		int *LinePL = Integral + Y * (Width + 1) + 1;
		int *LinePD = Integral + (Y + 1) * (Width + 1) + 1;
		LinePD[-1] = 0;
		for (int X = 0; X < Width; X++)
		{
			ColSum[X] += LinePS[X];
			LinePD[X] = LinePD[X - 1] + ColSum[X];
		}
	}
	free(ColSum);
}
//���ƽ������ͼ
void GetGraySqImage(unsigned char *Src, int *Integral, int Width, int Height, int Stride)
{
	uchar *copy = new uchar[Width*Height];
	for (int i = 0;i < Width;i++)
	{
		for (int j = 0;j < Height;j++)
		{
			copy[j + i * Width] = Src[j + i * Width] * Src[j + i * Width];
		}
	}
	GetGrayIntegralImage(copy,Integral,Width,Height,Stride);
	delete []copy;
}
/*
*ð������
*idx ��������
*data_array ��������
*/
void bubbleSort(int* pData, int *idx, int length)
{
	int temp, idxt;
	for (int i = 0;i != length;++i)
	{
		for (int j = 0; j != length; ++j)
		{
			if (pData[i] < pData[j])
			{
				temp = pData[i];
				idxt = idx[i];
				pData[i] = pData[j];
				idx[i] = idx[j];
				pData[j] = temp;
				idx[j] = idxt;
			}
		}
	}
}
/*
*��������
*b ��������
*s ��������
*/
void quickSort(int *s, int *b, int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l], y = b[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
			{
				s[i] = s[j];
				b[i] = b[j];
				i++;
			}

			while (i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
			{
				s[j] = s[i];
				b[j] = b[i];
				j--;
			}

		}
		s[i] = x;
		b[i] = y;
		quickSort(s, b, l, i - 1); // �ݹ����  
		quickSort(s, b, i + 1, r);
	}
}
/*
*��������
*b ��������
*/
void quickSort(float *s,int l, int r)
{
	if (l< r)
	{
		int i = l, j = r;float x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
			{
				s[i] = s[j];
				i++;
			}

			while (i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
			{
				s[j] = s[i];
				j--;
			}

		}
		s[i] = x;
		quickSort(s,  l, i - 1); // �ݹ����  
		quickSort(s,  i + 1, r);
	}
}