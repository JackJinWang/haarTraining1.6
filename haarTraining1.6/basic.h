/*************************************************
Date:2018-02-05
Description:��������
**************************************************/
#pragma once
#include<iostream>

using namespace std;

#define THREE_CHANNEL 3 //��ͨ��
#define ONE_CHANNEL 1  //һͨ��

#define INT_TYPE 1      //��������
#define FLOAT_TYPE 2
#define UCHAR_TYPE 3
#define DOUBLE_TYPE 4
#define SHORT_TYPE 5
#define SAVE_FEATURE_FILE 0
#define SAVE_FEATURE_MEM 1
#ifndef PATH_MAX
#define PATH_MAX 512
#endif /* PATH_MAX */

#define _MY_END_ exit:;
#define __MY_EXIT__        goto exit;
#ifndef MIN
#  define MIN(a,b)  ((a) > (b) ? (b) : (a))
#endif

#ifndef MAX
#  define MAX(a,b)  ((a) < (b) ? (b) : (a))
#endif
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef int    sum_type;
typedef double sqsum_type;
typedef short  idx_type;
typedef void MyArr;
/*
* ��ȡһ����Χ�ڲ��ظ��������
*/
int *getRand(int *result, int low, int high, int number);

