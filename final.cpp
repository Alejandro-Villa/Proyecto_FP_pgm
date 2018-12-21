#include<iostream>

using namespace std;

class PGM{
	private:
		short int alto;
		short int ancho;
		short int pixel[650][650];	
		void Traspuesta();
		void Swap(int columna1, int columna2);

	public:
		PGM();
		void LecturaDatos();
		void SalidaDatos();
		void Blanquear();
		void Contraste_Max();
		void Rotar();
		void Negativo();
        
};

int main(){
	PGM imagen;

	imagen.LecturaDatos();
	imagen.Rotar();
	imagen.SalidaDatos();

	return 0;
}

PGM::PGM(){
	alto = 650;
	ancho = 650;

	for (int i = 0; i < 650; i++)
		for (int j = 0; j < 650; j++)
			pixel[i][j] = 0;
}

void PGM::LecturaDatos(){
	int valor_blanco;
	string header;
	
	cin >> header;
	
	cin >> ancho;
	cin >> alto;
	
	cin >> valor_blanco;

	for ( int i = 0; i < alto; i++ )
		for ( int j = 0; j < ancho; j++)
			cin >> pixel[ i ][ j ];
}

void PGM::SalidaDatos(){
	cout << "P2" << "\n";
	cout << ancho << " " << alto << "\n";
	cout << "255" << endl;

	for(int i = 0; i < alto; i++ ){
		for(int j = 0; j < ancho; j++)
			cout << pixel[i][j] << " ";
		cout << endl;
	}
}

void PGM::Blanquear(){
	int cambio_color = 255; // Variable por si se desea modificar el color al que cambiar

	for(int i = 0; i < alto; i++)
		for(int j = 0; j < ancho; j++)
			pixel[i][j] = cambio_color;

}

void PGM::Contraste_Max(){
	for(int i = 0; i < alto; i++){
		for(int j = 0; j < ancho; j++){
			if(pixel[i][j] < 125)
				pixel[i][j] = 0;
			if(pixel[i][j] >= 125)
				pixel[i][j] = 255;
		}
	}
}

void PGM::Rotar(){
	Traspuesta();
	for (short int i = 0; i <= ancho/2 - 1; i++)
		Swap(i, ancho-i-1);
}

void PGM::Traspuesta(){
	short int cambio;

	for (short int i = 0; i < alto; i++){
		for (short int j = i; j < ancho; j++){
			cambio = pixel[i][j];
			pixel[i][j] = pixel[j][i];
			pixel[j][i] = cambio;
		}
	}

	cambio = ancho;
	ancho = alto;
	alto = cambio;
}

void PGM::Swap(int columna1, int columna2){
	short int intercambia;

	for(short int i = 0; i < alto; i++){
		intercambia = pixel[i][columna1];
		pixel[i][columna1] = pixel[i][columna2];
		pixel[i][columna2] = intercambia;
	}
}

void PGM::Negativo(){
	for (int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			pixel[i][j] = 255 - pixel[i][j];
		}
	}
}
