void imprimir(const char *categoria){
	//Esta funci�n imprime una lista de reproducci�n con canciones de una categor�a dada.
    //'categoria' es el nombre de la categor�a.
    Usuario *auxUsuario = primeraCancionU;
    //Declara un puntero 'auxUsuario' para recorrer la lista de reproducci�n.
    int y = 5;
	
	//Verifica si la lista de reproducci�n est� vac�a y muestra un mensaje si es el caso.
    if(auxUsuario == NULL){
        cout<<"No hay elementos en la lista"<<endl;
        return;
    }
	
	centrarTexto("Tu PlayList de: ", 1);
	setColor(15);
	cout<<categoria;
	//Imprime el t�tulo de la lista de reproducci�n centrado y muestra el nombre de la categor�a.
	
	setColor(1);
    cout<<endl<<endl<<"Numero de la cancion\t\t"<<"Nombre de la cancion\t\t"<<"Artista\t\t\t"<<"Duracion"<<endl;
    //Imprime encabezados de columna para la lista de reproducci�n.
    
    while(auxUsuario != NULL){
    	setColor(15);
    	//Muestra la informaci�n de cada canci�n en la lista de reproducci�n.     
    	gotoxy(10, y);
        cout<<auxUsuario->id;
        gotoxy(32, y);
        cout<<auxUsuario->nombre;
        gotoxy(64, y);
        cout<<auxUsuario->artista;
        gotoxy(93, y);
        cout<<auxUsuario->duracion<<endl;
        auxUsuario = auxUsuario->siguiente;
        y += 1;
    }
    //Calcula el tiempo total de reproducci�n sumando las duraciones de todas las canciones en la lista.
    int tiempoTotal = 0;
    Usuario *actual = primeraCancionU;
    while(actual != NULL){
        tiempoTotal += actual->duracion;
        actual = actual->siguiente;
    }
    
	setColor(1);
    cout<<endl<<"Tiempo total de reproduccion: ";
    setColor(15);
	cout<<tiempoTotal;
	cout<<" minutos"<<endl;
}

void eliminarListaReproduccion(){
	//Esta funci�n libera la memoria de la lista de reproducci�n y la reinicia.
	//Declara un puntero 'actual' para recorrer la lista de reproducci�n.
    Usuario *actual = primeraCancionU;

    while(actual != NULL){
    	//Declara un puntero 'siguiente' para conservar el siguiente nodo antes de eliminar el actual.
        Usuario *siguiente = actual->siguiente;
        //Libera la memoria del nodo actual.
        delete actual;
        // Avanza al siguiente nodo.
        actual = siguiente;
    }
    
    //Establece los punteros de inicio y fin de la lista de reproducci�n como nulos, reiniciando la lista.
    primeraCancionU = NULL;
    ultimaCancionU = NULL;
}

void crearLista(const char *categoria){
	//Esta funci�n crea una nueva lista de reproducci�n con canciones aleatorias de una categor�a dada.
    //'categoria' es el nombre de la categor�a.
    int auxAlbum = 0;
    int auxCancion[24] = {0};
    int cancion = 0;

    //Declaraci�n de variables y punteros necesarios.
    Album *auxAlbumes = NULL;
    Cancion *auxCanciones = NULL;
    Genero *auxGenero = primerGenero;
    
	//Busca el g�nero especificado en la lista de g�neros.
    while(auxGenero != NULL && auxGenero->nombre != categoria){
        auxGenero = auxGenero->siguiente;
    }
    
    //Verifica si la categor�a especificada existe y muestra un mensaje de error si no se encuentra.
    if(auxGenero == NULL){
        cout<<"El g�nero '"<<categoria<<"' no existe."<<endl;
        return;
    }
    
	//Agrega el nuevo nodo a la lista de reproducci�n.
    for(int i = 1; i <= 10; i++){
    	//Crea un nuevo nodo para la lista de reproducci�n.
        Usuario *playlistNuevo = new Usuario;

        //Genera n�meros aleatorios hasta encontrar una canci�n no repetida.
        do{
            cancion = (rand() % 24) + 1;
        }while(auxCancion[cancion - 1] != 0);

        auxCancion[cancion - 1] = 1;
        
        //Establece la canci�n seleccionada en el nuevo nodo.
        playlistNuevo->id = cancion;

        //A continuaci�n, se busca informaci�n sobre la canci�n y el �lbum al que pertenece.
        if(cancion >= 1 && cancion <= 8){
            auxAlbum = 1;
            auxAlbumes = auxGenero->albumes;
            while(auxAlbumes != NULL && auxAlbumes->id != 1){
                auxAlbumes = auxAlbumes->siguiente;
            }
        }else if(cancion >= 9 && cancion <= 16){
            auxAlbum = 2;
            auxAlbumes = auxGenero->albumes;
            while(auxAlbumes != NULL && auxAlbumes->id != 2){
                auxAlbumes = auxAlbumes->siguiente;
            }
        }else if(cancion >= 17){
            auxAlbum = 3;
            auxAlbumes = auxGenero->albumes;
            while(auxAlbumes != NULL && auxAlbumes->id != 3){
                auxAlbumes = auxAlbumes->siguiente;
            }
        }

        auxCanciones = auxAlbumes->canciones;
        while(auxCanciones != NULL && auxCanciones->id != cancion){
            auxCanciones = auxCanciones->siguiente;
        }

        if(auxAlbumes != NULL && auxCanciones != NULL){
            playlistNuevo->nombre = auxCanciones->nombre;
            playlistNuevo->duracion = auxCanciones->duracion;
            playlistNuevo->artista = auxAlbumes->artista;
        }else{
            cout<<"Error al encontrar la canci�n y su informaci�n."<<endl;
            delete playlistNuevo;
            continue;
        }

        playlistNuevo->siguiente = NULL;

        if(primeraCancionU == NULL){
            primeraCancionU = playlistNuevo;
            ultimaCancionU = playlistNuevo;
        }else{
            ultimaCancionU->siguiente = playlistNuevo;
            ultimaCancionU = playlistNuevo;
        }
    }
}

