
#include<iostream>

using namespace std;

struct imagen{

   int ancho;

   int alto;

   int imagen[650][650];

  };
  
int main(){
	imagen matriz;
	int i;
	int j;
	
	
	for(i = 0; i <= matriz.ancho; i++){
		for(j = 0; j <= matriz.alto; j++){
			if(matriz.imagen[i][j] < 125)
				matriz.imagen[i][j] = 0;
			if((matriz.imagen [i][j] <= 255) && (matriz.imagen[i][j] >= 125))
				matriz.imagen[i][j] = 255;
		}
	}
}
