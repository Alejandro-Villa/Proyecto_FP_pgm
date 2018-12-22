#include<iostream>

using namespace std;

struct imagen{

   short int ancho;

   short int alto;

   short int imagen[650][650];
 
};

void LecturaDatos(imagen &input);

int main(){
	
	imagen entrada;
	//Leemos los datos
	LecturaDatos(entrada);
  //Mostramos los datos
	cout << "P2" << "\n";
	cout << entrada.ancho << " " << entrada.alto << "\n";
	cout << "255" << endl;

	for(int j = 0; j < entrada.alto; j++ ){
		
		for(int i = 0; i < entrada.ancho; i++)
			cout << entrada.imagen[i][j] << "\n";
		
	}
	
}

//Función de Lectura de datos
void LecturaDatos(imagen &input){
	
	int valor_blanco;
	string header;
	
	cin >> header;
	
	cin >> input.ancho;
	cin >> input.alto;
	
	cin >> valor_blanco;
	//cout << header << " " << valor_blanco;
	for ( int j = 0; j < input.alto; j++ )
		for ( int i = 0; i < input.ancho; i++)
			cin >> input.imagen[ i ][ j ];
}
