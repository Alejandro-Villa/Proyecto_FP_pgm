using namespace std;
// Este es el tipo de datos que vamos a usar todos
 struct imagen{

   int ancho;

   int alto;

   int imagen[650][650];

  };

//Función de Salida de datos.
void SalidaDatos(imagen fichero){
	
	cout << "P2\n";
	cout << fichero.ancho << " " << fichero.alto << "\n";
	cout << "255\n";
	
	for(int i = 0 ; i < fichero.alto ; i++){
		for(int j = 0 ; j < fichero.ancho ; j++){
			cout << fichero.imagen[i][j] << " ";
			if(j == fichero.ancho -1)
				cout << "\n";
		}
	}
}

int main(){
  
}
