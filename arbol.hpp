/*
 * arbol.hpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#pragma once

#include "nodo.hpp"
//#include "dni.hpp"

#include <iostream>
#include <queue>

using namespace std;

template <class Clave>

class ABB{

private:
	nodoBB<Clave>* raiz;

public:
	ABB();
	~ABB();
	void podar(nodoBB<Clave>*);//funcion de ayuda para borrar el arbol ENTERO

	nodoBB<Clave>* getraiz();

	void insertar(Clave& dato, nodoBB<Clave>* nodo);

	void preorden(nodoBB<Clave>* nodo);
	void inorden(nodoBB<Clave>* nodo);
	void posorden(nodoBB<Clave>* nodo);
	void niveles();

};
