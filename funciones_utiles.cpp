#include<iostream>
#include<cstring>

using namespace std;
// Este es el tipo de datos que vamos a usar todos
 struct imagen{

   int ancho;

   int alto;

   int matriz[650][650];

  };
//Función para leer los datos del ficchero .pmg

imagen Leer_datos( ) {
  imagen ima_input;
  int valor_blanco, alto;
  string P2;
  
 
  cin >> P2;
 
  cin >> imagen.ancho;
  cin >> imagen.alto;
 
  cin >> valor_blanco;
  for ( int j = 0; j < imagen.alto; j++ )
   for ( int i = 0; i < imagen.ancho;ij++){
    cin >> imagen.matriz[i][j];
   }
 
}

int main(){
  
 
 
}
