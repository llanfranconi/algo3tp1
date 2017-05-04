#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int pintado_backtracking(int arreglo[], int largo, int posicion_actual, vector<int>* rojos, vector<int>* azules){
	
	if(posicion_actual == largo ){
		return largo - rojos->size() - azules->size();			//si termine de recorrer el arreglo, devuelvo
																//mi resultado
	}
	else{
		int elemento_actual = arreglo[posicion_actual];			//genero los vectores posibles de si pintara
		vector<int> rojos_nuevo(*rojos);						//el elemento actual del arreglo de cierto 
		rojos_nuevo.push_back(elemento_actual);					//color
		vector<int> azules_nuevo(*azules);
		azules_nuevo.push_back(elemento_actual);
		if(rojos->size() == 0 && azules->size() == 0 ) { 	 //evaluo el caso trivial donde no pinte ningun 
														  	//elemento de ningun color hasta mi posicion

			return min( min( pintado_backtracking(arreglo, largo, posicion_actual + 1, &rojos_nuevo, azules), 		//si mis vectores estan vacios
							pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, &azules_nuevo)),		//puedo pintarlo de cualquiera de los
						pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));					//dos colores, o dejarlo sin pintar
		}
		else{
			if(rojos->size() > 0 && azules->size() == 0){			//evaluo el caso donde ya pinte elementos
																	// de rojo, pero no de azul
				int ultimo_rojo = rojos->back();
				if(elemento_actual > ultimo_rojo){
					return min( min( pintado_backtracking(arreglo, largo, posicion_actual + 1, &rojos_nuevo, azules), 	//si mi elemento es mayor que el 
									pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, &azules_nuevo)),	//ultimo rojo, puedo pintarlo 
								pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));				//de cualquier color o dejarlo

				}
				else{
					return min( pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, &azules_nuevo), 		//en cambio si es menor o igual
								pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));				//solo puedo evaluar si pintarlo de azul
				}																										//o no pintarlo
			}
			else{
				if(rojos->size() == 0 && azules->size() > 0){		//reciproco del anterior caso, pero 
																	//con el azul con elementos
					int ultimo_azul = azules->back();
					if(elemento_actual < ultimo_azul){
						return min( min( pintado_backtracking(arreglo, largo, posicion_actual + 1, &rojos_nuevo, azules), 
										pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, &azules_nuevo)),
									pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));

					}else{
						return min( pintado_backtracking(arreglo, largo, posicion_actual + 1, &rojos_nuevo, azules),
									pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));
					}
				}
				else{
					if(rojos->size() > 0 && azules->size() > 0){   //me paro en el caso donde ya pinte almenos un numero
																   //de rojo, y almenos uno de azul
						int ultimo_rojo = rojos->back();
						int ultimo_azul = azules->back();
						if(elemento_actual > ultimo_rojo && elemento_actual < ultimo_azul){
							return min( min( pintado_backtracking(arreglo, largo, posicion_actual + 1, &rojos_nuevo, azules), //evaluo el caso donde puedo
											pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, &azules_nuevo)), //pintarlo de cualquiera de los
										pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));			  //dos colores, o dejarlo
						}
						else{
							if(elemento_actual > ultimo_rojo && elemento_actual >= ultimo_azul){
								return min( pintado_backtracking(arreglo, largo, posicion_actual + 1, &rojos_nuevo, azules), 	//evaluo el caso donde no 
											pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules));			//puedo agregarlo a los azules	
							}																											//pero si a los rojos
							else{
								if(elemento_actual <= ultimo_rojo && elemento_actual < ultimo_azul){
									return min( pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules), 			//evaluo el caso donde no
												pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, &azules_nuevo));	//puedo agregarlo a los rojos
								}																									//pero si a los azules
								else{
									return pintado_backtracking(arreglo, largo, posicion_actual + 1, rojos, azules);				//evaluo, por ultimo, el caso donde
								}																									//solo puedo dejarlo sin pintar
							}
						}
					}
				}
			}
		}
	}
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
	vector<int> rojos;
	vector<int> azules;
	int pos_ini = 0;
	int numeros_sin_pintar = pintado_backtracking(arreglo, largo_arreglo, pos_ini, &rojos, &azules);
	cout << "La cantidad de numeros sin pintar para este caso es: " << endl;
	cout << numeros_sin_pintar << endl;
	return 0;


}
