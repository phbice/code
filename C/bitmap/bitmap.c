#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	LONG   biHeight;  //4Bytes，图像高度，+：图像存储顺序为Bottom2Top，-：Top2Bottom
	WORD   biPlanes;  //2Bytes，图像数据平面，BMP存储RGB数据，因此总为1
	WORD   biBitCount;      //2Bytes，图像像素位数
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

void create_bitmap(char filename[], unsigned char data[],int width,int height)
{
	FILE  * fp;
	int i,j;
	unsigned int iBitPerLine = ((width + 31)>>5)<<2;
	unsigned char * line = (unsigned char *)malloc(iBitPerLine);
	memset(line, 0, iBitPerLine);

	BITMAPFILEHEADER * pFileHeader = (BITMAPFILEHEADER *)malloc(sizeof(BITMAPFILEHEADER));
	BITMAPINFOHEADER * pInfoHeader = (BITMAPINFOHEADER *)malloc(sizeof(BITMAPINFOHEADER));
	RGBQUAD * palette = (RGBQUAD *)malloc(sizeof(RGBQUAD)*2);

	pFileHeader->bfType = 0x4D42; //'BM'
	pFileHeader->bfSize = (14 + 40 + 8) + iBitPerLine * height;
	pFileHeader->bfReserved1 = 0;
	pFileHeader->bfReserved2 = 0;
	pFileHeader->bfOffBits   = (14 + 40 + 8);
	
	pInfoHeader->biSize   = sizeof(BITMAPINFOHEADER);
	pInfoHeader->biWidth  = width;
	pInfoHeader->biHeight = height;
	pInfoHeader->biPlanes = 1;
	pInfoHeader->biBitCount = 1;
	pInfoHeader->biCompression = 0; //不压缩
	pInfoHeader->biSizeImage    = iBitPerLine * height;
	pInfoHeader->biXPelsPerMeter = 0;
	pInfoHeader->biYPelsPerMeter = 0;
	pInfoHeader->biClrUsed      = 2;     //使用2个调色板
	pInfoHeader->biClrImportant = 2;
	
	palette[0] = (RGBQUAD){255, 255, 255, 0};
	palette[1] = (RGBQUAD){  0,   0,   0, 0};
	
	fp = fopen(filename, "wb");
	fwrite(pFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(pInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	fwrite(palette, 2*sizeof(RGBQUAD), 1, fp);
	
	for (i=height-1; i>=0; i--)
	{
		for (j=0; j<width; j++)
		{
			switch (data[i*height + j])
			{
			case 0:
				line[j>>3] &= ~(0x80>>(j&7));
				break;
			case 1:
				line[j>>3] |= (0x80>>(j&7));
			}
		}
		fwrite(line, iBitPerLine, 1, fp);
	}
	
	fclose(fp);
	
	return;
}

int main(int argc, char ** argv)
{
	char bitmap[32*32] = {1,1,1,1,0};
	
	bitmap[9*32 + 9] = 1;
	
	create_bitmap("test.bmp", bitmap, 32, 32);
	
	return 0;
}