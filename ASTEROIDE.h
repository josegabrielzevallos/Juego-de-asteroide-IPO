#ifndef ASTEROIDE_H
#define ASTEROIDE_H


#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include "NAVE.h"



void gotoxy(int x, int y);
void color(int X);

class AST{
protected:
	int x,y;
public:
	AST(int _x, int _y):x(_x),y(_y){}
	void pintar();
	void mover();
	void choque(class NAVE &N);
	int X(){ return x;}
	int Y(){ return y;}

};
#endif // ASTEROIDE_H
