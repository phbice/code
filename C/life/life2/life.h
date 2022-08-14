#ifndef _LIFE_H_
#define _LIFE_H_

#define WIDTH			200
#define HEIGHT			100

#define LIVE			1
#define DIE				0
#define LIFE_CHANGED    1
#define LIFE_UNCHANGED  0
#define INIT_TIME		1000
#define UPDATE_PERIOD	100

#define CELL_SIZE		5

#define TIMER_INIT_LIFE		1
#define TIMER_UPDATE_LIFE	2

void generate(char parent[][WIDTH], char child[][WIDTH], char changed[][WIDTH]);
int CountNeighbors(char canvas[][WIDTH], int i, int j);

#endif