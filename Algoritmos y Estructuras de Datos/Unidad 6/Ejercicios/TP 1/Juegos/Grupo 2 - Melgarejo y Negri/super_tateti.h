#include <string>
#include <iostream>
using namespace std;

#ifndef TATETI_H
#define TATETI_H

extern const int TAMANIO=9;
//Creo matrices de cada tateti chiquito
extern    int tateti_1[TAMANIO];
extern    int tateti_2[TAMANIO];
extern    int tateti_3[TAMANIO];
extern    int tateti_4[TAMANIO];
extern    int tateti_5[TAMANIO];
extern    int tateti_6[TAMANIO];
extern    int tateti_7[TAMANIO];
extern    int tateti_8[TAMANIO];
extern    int tateti_9[TAMANIO];
//Creo al tateti grande
extern    int main_tateti[9];
//Creo un registro de los movimientos
extern    int espacio_elegido;
extern    int tablero_elegido;

int main_super_tateti_juego();
void poner_ficha(int&, int&);
void verificar(int, int, int, int&);
void verificar_main(int);
string lugar_habilitado(int);
string tab_habilitado(int);
void rellenar_tablero(int, int);
void tablero();
string Xo0(int, int, int);
string tablero_jugando(int);

#endif // TATETI_H