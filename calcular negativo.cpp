#include <iostream>
using namespace std;

struct imagen{
	
	int ancho;
	int alto;
	int imagen [650][650];
};


int main(){
	
	imagen nombre;	//cambiar nombre por el del struct

for (int i = 0; i < nombre.ancho; i++){
		for (int j = 0; j < nombre.alto; j++){
			nombre.imagen [i][j] = 255 - nombre.imagen[i][j];
		}
	}




}

// ESTRUCTURA DEL PROGRAMA

void leer (imagen &);
void escribir (imagen);

// funcion para pasar a blanco
void blanquear (imagen &)

int main(){
	imagen ima;
	
	leer (ima);
	blanquear (ima);
	escribir (ima);
	
// y ahora se llaman a las funciones

}
