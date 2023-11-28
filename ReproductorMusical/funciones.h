void imprimir(const char *categoria){
	//Esta función imprime una lista de reproducción con canciones de una categoría dada.
    //'categoria' es el nombre de la categoría.
    Usuario *auxUsuario = primeraCancionU;
    //Declara un puntero 'auxUsuario' para recorrer la lista de reproducción.
    int y = 5;
	
	//Verifica si la lista de reproducción está vacía y muestra un mensaje si es el caso.
    if(auxUsuario == NULL){
        cout<<"No hay elementos en la lista"<<endl;
        return;
    }
	
	centrarTexto("Tu PlayList de: ", 1);
	setColor(15);
	cout<<categoria;
	//Imprime el título de la lista de reproducción centrado y muestra el nombre de la categoría.
	
	setColor(1);
    cout<<endl<<endl<<"Numero de la cancion\t\t"<<"Nombre de la cancion\t\t"<<"Artista\t\t\t"<<"Duracion"<<endl;
    //Imprime encabezados de columna para la lista de reproducción.
    
    while(auxUsuario != NULL){
    	setColor(15);
    	//Muestra la información de cada canción en la lista de reproducción.     
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
    //Calcula el tiempo total de reproducción sumando las duraciones de todas las canciones en la lista.
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
	//Esta función libera la memoria de la lista de reproducción y la reinicia.
	//Declara un puntero 'actual' para recorrer la lista de reproducción.
    Usuario *actual = primeraCancionU;

    while(actual != NULL){
    	//Declara un puntero 'siguiente' para conservar el siguiente nodo antes de eliminar el actual.
        Usuario *siguiente = actual->siguiente;
        //Libera la memoria del nodo actual.
        delete actual;
        // Avanza al siguiente nodo.
        actual = siguiente;
    }
    
    //Establece los punteros de inicio y fin de la lista de reproducción como nulos, reiniciando la lista.
    primeraCancionU = NULL;
    ultimaCancionU = NULL;
}

void crearLista(const char *categoria){
	//Esta función crea una nueva lista de reproducción con canciones aleatorias de una categoría dada.
    //'categoria' es el nombre de la categoría.
    int auxAlbum = 0;
    int auxCancion[24] = {0};
    int cancion = 0;

    //Declaración de variables y punteros necesarios.
    Album *auxAlbumes = NULL;
    Cancion *auxCanciones = NULL;
    Genero *auxGenero = primerGenero;
    
	//Busca el género especificado en la lista de géneros.
    while(auxGenero != NULL && auxGenero->nombre != categoria){
        auxGenero = auxGenero->siguiente;
    }
    
    //Verifica si la categoría especificada existe y muestra un mensaje de error si no se encuentra.
    if(auxGenero == NULL){
        cout<<"El género '"<<categoria<<"' no existe."<<endl;
        return;
    }
    
	//Agrega el nuevo nodo a la lista de reproducción.
    for(int i = 1; i <= 10; i++){
    	//Crea un nuevo nodo para la lista de reproducción.
        Usuario *playlistNuevo = new Usuario;

        //Genera números aleatorios hasta encontrar una canción no repetida.
        do{
            cancion = (rand() % 24) + 1;
        }while(auxCancion[cancion - 1] != 0);

        auxCancion[cancion - 1] = 1;
        
        //Establece la canción seleccionada en el nuevo nodo.
        playlistNuevo->id = cancion;

        //A continuación, se busca información sobre la canción y el álbum al que pertenece.
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
            cout<<"Error al encontrar la canción y su información."<<endl;
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
	// Esta función crea una lista de reproducción con canciones aleatorias de varios géneros.
    int auxAlbum = 0;
    int auxCancion[24] = {0};
    int cancion = 0;
    int genero = 0;

    Album *auxAlbumes = NULL;
    Cancion *auxCanciones = NULL;

	const char *categoria;
    
	//Agrega el nuevo nodo a la lista de reproducción.
    for(int i=1; i<=10; i++){
    	//Declaración de un puntero 'auxGenero' para recorrer la lista de géneros.
    	Genero *auxGenero = primerGenero;
    	//Crea un nuevo nodo para la lista de reproducción.
        Usuario *playlistNuevo = new Usuario;
        
        //Selecciona un género al azar.
        int genero = (rand() % 5) + 1;
        
		//Asigna el nombre de la categoría de acuerdo al valor aleatorio generado.
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
	    
	    //Busca el género especificado en la lista de géneros.
	    while(auxGenero != NULL && auxGenero->nombre != categoria){
        	auxGenero = auxGenero->siguiente;
    	}
    	
    	// Verifica si la categoría especificada existe y muestra un mensaje de error si no se encuentra.
    	if(auxGenero == NULL){
	        cout<<"El genero '"<<categoria<<"' no existe."<<endl;
	        return;
	    }

    	//Genera números aleatorios hasta encontrar una canción no repetida.
        do{
            cancion = (rand() % 24) + 1;
        }while(auxCancion[cancion - 1] != 0);

        auxCancion[cancion - 1] = 1;
    	//Establece la canción seleccionada en el nuevo nodo.
        playlistNuevo->id = cancion;

    	//A continuación, se busca información sobre la canción y el álbum al que pertenece.
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
            cout<<"Error al encontrar la canción y su información."<<endl;
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
