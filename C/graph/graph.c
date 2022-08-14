#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void create_bmp(char filename[], unsigned char * data, int width, int height);

int line(char * buffer, int width, int height, int x0, int y0, int x1, int y1, int thickness)
{
	int vs[2] = { x1 - x0, y1 - y0 };
	double vn[2] = { (y0 - y1)*thickness / sqrt(vs[0] * vs[0] + vs[1] * vs[1]), (x1 - x0)*thickness / sqrt(vs[0] * vs[0] + vs[1] * vs[1]) };

}