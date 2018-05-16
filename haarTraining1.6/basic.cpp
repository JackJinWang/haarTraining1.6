#pragma once
#include"basic.h"
#include<io.h>
#include<time.h>
int *getRand(int *result, int low, int high,int number)
{
	srand((unsigned)time(NULL));
	int allnumber = high - low + 1;
	int i,t = 0;
	int *markrand = new int[allnumber];
	memset(markrand,0,sizeof(int)*allnumber);
	while (t<number) {
		i = rand() % (high - low + 1) + low;
		if (markrand[i] == 0) {
			markrand[i] = 1;
			result[t] = i;
			t++;
		}
	}
	delete []markrand;
	return result;
}
void getFiles(string path, vector<string>& files)
{
	//文件句柄    
	long   hFile = 0;
	//文件信息    
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之    
			//如果不是,加入列表    
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
