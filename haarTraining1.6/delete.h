/*
*
* Î´ÍÑÀëopencvµÄº¯Êý£¬×îÖÕ±ØÐëÉ¾³ý
*
*/
#pragma once
#include"basic.h"
#include "MyMat.h"
#include <opencv2\highgui\highgui.hpp>
using namespace cv;
inline MyMat* transMat(MyMat * result,char *picName)
{
	Mat img = imread(picName, CV_LOAD_IMAGE_GRAYSCALE);
	int height = img.size().height;
	int width = img.size().width;
	if(img.empty())
	{
		return nullptr;
	}

	uchar *temp;
	for (int i = 0; i < height; i++)
	{
		// get the pointer to the ith row
		temp = img.ptr<uchar>(i);
		// operates on each pixel
		for (int j = 0; j < width; j++)
		{
			// assigns new value
			result->data.ptr[i*width+j] = temp[j];
		}
	}
	return result;
}

