#pragma once
#include <cmath>
/*
*���������ṹ��
*/
typedef struct MyStumpClassifier
{
	int compidx;

	float lerror; /* impurity of the right node */
	float rerror; /* impurity of the left  node */
	float error; /* �ܵĴ�����*/
	float threshold;
	float left;
	float right;
} MyStumpClassifier;

