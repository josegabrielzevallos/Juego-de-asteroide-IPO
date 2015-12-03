#include<list>
#include<NAVE.h>
#include<BALA.h>

#include<CORAZONES.h>
using namespace std;

void color(int X)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}


void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon,&cci);


}

void pintar_limites(){
	for(int i = 2 ; i<78 ; i++){
		gotoxy(i,3); printf("%c",205);
		gotoxy(i,33); printf("%c",205);
	}

	for(int i = 4; i<33 ; i++){
		gotoxy(2,i); printf("%c",186);
		gotoxy(77,i); printf("%c",186);
	}

	gotoxy(2,3); printf("%c",201);
	gotoxy(2,33); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,33); printf("%c",188);
}

void borrarlimites()
{
    for(int i = 3 ; i<77 ; i++){
        for(int j = 5; j<33 ; j++)
        {
		gotoxy(i,j); printf(" ");
		gotoxy(i,j); printf(" ");
        }
    }

}

void creditos()
{
    gotoxy(75/2-9,29/2+3); printf("  Gracias por jugar :)");
    gotoxy(75/2-9,29/2+4); printf("Hecho por: Diego Cervantes");
    gotoxy(75/2-9,29/2+5); printf(" Jose Gabriel Zevallos");
}

int main(){

	OcultarCursor();
	pintar_limites();
	NAVE N(37,30,3,3);
	N.pintar();
	N.pintar_corazones();

    CORAZONES hp(rand()%75 + 3, rand()%5 + 4);

	list<AST*> A ;
	list<AST*>::iterator itA;
	for(int i = 0; i<5; i++){
		A.push_back(new AST(rand()%75 + 3, rand()%5 + 4));
	}

	list<BALA*> B;
	list<BALA*>::iterator it;

	bool game_over = false;
	int puntos = 0;
	while(!game_over){

		gotoxy(4,2); printf("Puntos %d", puntos);
		if(kbhit())
		{

			char tecla = getch();
			if(tecla == 'a')
			B.push_back(new BALA(N.X()+2 , N.Y()-1 ));
		}

		for(it = B.begin(); it != B.end(); it ++)
		{
			(*it)->mover();
			if((*it)->fuera()){
				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);


			}
		}

		for(itA = A.begin(); itA != A.end(); itA++){
			(*itA)->mover();
			(*itA)->choque(N);

		}

		for(itA = A.begin(); itA!=A.end(); itA++){
			for(it = B.begin(); it != B.end(); it++){
				if((*itA)->X() == (*it)->X() and ( (*itA)-> Y()+1 == (*it)->Y()  or ( (*itA)-> Y() == (*it)->Y() )) ){
					gotoxy((*it)->X(),(*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);

					A.push_back(new AST(rand()%74 + 3, 4 ));
					gotoxy((*itA)->X(),(*itA)->Y()); printf(" ");
					delete(*itA);
					itA = A.erase(itA);

					puntos+=5;

				}
			}

		}


        hp.mover();
        hp.choque(N);

		if(N.VID() == 0) game_over = true;
		if(puntos == 50)
        {
            game_over = true;
            borrarlimites();
            gotoxy(75/2-1,29/2+2); printf("GANASTE");
            creditos();
            Sleep(3000);
        }
		N.morir();
		N.mover();
		Sleep(30);


	}


	return 0;
}
