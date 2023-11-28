void setColor(int color){
	//Esta funci�n cambia el color del texto en la consola.
    //El argumento 'color' debe ser un n�mero que representa el color.

    //SetConsoleTextAttribute cambia el color del texto en la consola.
    //GetStdHandle(STD_OUTPUT_HANDLE) obtiene el manejador de la salida est�ndar de la consola.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void centrarTexto(const char *texto, int y){
	//Esta funci�n imprime el texto centrado en la pantalla en la coordenada vertical 'y'.
    //'texto' es el texto que se va a imprimir.
	
	//Calcula la longitud del texto.
	int longitud = strlen(texto);
	
	//Llama a la funci�n gotoxy para posicionar el cursor en el centro de la pantalla horizontalmente.
	gotoxy(60-(longitud/2),y);
	
	//Imprime el texto en la posici�n calculada.
	cout<<texto;
}

void centrarTextoAcentos(const char *texto, int y, int acentos){
	//Esta funci�n es similar a centrarTexto, pero admite texto con acentos.
    //'texto' es el texto que se va a imprimir.
    //'acentos' es el n�mero de acentos.
	
	//Calcula la longitud del texto.
	int longitud = strlen(texto);
	
	//Llama a la funci�n gotoxy para posicionar el cursor en el centro de la pantalla horizontalmente, con un ajuste.
	gotoxy(60-(longitud/2)+1,y);
	
	//Imprime el texto con los acentos en la posici�n calculada.
	printf(texto, acentos);
}

void cargando(){
	//Esta funci�n muestra una animaci�n de carga en la pantalla.
	
	//Cambia el color del texto y muestra un mensaje centrado en la pantalla.
	setColor(1);
	centrarTexto("Generando PlayList...",28);
	setColor(0);
	
	//Dibuja un patr�n de carga con el car�cter ASCII 177 (bloque medio).
	for(int i = 20; i<=100; i++){
		gotoxy(i,30);
		cout<<static_cast<char>(177);
	}
	setColor(3);

	//Dibuja un patr�n de carga con el car�cter ASCII 219 (bloque s�lido) y pausa la ejecuci�n durante 15 milisegundos.
	for(int i = 20; i<=100; i++){
		gotoxy(i,30);
		cout<<static_cast<char>(219);
		Sleep(15);
	}
}

void cuadro(int xs, int ys, int xi, int yi, int opciones){
	//Esta funci�n dibuja un cuadro en la pantalla.
    //'xs' y 'ys' son las coordenadas del punto de inicio del cuadro.
    //'xi' e 'yi' son las coordenadas del punto final del cuadro.
    //'opciones' es el n�mero de opciones a dibujar.
	setColor(1);
	
	for(int i=0; i<opciones; i++){
		//Dibuja l�neas horizontales en la parte superior e inferior del cuadro.
		for(int i=xs; i <= xi; i++){
			gotoxy(i,ys);
			cout<<static_cast<char>(196);
			gotoxy(i,yi);
			cout<<static_cast<char>(196);
		}
		//Dibuja l�neas verticales en los lados izquierdo y derecho del cuadro.
		for(int i=ys; i <= yi; i++){
			gotoxy(xs,i);
			cout<<static_cast<char>(179);
			gotoxy(xi,i);
			cout<<static_cast<char>(179);
		}
	
		//Dibuja las esquinas del cuadro y ajusta las coordenadas para la siguiente iteraci�n.
		gotoxy(xs,ys);
		cout<<static_cast<char>(218);
		gotoxy(xi,yi);
		cout<<static_cast<char>(217);
		gotoxy(xi,ys);
		cout<<static_cast<char>(191);
		gotoxy(xs,yi);
		cout<<static_cast<char>(192);
		gotoxy(71,17);
		
	    //Ajusta las coordenadas para la siguiente iteraci�n, considerando m�ltiples opciones.
		ys= ys + 3;
		yi= yi + 3;
	}
}
