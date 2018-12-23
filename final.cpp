#include<iostream>

using namespace std;

/**
 * @file main.cpp
 * @brief Código fuente del proyecto para manipular archivos .pgm
 * 
 * Detalles.
 * 
 * En este fichero fuente se encuentra todo el código necesario para manipular imágenes codificadas en archivos .pgm. Las dimesiones máximas de la imagen deben ser 650x650, 
 * de otra forma se produce un desbordamiento y se generan fallos.
 * 
 * @author Alejandro Villanueva, Miguel Piñar, Francisco Bonillo, Gerardo Tirado, Carlos Romero.
 * @version 1.0
 */
/**
 * @class PGM
 * @brief Clase para manipular imágenes .pgm
 * 
 * Esta clase permite leer y escribir ficheros .pgm desde la E/S estándar, también incluye métodos para rotar, maximizar el contraste y hallar el negativo. 
 * La clase ha sido diseñada con el supuesto de que las imágenes de entrada están formateadas correctamente y con un valor de blanco igual a 255.
 */
/**
 * 
 * @fn PGM::Traspuesta()
 * @brief Hace la traspuesta de la matriz miembro \a pixel
 * @post La matriz \a pixel ahora es su traspuesta.
 */
/**
 * @fn PGM::Swap(int columna1, int columna2)
 * @brief Función que intercambia los valores de \a columna1 y \a columna2
 * @param columna1 Primera columna a intercambiar.
 * @param columna2 Segunda columna a intercambiar.
 * @post las columnas \a columna1 y \a columna2 de la matriz \a pixel aparecen cambiadas.
 */
/**
 * @fn PGM::PGM()
 * @brief Constructor por defecto, inicializa a una imagen negra de 650x650px
 * @post \a ancho y \a alto inician al valor 650, \a pixel inicia todas sus celdas a 0.
 */
/** 
 * @fn PGM::LecturaDatos()
 * @brief Lee desde la entrada estándar los datos para dar valores a la clase.
 * @post Los datos de la clase son inicializados.
 * 
 * Cuando lee los datos del archivo, descarta el identificador "P2", almacena ancho y alto, descarta el valor de blanco, 
 * pues por convenio lo situamos en 255, y lee la matriz \a pixel.
 */
/**
 * @fn PGM::SalidaDatos();
 * @brief Escribe por salida estándar los datos de la imagen con formato adecuado a un archivo .pgm
 * 
 * La función escribe primero "P2", que indica que el archivo contiene una imagen en formato PGM, luego imprime el ancho, un espacio, el alto y un salto de línea, 
 * luego el valor de blanco (255). Por último escribe la matriz que representa la imagen.
 */
/**
 * @fn PGM::Blanquear();
 * @brief Cambia todos los valores de \a pixel a 255, el valor de blanco por defecto.
 * @post Todos los valores de \a pixel ahora son 255.
 */
/**
 * @fn PGM::Contraste_Max();
 * @brief Aumenta el contraste de la imagen, llevando los píxeles más cercanos al blanco a 255 y los más cercanos al negro al 0.
 * @post Los píxeles mayores que 127 (valor medio) cambian su valor a 255 (blanco), los inferiores cambian a 0 (negro). 
 */
/**
 * @fn PGM::Rotar();
 * @brief Rota la imagen 90º a la derecha
 * @post La matriz \a pixel es traspuesta y luego sus columnas son intercambiadas sucesivamente.
 */
/**
 * @fn PGM::Negativo();
 * @brief Produce el negativo de la imagen.
 * @post Los píxeles de \a pixel cambian su valor a \f$255 - pixel[i][j]\f$
 */
/**
 * @fn int main()
 * @brief Función principal, requerida para poder compilar
 * 
 * Esta función no tiene ningún código implementado. Se puede utilizar para probar las características y el funcionamiento de la clase.
 */

class PGM{
	private:
		/// Alto de la imagen, en px, corresponde con el número de columnas de la matriz.
		short int alto;
		/// Ancho de la imagen, en px, corresponde con el número de filas de la matriz.
		short int ancho;
		/// Matriz que representa la imagen, cada punto es un píxel.
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
	int cambio_color = 255;

	for(int i = 0; i < alto; i++)
		for(int j = 0; j < ancho; j++)
			pixel[i][j] = cambio_color;

}

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