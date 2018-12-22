#include<iostream>
#include<string>


using namespace std;

struct imagen{

   short int ancho;

   short int alto;

   short int imagen[650][650];
 
};

void LecturaDatos(imagen &input);
void Blanquear(imagen &input);
void SalidaDatos(imagen fichero);

int main(){

imagen entrada;

LecturaDatos(entrada);

Blanquear(entrada);

SalidaDatos(entrada);

}

void LecturaDatos(imagen &input){
	
	int valor_blanco;
	string header;
	
	cin >> header;
	
	cin >> input.ancho;
	cin >> input.alto;
	
	cin >> valor_blanco;
	for ( int j = 0; j < input.alto; j++ )
		for ( int i = 0; i < input.ancho; i++)
			cin >> input.imagen[ i ][ j ];
}

void Blanquear(imagen &input){
    
    int cambio_color = 255; // Variable por si se desea modificar el color al que cambiar
    
    for(int j = 0; j < input.alto; j++){

        for(int i = 0; i < input.ancho; i++)
            input.imagen[i][j] = cambio_color;

    }
}

void SalidaDatos(imagen fichero){
    cout << "P2" << "\n";
	cout << fichero.ancho << " " << fichero.alto << "\n";
    cout << "255" << endl;

	for(int j = 0; j < fichero.alto; j++ ){
		
    	for(int i = 0; i < fichero.ancho; i++)
	        cout << fichero.imagen[i][j] << "\n";
    }
}
