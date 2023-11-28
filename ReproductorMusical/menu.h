void flechas(int x, int y, int inicio, int fin){
	char tecla = '\0';
	opc = 1;
	setColor(15);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla =  getch();
			setColor(0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc > inicio && tecla == 72){
				y = y-3;
				opc--;
			}
			if(opc < fin && tecla == 80){
				y = y + 3;
				opc++;
			}
			setColor(15);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla != 13);
}

void menu(){
	setColor(15);
	centrarTextoAcentos("M%csica cargada...", 1, 163);
	centrarTexto("Listo para comenzar!!", 2);
	centrarTextoAcentos("Crea tu propia lista de reproducci%Cn: ", 3, 162);
	
	while(opc != 7){
		setColor(1);
		centrarTexto("Elige tu genero de preferencia: ", 5);
		cuadro(53, 7, 66, 9, 7);
		setColor(15);
		centrarTexto("   Rock   ", 8);
		centrarTexto("    Pop   ", 11);
		centrarTexto("   Jazz   ", 14);
		centrarTexto("   Disco  ", 17);
		centrarTexto(" Regueton ", 20);
		centrarTexto("Shuffle!!!", 23);
		centrarTexto("   Salir  ", 26);
		eliminarListaReproduccion();
		flechas(52,8,1,7);
		cargando();
		setColor(1);
		system("cls");
		switch(opc){
			case OPC1:
				crearLista("Rock");
				imprimir("Rock");
				getch();
				break;
			case OPC2:
				crearLista("Pop");
				imprimir("Pop");
				getch();
				break;
			case OPC3:
				crearLista("Jazz");
				imprimir("Jazz");
				getch();
				break;
			case OPC4:
				crearLista("Disco");
				imprimir("Disco");
				getch();
				break;
			case OPC5:
				crearLista("Regueton");
				imprimir("Regueton");
				getch();
				break;
			case OPC6:
				shuffle();
				imprimir("Shuffle");
				getch();
				break;
			case OPC7:
				setColor(15);
				cout<<"Adios Usuario...";
				setColor(1);
				exit(1);
		}
		system("cls");
	}
	getch();
}
