#ifndef NAVE_H
#define NAVE_H
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>


#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y);
void color(int X);

class NAVE{
private:
	int x,y;
	int corazones;
	int vidas;
public:
	NAVE(int _x, int _y, int _corazones, int _vidas):x(_x),y(_y),corazones(_corazones),vidas(_vidas){}
	int X(){return x; }
	int Y(){return y; }
	int VID(){return vidas;}
	int CO(){return corazones;}
	void COR(){corazones--;}
	void CORZ(){corazones++;}
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
	void morir();
};

#endif // NAVE_H
