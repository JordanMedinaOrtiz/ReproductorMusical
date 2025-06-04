void archivoLectura_Canciones(){
	//Esta funci�n se encarga de leer informaci�n de un archivo de texto y construir una estructura de datos con g�neros, �lbumes y canciones.
	//Abre el archivo "canciones.txt" para lectura.
    ifstream arch("canciones.txt");
    //Declara variables para almacenar l�neas del archivo y caracteres temporales.
    string linea, c;
    
    //Comprueba si se pudo abrir el archivo, y muestra un mensaje de error si no es as�.
    if(arch.fail()){
        cerr<<"Error al abrir el archivo"<<endl;
    }else{
    	//Lee una l�nea del archivo y la almacena en la variable 'linea'.
        while(getline(arch, linea)){
        	//Crea un nuevo nodo de g�nero.
            Genero *generoNuevo = new Genero;
            //Utiliza un stringstream para leer la l�nea y extraer los datos.
            stringstream leer(linea);

            leer>>generoNuevo->id;
            getline(leer, c, '\t');
            getline(leer, generoNuevo->nombre, '\t');

            generoNuevo->albumes = NULL; //Inicializa la lista de �lbumes como NULL

            for(int i=0; i<3; i++){
                Album *albumNuevo = new Album;
                leer>>albumNuevo->id;
                getline(leer, c, '\t');
                getline(leer, albumNuevo->titulo, '\t');
                getline(leer, albumNuevo->artista, '\t');
                leer>>albumNuevo->anio;
                getline(leer, c, '\t');

                albumNuevo->canciones = NULL; //Inicializa la lista de canciones como NULL

                for(int j=0; j<8; j++){
                    Cancion *cancionNuevo = new Cancion;
                    leer>>cancionNuevo->id;
                    getline(leer, c, '\t');
                    getline(leer, cancionNuevo->nombre, '\t');
                    leer>>cancionNuevo->duracion;

                    if(i == 2 && j == 7){
                        getline(leer, c, '\n');
                    }else{
                        getline(leer, c, '\t');
                    }

                    cancionNuevo->siguiente = albumNuevo->canciones;
                    albumNuevo->canciones = cancionNuevo;
                }

                albumNuevo->siguiente = generoNuevo->albumes;
                generoNuevo->albumes = albumNuevo;
            }

            generoNuevo->siguiente = NULL;

            if(primerGenero == NULL){
                primerGenero = generoNuevo;
                ultimoGenero = generoNuevo;
            }else{
                ultimoGenero->siguiente = generoNuevo;
                ultimoGenero = generoNuevo;
            }
        }

        arch.close();

        //Asigna los punteros globales primerGenero y ultimoGenero
        primerGenero = primerGenero;
        ultimoGenero = ultimoGenero;
    }
}
