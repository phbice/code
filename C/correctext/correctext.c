/*
check format of the file according to the file header
and correct filename extension (only support .webp format)
 PHB 2018/2/20 15:21
*/

#include <stdio.h>
#include <string.h>

#define FILE_LIST "filelist2.txt"
#define RENAME_LIST "renamelist.bat"

typedef struct riffHeader
{
	char szRiffID[4];  // 'R','I','F','F'
	int  dwRiffSize;
	char szRiffFormat[4]; // 'W','E','B','P'
}RIFFHEADER;

int findExtension(char *str);
int correctFilenameExtension(char * filename);

int main(void)
{
	char filename[260];
	char newname[260];
	FILE * fpList = fopen(FILE_LIST,"r");
	FILE * fpRenameList = fopen(RENAME_LIST, "w");
	while (fgets(filename, 260, fpList) != NULL)
	{
		filename[strlen(filename)-1] = 0;
		strcpy(newname, filename);
		if (correctFilenameExtension(newname) == 1)
		{
			fprintf(fpRenameList, "rename %s %s\n", filename, newname);
		}
	}
	fclose(fpList);
	fclose(fpRenameList);
	return 0;
}

int findExtension(char *str)
{
	int pos = strlen(str);
	int i;
	for (i=0; str[i]!=0; i++)
	{
		if (str[i] == '.')
			pos = i;
	}
	return pos;
}

int correctFilenameExtension(char * filename)
{
	RIFFHEADER header;
	FILE * fp = fopen(filename, "rb");
	fread(&header, sizeof(header), 1, fp);
	fclose(fp);
	
	if ( strncmp(header.szRiffID,     "RIFF", 4)==0 && 
	     strncmp(header.szRiffFormat, "WEBP", 4)==0)
	{
		strcpy(&filename[findExtension(filename)], ".webp");
		return 1;
	}
	return 0;
}