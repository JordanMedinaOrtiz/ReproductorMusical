void setColor(int color){
	//Esta función cambia el color del texto en la consola.
    //El argumento 'color' debe ser un número que representa el color.

    //SetConsoleTextAttribute cambia el color del texto en la consola.
    //GetStdHandle(STD_OUTPUT_HANDLE) obtiene el manejador de la salida estándar de la consola.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void centrarTexto(const char *texto, int y){
	//Esta función imprime el texto centrado en la pantalla en la coordenada vertical 'y'.
    //'texto' es el texto que se va a imprimir.
	
	//Calcula la longitud del texto.
	int longitud = strlen(texto);
	
	//Llama a la función gotoxy para posicionar el cursor en el centro de la pantalla horizontalmente.
	gotoxy(60-(longitud/2),y);
	
	//Imprime el texto en la posición calculada.
	cout<<texto;
}

void centrarTextoAcentos(const char *texto, int y, int acentos){
	//Esta función es similar a centrarTexto, pero admite texto con acentos.
    //'texto' es el texto que se va a imprimir.
    //'acentos' es el número de acentos.
	
	//Calcula la longitud del texto.
	int longitud = strlen(texto);
	
	//Llama a la función gotoxy para posicionar el cursor en el centro de la pantalla horizontalmente, con un ajuste.
	gotoxy(60-(longitud/2)+1,y);
	
	//Imprime el texto con los acentos en la posición calculada.
	printf(texto, acentos);
}

void cargando(){
	//Esta función muestra una animación de carga en la pantalla.
	
	//Cambia el color del texto y muestra un mensaje centrado en la pantalla.
	setColor(1);
	centrarTexto("Generando PlayList...",28);
	setColor(0);
	
	//Dibuja un patrón de carga con el carácter ASCII 177 (bloque medio).
	for(int i = 20; i<=100; i++){
		gotoxy(i,30);
		cout<<static_cast<char>(177);
	}
	setColor(3);

	//Dibuja un patrón de carga con el carácter ASCII 219 (bloque sólido) y pausa la ejecución durante 15 milisegundos.
	for(int i = 20; i<=100; i++){
		gotoxy(i,30);
		cout<<static_cast<char>(219);
		Sleep(15);
	}
}

void cuadro(int xs, int ys, int xi, int yi, int opciones){
	//Esta función dibuja un cuadro en la pantalla.
    //'xs' y 'ys' son las coordenadas del punto de inicio del cuadro.
    //'xi' e 'yi' son las coordenadas del punto final del cuadro.
    //'opciones' es el número de opciones a dibujar.
	setColor(1);
	
	for(int i=0; i<opciones; i++){
		//Dibuja líneas horizontales en la parte superior e inferior del cuadro.
		for(int i=xs; i <= xi; i++){
			gotoxy(i,ys);
			cout<<static_cast<char>(196);
			gotoxy(i,yi);
			cout<<static_cast<char>(196);
		}
		//Dibuja líneas verticales en los lados izquierdo y derecho del cuadro.
		for(int i=ys; i <= yi; i++){
			gotoxy(xs,i);
			cout<<static_cast<char>(179);
			gotoxy(xi,i);
			cout<<static_cast<char>(179);
		}
	
		//Dibuja las esquinas del cuadro y ajusta las coordenadas para la siguiente iteración.
		gotoxy(xs,ys);
		cout<<static_cast<char>(218);
		gotoxy(xi,yi);
		cout<<static_cast<char>(217);
		gotoxy(xi,ys);
		cout<<static_cast<char>(191);
		gotoxy(xs,yi);
		cout<<static_cast<char>(192);
		gotoxy(71,17);
		
	    //Ajusta las coordenadas para la siguiente iteración, considerando múltiples opciones.
		ys= ys + 3;
		yi= yi + 3;
	}
}
