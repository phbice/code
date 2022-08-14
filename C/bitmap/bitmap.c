#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(2) //���ֽڶ���

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef signed   int   LONG;

typedef struct tagBITMAPFILEHEADER
{ 
	WORD    bfType;       //2Bytes������Ϊ"BM"����0x4D42 ����Windowsλͼ�ļ�
	DWORD   bfSize;       //4Bytes������BMP�ļ��Ĵ�С
	WORD    bfReserved1;  //2Bytes��������Ϊ0
	WORD    bfReserved2;  //2Bytes��������Ϊ0
	DWORD   bfOffBits;    //4Bytes���ļ���ʼλ�õ�ͼ���������ݵ��ֽ�ƫ����
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD  biSize;  //4Bytes��INFOHEADER�ṹ���С�����������汾INFOHEADER����������
	LONG   biWidth;   //4Bytes��ͼ���ȣ�������Ϊ��λ��
	LONG   biHeight;  //4Bytes��ͼ��߶ȣ�+��ͼ��洢˳��ΪBottom2Top��-��Top2Bottom
	WORD   biPlanes;  //2Bytes��ͼ������ƽ�棬BMP�洢RGB���ݣ������Ϊ1
	WORD   biBitCount;      //2Bytes��ͼ������λ��
	DWORD  biCompression;   //4Bytes��0����ѹ����1��RLE8��2��RLE4
	DWORD  biSizeImage;     //4Bytes��4�ֽڶ����ͼ�����ݴ�С
	LONG   biXPelsPerMeter; //4 Bytes��������/�ױ�ʾ��ˮƽ�ֱ���
	LONG   biYPelsPerMeter; //4 Bytes��������/�ױ�ʾ�Ĵ�ֱ�ֱ���
	DWORD  biClrUsed;       //4 Bytes��ʵ��ʹ�õĵ�ɫ����������0��ʹ�����еĵ�ɫ������
	DWORD  biClrImportant;  //4 Bytes����Ҫ�ĵ�ɫ����������0�����еĵ�ɫ����������Ҫ
}BITMAPINFOHEADER;

typedef struct _tagRGBQUAD
{
	BYTE  rgbBlue;      //ָ����ɫǿ��
	BYTE  rgbGreen;     //ָ����ɫǿ��
	BYTE  rgbRed;       //ָ����ɫǿ��
	BYTE  rgbReserved;  //����������Ϊ0
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
	pInfoHeader->biCompression = 0; //��ѹ��
	pInfoHeader->biSizeImage    = iBitPerLine * height;
	pInfoHeader->biXPelsPerMeter = 0;
	pInfoHeader->biYPelsPerMeter = 0;
	pInfoHeader->biClrUsed      = 2;     //ʹ��2����ɫ��
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