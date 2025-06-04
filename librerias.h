#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

//Estructura de una playslist
struct Usuario{
	int id;
	string nombre;
	string artista;
	int duracion;
	struct Usuario *siguiente;
}*primeraCancionU, *ultimaCancionU;

//Estructura de una canci�n
struct Cancion{
	int id;
	string nombre;
	int duracion;
	struct Cancion *siguiente;
}*primeraCancion, *ultimaCancion;

//Estructura de un �lbum
struct Album{
	int id;
	string titulo;
	string artista;
	int anio;
	struct Cancion *canciones;
	struct Album *siguiente;
}*primerAlbum, *ultimoAlbum;

//Estructura de un g�nero
struct Genero{
	int id;
	string nombre;
	struct Album *albumes;
	struct Genero *siguiente;
}*primerGenero, *ultimoGenero;

//Funci�n gotoxy que posiciona el cursor en una posici�n espec�fica en la pantalla
void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Enumeraci�n de las opciones del men�
enum MENU{OPC1 = 1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};
int opc = 0, x = 0, y = 0;

//Inclusi�n de archivos de cabecera
#include "decoracion.h"
#include "funciones.h"
#include "menu.h"
#include "archivos.h"
