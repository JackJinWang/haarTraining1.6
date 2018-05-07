#pragma once
#include"basicStruct.h"
#include"MyMat.h"
#include <cassert>
#include <cstring>
#include <cstdio>

#define CV_HAAR_FEATURE_MAX      3
#define CV_HAAR_FEATURE_DESC_MAX 20
#define CV_DEFAULT(val) = val

typedef struct CvTHaarFeature
{
	char desc[CV_HAAR_FEATURE_DESC_MAX];
	int  tilted;
	struct
	{
		MyRect r;
		float weight;
	} rect[CV_HAAR_FEATURE_MAX];
} CvTHaarFeature;

typedef struct CvFastHaarFeature
{
	int tilted;
	struct
	{
		int p0, p1, p2, p3;
		float weight;
	} rect[CV_HAAR_FEATURE_MAX];
} CvFastHaarFeature;

typedef struct CvIntHaarFeatures
{
	MySize winsize;
	int count;
	CvTHaarFeature *feature;
	CvFastHaarFeature *fastfeature;
} CvIntHaarFeatures;

/* haar特征记录*/
inline CvTHaarFeature cvHaarFeature(const char* desc,
	int x0, int y0, int w0, int h0, float wt0,
	int x1, int y1, int w1, int h1, float wt1,
	int x2 CV_DEFAULT(0), int y2 CV_DEFAULT(0),
	int w2 CV_DEFAULT(0), int h2 CV_DEFAULT(0),
	float wt2 CV_DEFAULT(0.0F))
{
	CvTHaarFeature hf;

	assert(CV_HAAR_FEATURE_MAX >= 3);
	assert(strlen(desc) < CV_HAAR_FEATURE_DESC_MAX);

	strcpy(&(hf.desc[0]), desc);
	hf.tilted = (hf.desc[0] == 't');

	hf.rect[0].r.x = x0;
	hf.rect[0].r.y = y0;
	hf.rect[0].r.width = w0;
	hf.rect[0].r.height = h0;
	hf.rect[0].weight = wt0;

	hf.rect[1].r.x = x1;
	hf.rect[1].r.y = y1;
	hf.rect[1].r.width = w1;
	hf.rect[1].r.height = h1;
	hf.rect[1].weight = wt1;

	hf.rect[2].r.x = x2;
	hf.rect[2].r.y = y2;
	hf.rect[2].r.width = w2;
	hf.rect[2].r.height = h2;
	hf.rect[2].weight = wt2;

	return hf;
}
/*
*
* haar特征转换函数
*
*/
void icvConvertToFastHaarFeature(CvTHaarFeature* haarFeature,
	CvFastHaarFeature* fastHaarFeature,
	int size, int step);

/* Prepared for training samples */
typedef struct CvHaarTrainingData
{
	MySize winsize;     /* training image size */
	int    maxnum;      /* maximum number of samples */
	MyMat  sum;         /* sum images (each row represents image) */
	MyMat  tilted;      /* tilted sum images (each row represents image) */
	MyMat  normfactor;  /* normalization factor */
	MyMat  cls;         /* classes. 1.0 - object, 0.0 - background */
	MyMat  weights;     /* weights */

	MyMat* valcache;    /* precalculated feature values (CV_32FC1) */
	MyMat* idxcache;    /* presorted indices (CV_IDX_MAT_TYPE) */
} CvHaarTrainigData;

/*
*
* haar 训练主要过程
*
*/
void myHaarTraining(const char* dirname,
	const char* posfilename,
	const char* bgfilename,
	const char* featuredir,
	int npos, int nneg, int nstages,
	int numprecalculated,
	int numsplits,
	float minhitrate, float maxfalsealarm,
	float weightfraction,
	int mode, int symmetric,
	int equalweights,
	int winwidth, int winheight,
	int boosttype, int stumperror,
	int maxtreesplits, int minpos, bool bg_vecfile = false, bool pos_vecfile = false);