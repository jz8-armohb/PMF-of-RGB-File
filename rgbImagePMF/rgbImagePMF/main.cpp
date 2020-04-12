#include <iostream>
#include "globalVariables.h"
using namespace std;

int main()
{
	FILE* img;
	FILE* outR;	// 存储R分量数据的文件
	FILE* outG;	// 存储G分量数据的文件
	FILE* outB;	// 存储B分量数据的文件
	int imgSize;	// 图像总字节数

	// 打开文件
	if (fopen_s(&img, inPath, "rb") == 0)
	{
		cout << "Successfull opened the original image." << endl;
	}
	else
	{
		cout << "Failed to open the original image." << endl;
	}
	fopen_s(&outR, outPathR, "w");
	fopen_s(&outG, outPathG, "w");
	fopen_s(&outB, outPathB, "w");

	// 计算图片总字节数
	fseek(img, 0L, SEEK_END);	// 使文件指针指向文件末尾
	imgSize = ftell(img);	// 文件总字节数
	rewind(img);	// 使文件指针再回到文件起始（若不回到起始，无法将img中的数据读入到缓冲区中）
	cout << "The space that original image accounts for: " << imgSize << " Bytes = " << imgSize / 1024 << " kB" << endl;

	// 建立缓冲区
	unsigned char* imgBuffer = new unsigned char[imgSize];	// 图像缓冲区
	unsigned char* rBuffer = new unsigned char[imgSize / 3];	// R分量缓冲区
	unsigned char* gBuffer = new unsigned char[imgSize / 3];	// G分量缓冲区
	unsigned char* bBuffer = new unsigned char[imgSize / 3];	// B分量缓冲区

	// 将数据读入缓冲区
	fread(imgBuffer, sizeof(unsigned char), imgSize, img);	// 先将全部像素的RGB三个分量读入图像缓冲区
	for (int i = 0; i < imgSize / 3; i++)
	{
		// 再分别将图像缓冲区的内容对应地分配给R、G、B缓冲区（注意：img中存储的顺序为G、B、R）
		bBuffer[i] = imgBuffer[3 * i];
		gBuffer[i] = imgBuffer[3 * i + 1];
		rBuffer[i] = imgBuffer[3 * i + 2];
	}

	// 分别统计R、G、B分量的概率分布
	Pmf(rBuffer, imgSize, outR);
	Pmf(gBuffer, imgSize, outG);
	Pmf(bBuffer, imgSize, outB);

	// 关闭文件
	fclose(img);
	fclose(outR);
	fclose(outG);
	fclose(outB);
	// 释放内存
	delete[]imgBuffer;
	delete[]rBuffer;
	delete[]gBuffer;
	delete[]bBuffer;
}