void shuffle(){
	// Esta funci�n crea una lista de reproducci�n con canciones aleatorias de varios g�neros.
    int auxAlbum = 0;
    int auxCancion[24] = {0};
    int cancion = 0;
    int genero = 0;

    Album *auxAlbumes = NULL;
    Cancion *auxCanciones = NULL;

	const char *categoria;
    
	//Agrega el nuevo nodo a la lista de reproducci�n.
    for(int i=1; i<=10; i++){
    	//Declaraci�n de un puntero 'auxGenero' para recorrer la lista de g�neros.
    	Genero *auxGenero = primerGenero;
    	//Crea un nuevo nodo para la lista de reproducci�n.
        Usuario *playlistNuevo = new Usuario;
        
        //Selecciona un g�nero al azar.
        int genero = (rand() % 5) + 1;
        
		//Asigna el nombre de la categor�a de acuerdo al valor aleatorio generado.
	    switch (genero) {
	        case 1: categoria = "Rock";
	                break;
	        case 2: categoria = "Pop";
	                break;
	        case 3: categoria = "Jazz";
	                break;
	        case 4: categoria = "Disco";
	                break;
	        case 5: categoria = "Regueton";
	                break;
	    }
	    
	    //Busca el g�nero especificado en la lista de g�neros.
	    while(auxGenero != NULL && auxGenero->nombre != categoria){
        	auxGenero = auxGenero->siguiente;
    	}
    	
    	// Verifica si la categor�a especificada existe y muestra un mensaje de error si no se encuentra.
    	if(auxGenero == NULL){
	        cout<<"El genero '"<<categoria<<"' no existe."<<endl;
	        return;
	    }

    	//Genera n�meros aleatorios hasta encontrar una canci�n no repetida.
        do{
            cancion = (rand() % 24) + 1;
        }while(auxCancion[cancion - 1] != 0);

        auxCancion[cancion - 1] = 1;
    	//Establece la canci�n seleccionada en el nuevo nodo.
        playlistNuevo->id = cancion;

    	//A continuaci�n, se busca informaci�n sobre la canci�n y el �lbum al que pertenece.
        if(cancion >= 1 && cancion <= 8){
            auxAlbum = 1;
            auxAlbumes = auxGenero->albumes;
            while(auxAlbumes != NULL && auxAlbumes->id != 1){
                auxAlbumes = auxAlbumes->siguiente;
            }
        }else if(cancion >= 9 && cancion <= 16){
            auxAlbum = 2;
            auxAlbumes = auxGenero->albumes;
            while(auxAlbumes != NULL && auxAlbumes->id != 2){
                auxAlbumes = auxAlbumes->siguiente;
            }
        }else if(cancion >= 17){
            auxAlbum = 3;
            auxAlbumes = auxGenero->albumes;
            while(auxAlbumes != NULL && auxAlbumes->id != 3){
                auxAlbumes = auxAlbumes->siguiente;
            }
        }

        auxCanciones = auxAlbumes->canciones;
        while(auxCanciones != NULL && auxCanciones->id != cancion){
            auxCanciones = auxCanciones->siguiente;
        }

        if(auxAlbumes != NULL && auxCanciones != NULL){
            playlistNuevo->nombre = auxCanciones->nombre;
            playlistNuevo->duracion = auxCanciones->duracion;
            playlistNuevo->artista = auxAlbumes->artista;
        }else{
            cout<<"Error al encontrar la canci�n y su informaci�n."<<endl;
            delete playlistNuevo;
            continue;
        }

        playlistNuevo->siguiente = NULL;

        if(primeraCancionU == NULL){
            primeraCancionU = playlistNuevo;
            ultimaCancionU = playlistNuevo;
        }else{
            ultimaCancionU->siguiente = playlistNuevo;
            ultimaCancionU = playlistNuevo;
        }
    }
}
