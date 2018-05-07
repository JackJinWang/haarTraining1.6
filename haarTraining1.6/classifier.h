#pragma once
#include <cmath>
/*
*弱分类器结构体
*/
typedef struct MyStumpClassifier
{
	int compidx;

	float lerror; /* impurity of the right node */
	float rerror; /* impurity of the left  node */
	float error; /* 总的错误率*/
	float threshold;
	float left;
	float right;
} MyStumpClassifier;

