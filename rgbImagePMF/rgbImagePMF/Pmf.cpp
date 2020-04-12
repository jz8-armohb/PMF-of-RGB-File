#include <iostream>
#include "globalVariables.h"
using namespace std;

const char* inPath = "C:\\Users\\s.z.zheng\\OneDrive\\文档\\CUC课程 - OD\\大三下学期课程 - OD\\数据压缩原理与应用A - OD\\作业\\作业3：RGB文件的概率分布\\down.rgb";	// 原始图像路径及文件
const char* outPathR = "C:\\Users\\s.z.zheng\\OneDrive\\文档\\CUC课程 - OD\\大三下学期课程 - OD\\数据压缩原理与应用A - OD\\作业\\作业3：RGB文件的概率分布\\down_RStats.csv";	// R分量统计结果
const char* outPathG = "C:\\Users\\s.z.zheng\\OneDrive\\文档\\CUC课程 - OD\\大三下学期课程 - OD\\数据压缩原理与应用A - OD\\作业\\作业3：RGB文件的概率分布\\down_GStats.csv";	// G分量统计结果
const char* outPathB = "C:\\Users\\s.z.zheng\\OneDrive\\文档\\CUC课程 - OD\\大三下学期课程 - OD\\数据压缩原理与应用A - OD\\作业\\作业3：RGB文件的概率分布\\down_BStats.csv";	// B分量统计结果
int w = 256;	// 图像宽
int h = 256;	// 图像高

void Pmf(unsigned char* buffer, int size, FILE* outFile)
{
	int count[256] = { 0 };	// 计数器
	double freq[256] = { 0 };	// 频率
	double entropy = 0;	// 该分量的熵

	// 统计某一分量
	for (int i = 0; i < size / 3; i++)
	{
		int index = (int)buffer[i];
		count[index]++;
	}

	// 计算该分量的频率，并输出该分量
	for (int i = 0; i < 256; i++)
	{
		freq[i] = (double)count[i] / (w * h);	//分子分母都为int型，进行类型转换，保证结果为double类型
		if (freq[i] != 0)
		{
			entropy += (-freq[i]) * log(freq[i]) / log(2);
		}
	}

	fprintf(outFile, "Symbol,Frequency\n");
	for (int i = 0; i < 256; i++)
	{
		fprintf(outFile, "%-3d,%-8.2e\n", i, freq[i]);	// 将数据输出到文件中（csv文件以“,”作为分隔符）
	}
	fprintf(outFile, "%.4lf", entropy);
}