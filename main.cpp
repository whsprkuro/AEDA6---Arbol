/*
 * main.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#include <iostream>
#include <stdlib.h>

#include "DNI.hpp"
#include "nodo.hpp"
#include "arbol.hpp"

using namespace std;

void pruebaLau(){
//	int dato;
//	Arbol tree;
//
//	do{
//		cout << "Insertar una clave" << endl;
//		cout << "Para salir pulse 0" << endl;
//		cin >> dato;
//
//		if(dato != 0){
//			tree.insertar(dato, tree.getraiz());
//		}
//
//		system("cls");
//	}
//	while(dato > 0);
//
//	tree.niveles();
}

void pruebaDNI(){
	DNI A, B;

	cout << A << endl;
	cout << B << endl;

	A.set_numDNI("12345678");
	B.set_numDNI("caca");

	cout << A << endl;
	cout << B << endl;
}

void pruebaNodo(){
	DNI A;
	nodoBB<DNI> N(A);

	N.mostrarNodo();
}

int main(){

//	pruebaDNI();
//	pruebaNodo();


	return 0;
}
