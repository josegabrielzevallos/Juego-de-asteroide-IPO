#ifndef CORAZONES_H
#define CORAZONES_H
#include "ASTEROIDE.h"

class CORAZONES : public AST
{
public:
    CORAZONES(int _x, int _y) : AST(x,y) {}
    void pintar();
    void mover();
    void choque(class NAVE &N);

};

#endif // CORAZONES_H
