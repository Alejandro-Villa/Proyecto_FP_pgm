#include<iostream>

using namespace std;

/**
 * @file contraste_max.cpp
 * @brief Código fuente para aumentar el contraste a archivos PGM.
 * 
 * Detalles.
 * 
 * En este fichero fuente se encuentra el código necesario para aumentar el contraste a imágenes codificadas en archivos .pgm. Las dimesiones máximas de la imagen deben ser 650x650, 
 * de otra forma se produce un desbordamiento y se generan fallos.
 * 
 * @author Alejandro Villanueva, Miguel Piñar, Francisco Bonillo, Gerardo Tirado, Carlos Romero.
 */

/**
 * @class PGM
 * @brief Clase para manipular imágenes .pgm
 * 
 * Esta clase permite leer y escribir ficheros .pgm desde la E/S estándar, incluye un método para maximizar el contraste. 
 * La clase ha sido diseñada con el supuesto de que las imágenes de entrada están formateadas correctamente y con un valor de blanco igual a 255.
 */
class PGM{
	private:
		/// Alto de la imagen, en px, corresponde con el número de columnas de la matriz.
		short int alto;
		/// Ancho de la imagen, en px, corresponde con el número de filas de la matriz.
		short int ancho;
		/// Matriz que representa la imagen, cada punto es un píxel.
		short int pixel[650][650];

	public:
		PGM();
		void LecturaDatos();
		void SalidaDatos();
		void Contraste_Max();
		
};

/**
 * @fn int main()
 * @brief Función principal, requerida para poder compilar.
 * Permite aumentar el contraste de la imagen.
 */
int main(){
	PGM imagen;

	imagen.LecturaDatos();
	imagen.Contraste_Max();
	imagen.SalidaDatos();

	return 0;
}

/**
 * @fn PGM::PGM()
 * @brief Constructor por defecto, inicializa a una imagen negra de 650x650px
 * @post \a ancho y \a alto inician al valor 650, \a pixel inicia todas sus celdas a 0.
 */
PGM::PGM(){
	alto = 650;
	ancho = 650;

	for (int i = 0; i < 650; i++)
		for (int j = 0; j < 650; j++)
			pixel[i][j] = 0;
}

/** 
 * @fn PGM::LecturaDatos()
 * @brief Lee desde la entrada estándar los datos para dar valores a la clase.
 * @post Los datos de la clase son inicializados.
 * 
 * Cuando lee los datos del archivo, descarta el identificador "P2", almacena ancho y alto, descarta el valor de blanco, 
 * pues por convenio lo situamos en 255, y lee la matriz \a pixel.
 */
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

/**
 * @fn PGM::SalidaDatos();
 * @brief Escribe por salida estándar los datos de la imagen con formato adecuado a un archivo .pgm
 * 
 * La función escribe primero "P2", que indica que el archivo contiene una imagen en formato PGM, luego imprime el ancho, un espacio, el alto y un salto de línea, 
 * luego el valor de blanco (255). Por último escribe la matriz que representa la imagen.
 */
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

/**
 * @fn PGM::Contraste_Max();
 * @brief Aumenta el contraste de la imagen, llevando los píxeles más cercanos al blanco a 255 y los más cercanos al negro al 0.
 * @post Los píxeles mayores que 127 (valor medio) cambian su valor a 255 (blanco), los inferiores cambian a 0 (negro). 
 */
void PGM::Contraste_Max(){
	for(int i = 0; i < alto; i++){
		for(int j = 0; j < ancho; j++){
			if(pixel[i][j] < 127)
				pixel[i][j] = 0;
			if(pixel[i][j] >= 127)
				pixel[i][j] = 255;
		}
	}
}
