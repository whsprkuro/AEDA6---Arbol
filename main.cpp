/*
 * main.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#include <iostream>
#include <stdlib.h> //srand, rand

#include "DNI.hpp"
#include "nodo.hpp"
#include "arbol.hpp"

using namespace std;

void menu();
void demo(ABB<DNI>& Arbol);
void insert(ABB<DNI>& Arbol);
void eliminar(ABB<DNI>& Arbol);
void est(ABB<DNI>& Arbol);
void contador_busqueda(ABB<DNI>& Arbol, int nPruebas, nodoBB<DNI> *dnivector, int tree_sz);
void contador_insercion(ABB<DNI>& Arbol, int nPruebas, nodoBB<DNI> *dnivector, int tree_sz);

void menu(){
	cout << "Introducir Tipo de Prueba" << endl << endl;
	cout << "1. Demostración" << endl;
	cout << "2. Estadística" << endl;
	int tPrueba;
	cin >> tPrueba;

	ABB<DNI> Arbol;

	if(tPrueba == 1){
		Arbol.niveles1(Arbol.getraiz(), 0);
		demo(Arbol); //Modo Demostración
	}
	else if(tPrueba == 2)
		est(Arbol); //Modo Estadística
	else{
		cout << "Opción inválida" << endl;
		menu();
	}
}

void demo(ABB<DNI>& Arbol){

	cout << "Seleccione Operación" << endl << endl;
	cout << "[0] Salir" << endl;
	cout << "[1] Insertar Clave" << endl;
	cout << "[2] Eliminar Clave" << endl;
	int opcion;
	cin >> opcion;

	switch(opcion){
		case 0:
			cout << endl;
			menu();
			break;
		case 1:
			insert(Arbol);
			break;
		case 2:
			eliminar(Arbol);
			break;
		}

	if((opcion != 0) || (opcion != 1) || (opcion != 2)){
		cout << endl << "Opción inválida" << endl << endl;
		demo(Arbol);
	}
}

void insert(ABB<DNI>& Arbol){

	nodoBB<DNI> *aux = new nodoBB<DNI>;

	cout << endl << "Introduzca Valor a Insertar" << endl;
	cin >> aux->dato; //introduzco el valor del DNI directamente en el nodo
	cout << endl;

	Arbol.insertar(aux, Arbol.getraiz(), 1); //inserto el nodo con el nuevo valor en el árbol
	Arbol.niveles1(Arbol.getraiz(), 0);
	cout << endl;

	demo(Arbol);
}

void eliminar(ABB<DNI>& Arbol){

	if(Arbol.getraiz() == NULL){
		cout << endl << "Árbol Vacío, no hay Nada que Borrar" << endl << endl;
		demo(Arbol);
	}

	cout << endl << "Introduzca Valor a Eliminar" << endl;
	string val;
	cin >> val;

	DNI A; //creo un DNI con valor especificado
	A.set_numDNI(val);

	Arbol.eliminar(A); //el DNI será buscado en el árbol y eliminado
	Arbol.niveles1(Arbol.getraiz(), 0);
	cout << endl;

	demo(Arbol);
}

void est(ABB<DNI>& Arbol){
	cout << endl << "Introducir Tamaño del Árbol" << endl;
	int N;
	cin >> N;

	cout << endl << "Introducir Número de Pruebas a Realizar" << endl;
	int nPruebas;
	cin >> nPruebas;
	cout << endl;

	nodoBB<DNI> *dnivector = new nodoBB<DNI>[2*N]; //Genera vector de DNI aleatorios (Banco de Pruebas)
	for(int i = 0; i < 2*N; i++){
		dnivector[i].dato = DNI();
	}

	for(int i = 0; i < N; i++){ //Insertar DNI hasta el tamaño del árbol
		Arbol.insertar(&dnivector[i], Arbol.getraiz(), 0);
	}

//	Arbol.niveles1(Arbol.getraiz(), 0);

	cout << "\t\t\t\tNúmero de Comparaciones" << endl;
	cout << "                N        Pruebas        Mínimo        Medio        Máximo" << endl;

	contador_busqueda(Arbol, nPruebas, dnivector, N);
	contador_insercion(Arbol, nPruebas, dnivector, N);

	cout << endl << endl;
	menu();
}

void contador_busqueda(ABB<DNI>& Arbol, int nPruebas, nodoBB<DNI> *dnivector, int tree_sz){
	int total = 0, min = 99999, max = 0, clave_random = 0;
	nodoBB<DNI> *padre, *nodo_actual;

	for(int j = 0; j <= nPruebas; j++){
		clave_random = rand() % tree_sz; //extraer clave de forma aleatoria de entre las insertadas en el árbol

//		dnivector[clave_random].mostrarNodo();
//		cout << endl << endl;

		int contador = Arbol.buscar(dnivector[clave_random].dato, &padre, &nodo_actual, 0); //Buscar en el árbol las nPruebas claves

		if(contador < min)
			min = contador;
		if(contador > max)
			max = contador;
		total += contador;

		if(j == nPruebas)
			cout << "Búsqueda:       " << tree_sz << "\t    " << nPruebas << "\t\t   " << min << "\t\t" << total/nPruebas << "\t     " << max << endl;
	}
}

void contador_insercion(ABB<DNI>& Arbol, int nPruebas, nodoBB<DNI> *dnivector, int tree_sz){
	int total = 0, min = 99999, max = 0, clave_random = 0;
	nodoBB<DNI> *padre, *nodo_actual;

	for(int j = 0; j <= nPruebas; j++){
		clave_random = rand() % tree_sz + tree_sz; //extraer clave de forma aleatoria del banco de pruebas que no se insertaron en el árbol

//		dnivector[clave_random].mostrarNodo();
//		cout << endl << endl;

		int contador = Arbol.buscar(dnivector[clave_random].dato, &padre, &nodo_actual, 0); //Buscar en el árbol las nPruebas claves

		if(contador < min)
			min = contador;
		if(contador > max)
			max = contador;
		total += contador;

		if(j == nPruebas)
			cout << "Inserción:      " << tree_sz << "\t    " << nPruebas << "\t\t   " << min << "\t\t" << total/nPruebas << "\t     " << max << endl;
	}
}

int main(){

	menu();

	return 0;
}
