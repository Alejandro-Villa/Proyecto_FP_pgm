#include<iostream>

using namespace std;

class PGM{
    private:
       short int alto;
       short int ancho;
       short int pixel[650][650];
    public:
        PGM();
        void LecturaDatos();
        void SalidaDatos();
        void Blanquear();
        void Contraste_Max();
        
};

int main{

};

void PGM::LecturaDatos(){
	
	int valor_blanco;
	string header;
	
	cin >> header;
	
	cin >> ancho;
	cin >> alto;
	
	cin >> valor_blanco;

	for ( int j = 0; j < alto; j++ )
		for ( int i = 0; i < ancho; i++)
			cin >> pixel[ i ][ j ];
}

void PGM::SalidaDatos(){
	cout << "P2" << "\n";
	cout << ancho << " " << alto << "\n";
	cout << "255" << endl;

	for(int j = 0; j < alto; j++ ){
		for(int i = 0; i < ancho; i++)
			cout << pixel[i][j] << "\n";
    	}
}

void PGM::Blanquear(){
    
    int cambio_color = 255; // Variable por si se desea modificar el color al que cambiar
    
    for(int j = 0; j < alto; j++){

        for(int i = 0; i < ancho; i++)
            pixel[i][j] = cambio_color;

    }
}

void PGM::Contraste_Max(){
	for(int i = 0; i <= ancho; i++){
		for(int j = 0; j <= alto; j++){
			if(pixel[i][j] < 125)
				pixel[i][j] = 0;
			if(pixel[i][j] >= 125)
				pixel[i][j] = 255;
		}
	}
}