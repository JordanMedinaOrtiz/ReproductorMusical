#include "librerias.h"

//Funci�n principal
int main(){
	srand(time(NULL)); //Declaramos la semilla de tiempo para generar numeros random 
	
	//Declaraci�n de apuntadores de inicio y fin para las listas
	primerGenero = NULL;
	ultimoGenero = NULL;
	primerAlbum = NULL;
	ultimoAlbum = NULL;
	primeraCancion = NULL;
	ultimaCancion = NULL;
	primeraCancionU = NULL;
	ultimaCancionU = NULL;
	
    //Llamamos a la funci�n que leer� la informaci�n desde un archivo y la almacenar� en las listas anidadas
	archivoLectura_Canciones();
	
    //Llamamos a la funci�n que mostrar� el men� para seleccionar un g�nero
	menu();
		
    //Esperamos una tecla para salir del programa
	getch();
	
	return 0;
}
