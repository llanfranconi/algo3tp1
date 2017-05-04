#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int pintado_dinamico(int[] arreglo, int largo_arreglo, int pos_actual, vector<vector<vector<int>>>* datos){
	
}


int main(){

	cout<< "Introduzca la cantidad de numeros a evaluar" << endl;
	unsigned int largo_arreglo = 0;
	cin >> largo_arreglo; 										//guardo el input del usuario sobre 
																//la cant. de números en un int

	cin.ignore(); 												//descarto el cin para poder 
																//trabajar con getline en el siguiente input
																//sin que agarre el valor anterior

	string tira_numeros = "";
	cout<< "Introduzca, separados por un solo espacio entre si, los numeros a evaluar" << endl;

	getline(cin, tira_numeros);									//me guardo la tira de numeros en un string

	int arreglo[largo_arreglo];									//genero un arreglo con la cantidad justa de numeros

	int i = 0;
	string numero_actual = "";
	stringstream tira_numeros_stream(tira_numeros);				//creo un stringstream con la tira de numeros
																// con el fin de poder recorrer el input
																// en base al espacio como delimitador

	while(getline(tira_numeros_stream, numero_actual, ' ')){	//agrego cada numero en el orden pasado al arreglo
		arreglo[i] = stoi(numero_actual);
		i++;
	}
	vector<int> vectorInterno;
	i = 0;
	while(i < largo_arreglo){
		vectorInterno.push_back(-1);
		i++;
	}
	vector<vector<int>> vectorMedio;
	i = 0;
	while(i < largo_arreglo){
		vectorMedio.push_back(vectorInterno);
		i++:
	}
	vector<vector<vector<int>>> datos;
	i = 0;
	while(i < largo_arreglo){
		datos.push_back(vectorMedio);
		i++;
	}
	int pos_ini = 0;
	int numeros_sin_pintar = pintado_dinamico(arreglo, largo_arreglo, pos_ini, &datos);
	cout << "La cantidad de numeros sin pintar para este caso es: " << endl;
	cout << numeros_sin_pintar << endl;
	return 0;


}