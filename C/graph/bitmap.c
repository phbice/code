#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

#pragma pack(2) //两字节对齐

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef signed   int   LONG;

typedef struct tagBITMAPFILEHEADER
{ 
	WORD    bfType;       //2Bytes，必须为"BM"，即0x4D42 才是Windows位图文件
	DWORD   bfSize;       //4Bytes，整个BMP文件的大小
	WORD    bfReserved1;  //2Bytes，保留，为0
	WORD    bfReserved2;  //2Bytes，保留，为0
	DWORD   bfOffBits;    //4Bytes，文件起始位置到图像像素数据的字节偏移量
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD  biSize;  //4Bytes，INFOHEADER结构体大小，存在其他版本INFOHEADER，用作区分
	LONG   biWidth;   //4Bytes，图像宽度（以像素为单位）
	LONG   biHeight;  //4Bytes，图像高度，正值：图像存储顺序为Bottom2Top. 负值：Top2Bottom
	WORD   biPlanes;  //2Bytes，图像数据平面，BMP存储RGB数据，因此总为1
	WORD   biBitCount;      //2Bytes，图像像素位数，可取1, 4, 8, 16, 24, 32
	DWORD  biCompression;   //4Bytes，0：不压缩，1：RLE8，2：RLE4
	DWORD  biSizeImage;     //4Bytes，4字节对齐的图像数据大小
	LONG   biXPelsPerMeter; //4 Bytes，用象素/米表示的水平分辨率
	LONG   biYPelsPerMeter; //4 Bytes，用象素/米表示的垂直分辨率
	DWORD  biClrUsed;       //4 Bytes，实际使用的调色板索引数，0：使用所有的调色板索引
	DWORD  biClrImportant;  //4 Bytes，重要的调色板索引数，0：所有的调色板索引都重要
}BITMAPINFOHEADER;

typedef struct _tagRGBQUAD
{
	BYTE  rgbBlue;      //指定蓝色强度
	BYTE  rgbGreen;     //指定绿色强度
	BYTE  rgbRed;       //指定红色强度
	BYTE  rgbReserved;  //保留，设置为0
}RGBQUAD;

#define TOTAL_HEADER_SIZE (14 + 40 + 256*4)

void create_bmp(char filename[], unsigned char * data, int width, int height)
{
	FILE  * fp;
	int i,j;
	unsigned int iBitPerLine = (width + 3) & ~(0x03);
	unsigned char * line = (unsigned char *)malloc(iBitPerLine);
	memset(line, 0, iBitPerLine);

	BITMAPFILEHEADER * pFileHeader = (BITMAPFILEHEADER *)malloc(sizeof(BITMAPFILEHEADER));
	BITMAPINFOHEADER * pInfoHeader = (BITMAPINFOHEADER *)malloc(sizeof(BITMAPINFOHEADER));
	RGBQUAD  palette;

	pFileHeader->bfType = 0x4D42; //'BM'
	pFileHeader->bfSize = TOTAL_HEADER_SIZE + iBitPerLine * height; //文件总大小
	pFileHeader->bfReserved1 = 0;
	pFileHeader->bfReserved2 = 0;
	pFileHeader->bfOffBits   = TOTAL_HEADER_SIZE; //文件起始位置到像素数据起始位置的偏移量
	
	pInfoHeader->biSize   = sizeof(BITMAPINFOHEADER);
	pInfoHeader->biWidth  = width;
	pInfoHeader->biHeight = height;
	pInfoHeader->biPlanes = 1;
	pInfoHeader->biBitCount = 8;	//每像素八位，256阶灰度图
	pInfoHeader->biCompression = 0; //不压缩
	pInfoHeader->biSizeImage    = iBitPerLine * height;
	pInfoHeader->biXPelsPerMeter = 0;
	pInfoHeader->biYPelsPerMeter = 0;
	pInfoHeader->biClrUsed      = 0;     //使用所有调色板
	pInfoHeader->biClrImportant = 0;
	
	fp = fopen(filename, "wb");
	fwrite(pFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(pInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	for (i = 0; i < 256; i++)
	{
		palette = (RGBQUAD) { i, i, i, 0 };
		fwrite(&palette, sizeof(RGBQUAD), 1, fp);
	}
	
	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j<width; j++)
		{
			line[j] = data[i*height + j];
		}
		fwrite(line, iBitPerLine, 1, fp);
	}

	fclose(fp);
	return;
}

/*
int set_bmp_pix(FILE * bmp,int x, int y, int gray)
{
	int iBitPerLine;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	rewind(bmp);
	fread(&fileHeader, sizeof(fileHeader), 1, bmp);
	fread(&infoHeader, sizeof(infoHeader), 1, bmp);

	iBitPerLine = (infoHeader.biWidth + 3) & ~(0x03);
}
*/