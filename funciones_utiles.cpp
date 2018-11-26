using namespace std;
// Este es el tipo de datos que vamos a usar todos
struct imagen{

	int ancho;

	int alto;

	int imagen[650][650];

};

//Función de Salida de datos.
void SalidaDatos(imagen fichero){
	cout << "P2" << "\n";
	cout << fichero.ancho << " " << fichero.alto << "\n";
	cout << "255" << endl;

	for(int j = 0; j < fichero.alto; j++ ){
		for(int i = 0; i < fichero.ancho; i++)
			cout << fichero.imagen[i][j] << "\n";
    	}
}

int main(){
  
}
