#include "librerias.h"

//Función principal
int main(){
	srand(time(NULL)); //Declaramos la semilla de tiempo para generar numeros random 
	
	//Declaración de apuntadores de inicio y fin para las listas
	primerGenero = NULL;
	ultimoGenero = NULL;
	primerAlbum = NULL;
	ultimoAlbum = NULL;
	primeraCancion = NULL;
	ultimaCancion = NULL;
	primeraCancionU = NULL;
	ultimaCancionU = NULL;
	
    //Llamamos a la función que leerá la información desde un archivo y la almacenará en las listas anidadas
	archivoLectura_Canciones();
	
    //Llamamos a la función que mostrará el menú para seleccionar un género
	menu();
		
    //Esperamos una tecla para salir del programa
	getch();
	
	return 0;
}
