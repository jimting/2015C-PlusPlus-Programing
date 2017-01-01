#ifndef MAIN_H
#define MAIN_H
struct line;
struct line{
	int to;
	int distance;
	struct line *next;
};
#endif