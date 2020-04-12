#include <iostream>
#include "globalVariables.h"
using namespace std;

const char* inPath = "C:\\Users\\s.z.zheng\\OneDrive\\�ĵ�\\CUC�γ� - OD\\������ѧ�ڿγ� - OD\\����ѹ��ԭ����Ӧ��A - OD\\��ҵ\\��ҵ3��RGB�ļ��ĸ��ʷֲ�\\down.rgb";	// ԭʼͼ��·�����ļ�
const char* outPathR = "C:\\Users\\s.z.zheng\\OneDrive\\�ĵ�\\CUC�γ� - OD\\������ѧ�ڿγ� - OD\\����ѹ��ԭ����Ӧ��A - OD\\��ҵ\\��ҵ3��RGB�ļ��ĸ��ʷֲ�\\down_RStats.csv";	// R����ͳ�ƽ��
const char* outPathG = "C:\\Users\\s.z.zheng\\OneDrive\\�ĵ�\\CUC�γ� - OD\\������ѧ�ڿγ� - OD\\����ѹ��ԭ����Ӧ��A - OD\\��ҵ\\��ҵ3��RGB�ļ��ĸ��ʷֲ�\\down_GStats.csv";	// G����ͳ�ƽ��
const char* outPathB = "C:\\Users\\s.z.zheng\\OneDrive\\�ĵ�\\CUC�γ� - OD\\������ѧ�ڿγ� - OD\\����ѹ��ԭ����Ӧ��A - OD\\��ҵ\\��ҵ3��RGB�ļ��ĸ��ʷֲ�\\down_BStats.csv";	// B����ͳ�ƽ��
int w = 256;	// ͼ���
int h = 256;	// ͼ���

void Pmf(unsigned char* buffer, int size, FILE* outFile)
{
	int count[256] = { 0 };	// ������
	double freq[256] = { 0 };	// Ƶ��
	double entropy = 0;	// �÷�������

	// ͳ��ĳһ����
	for (int i = 0; i < size / 3; i++)
	{
		int index = (int)buffer[i];
		count[index]++;
	}

	// ����÷�����Ƶ�ʣ�������÷���
	for (int i = 0; i < 256; i++)
	{
		freq[i] = (double)count[i] / (w * h);	//���ӷ�ĸ��Ϊint�ͣ���������ת������֤���Ϊdouble����
		if (freq[i] != 0)
		{
			entropy += (-freq[i]) * log(freq[i]) / log(2);
		}
	}

	fprintf(outFile, "Symbol,Frequency\n");
	for (int i = 0; i < 256; i++)
	{
		fprintf(outFile, "%-3d,%-8.2e\n", i, freq[i]);	// ������������ļ��У�csv�ļ��ԡ�,����Ϊ�ָ�����
	}
	fprintf(outFile, "%.4lf", entropy);
}