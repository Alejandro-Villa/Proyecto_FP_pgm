using namespace std;
// Este es el tipo de datos que vamos a usar todos
 struct imagen{

   int ancho;

   int alto;

   int imagen[650][650];

  };

//Función de Salida de datos.
int SalidaDatos(imagen fichero){
	
	cout << "P2\n";
	cout << imagen.ancho << " " << imagen.alto << "\n";
	cout << "255\n";
	
	for(int i = 0 ; i < imagen.alto ; i++){
		for(int j = 0 ; j < imagen.ancho ; j++){
			cout << imagen.imagen[i][j] << " ";
			if(j == imagen.ancho -1)
				cout << "\n";
		}
	}
}

int main(){
  
}
