#pragma once
extern const char* inPath;	// ԭʼͼ��·�����ļ�
extern const char* outPathR;	// R����ͳ�ƽ��
extern const char* outPathG;	// G����ͳ�ƽ��
extern const char* outPathB;	// B����ͳ�ƽ��
extern int w;	// ͼ���
extern int h;	// ͼ���
void Pmf(unsigned char* buffer,int size, FILE* outFile);