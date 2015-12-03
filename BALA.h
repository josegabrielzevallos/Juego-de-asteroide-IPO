#ifndef BALA_H
#define BALA_H

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>


void gotoxy(int x, int y);
void color(int X);

class BALA{
private:
	int x,y;
public:
	BALA(int _x, int _y): x(_x),y(_y){}
	int X(){ return x;}
	int Y(){ return y;}
	void mover();
	bool fuera();

};
#endif // BALA_H
