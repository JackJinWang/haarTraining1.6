/*************************************************
Date:2018-02-05
Description:ͼ��ṹ
**************************************************/
#pragma once
#include <cstdio>
#include <cstdlib>
#include "basic.h"

/****************************************************************************************\
*                                  Matrix type (MyMat)                                   *
\****************************************************************************************/
typedef struct MyMat
{
	int data_type;	    /*��������*/
	int step;           /*ÿ�����ݵĳ���*/
	int channel_type;   /*����ͨ����*/
	union               /*����*/
	{
		uchar* ptr;
		short* s;
		int* i;
		float* fl;
		double* db;
	} data;

#ifdef __cplusplus
	union
	{
		int rows;
		int height;
	};
	//ÿ��Ԫ�ظ���
	union
	{
		int cols;
		int width;
	};
#else
	int rows;
	int cols;
#endif
}MyMat;

inline MyMat* createMyMat(int rows, int cols, int channel_type, int data_type)
{
	MyMat * temp = (MyMat*)malloc(sizeof(MyMat));
	temp->data_type = data_type;
	temp->channel_type = channel_type;
	temp->cols = cols;
	temp->rows = rows;
	switch (temp->data_type)
	{
	case UCHAR_TYPE:
		temp->step = temp->cols * sizeof(uchar);
		temp->data.ptr = (uchar*)malloc(sizeof(uchar) * rows * cols * channel_type);
		break;
	case SHORT_TYPE:
		temp->step = temp->cols * sizeof(short);
		temp->data.s = (short*)malloc(sizeof(short) * rows * cols * channel_type);
		break;
	case INT_TYPE:
		temp->step = temp->cols * sizeof(int);
		temp->data.i = (int*)malloc(sizeof(int) * rows * cols * channel_type);
		break;
	case FLOAT_TYPE:
		temp->step = temp->cols * sizeof(float);
		temp->data.fl = (float*)malloc(sizeof(float) * rows * cols * channel_type);
		break;
	case DOUBLE_TYPE:
		temp->step = temp->cols * sizeof(double);
		temp->data.db = (double*)malloc(sizeof(double) * rows * cols * channel_type);
		break;
	default:
		break;
	}
	return temp;
}

inline MyMat myMat(int rows, int cols, int channel_type, int data_type, void* ptr)
{
	MyMat  temp;
	temp.data_type = data_type;
	temp.channel_type = channel_type;
	temp.cols = cols;
	temp.rows = rows;
	if (ptr != NULL)
		switch (temp.data_type)
		{
		case UCHAR_TYPE:
			temp.step = temp.cols * sizeof(uchar);
			temp.data.ptr = (uchar*)ptr;
			break;
		case SHORT_TYPE:
			temp.step = temp.cols * sizeof(short);
			temp.data.s = (short*)ptr;
			break;
		case INT_TYPE:
			temp.step = temp.cols * sizeof(int);
			temp.data.i = (int*)ptr;
			break;
		case FLOAT_TYPE:
			temp.step = temp.cols * sizeof(float);
			temp.data.fl = (float*)ptr;
			break;
		case DOUBLE_TYPE:
			temp.step = temp.cols * sizeof(double);
			temp.data.db = (double*)ptr;
			break;
		default:
			break;
		}
	else
		switch (temp.data_type)
		{
		case UCHAR_TYPE:
			temp.step = temp.cols * sizeof(uchar);
			//	temp.data.ptr = (uchar*)malloc(sizeof(uchar) * rows * cols * channel_type);
			temp.data.ptr = NULL;
			break;
		case SHORT_TYPE:
			temp.step = temp.cols * sizeof(short);
			//	temp.data.ptr = (uchar*)malloc(sizeof(uchar) * rows * cols * channel_type);
			temp.data.s = NULL;
			break;
		case INT_TYPE:
			temp.step = temp.cols * sizeof(int);
			//	temp.data.i = (int*)malloc(sizeof(int) * rows * cols * channel_type);
			temp.data.i = NULL;
			break;
		case FLOAT_TYPE:
			temp.step = temp.cols * sizeof(float);
			//	temp.data.fl = (float*)malloc(sizeof(float) * rows * cols * channel_type);
			temp.data.fl = NULL;
			break;
		case DOUBLE_TYPE:
			temp.step = temp.cols * sizeof(double);
			//	temp.data.db = (double*)malloc(sizeof(double) * rows * cols * channel_type);
			temp.data.db = NULL;
			break;
		default:
			break;
		}
	return temp;
}

inline void releaseMyMat(MyMat *mat)
{
	if (mat != NULL)
	{
		switch (mat->data_type)
		{
		case INT_TYPE:
			if (mat->data.i != NULL)
			{
				free(mat->data.i);
			}
			break;
		case SHORT_TYPE:
			if (mat->data.s != NULL)
			{
				free(mat->data.s);
			}
			break;
		case UCHAR_TYPE:
			if (mat->data.ptr != NULL)
			{
				free(mat->data.ptr);
			}
			break;
		case FLOAT_TYPE:
			if (mat->data.fl != NULL)
			{
				free(mat->data.fl);
			}
			break;
		case DOUBLE_TYPE:
			if (mat->data.db != NULL)
			{
				free(mat->data.db);
			}
			break;
		default:
			break;
		}
		free(mat);
	}
}
inline int getElemSize(MyMat idx)
{
	int temp;
	if (idx.data_type == UCHAR_TYPE)
		temp = sizeof(uchar);
	else if (idx.data_type == INT_TYPE)
		temp = sizeof(int);
	else if (idx.data_type == FLOAT_TYPE)
		temp = sizeof(float);
	else if (idx.data_type == DOUBLE_TYPE)
		temp = sizeof(double);
	return temp;
}
