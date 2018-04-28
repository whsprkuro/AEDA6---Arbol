/*
 * arbol.hpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#pragma once

#include "nodo.hpp"

#include <iostream>

using namespace std;

template <class Clave>

class ABB{

private:
	nodoBB<Clave>* raiz;

public:
	ABB();
	~ABB();
	void podar(nodoBB<Clave>*); //funcion de ayuda para borrar el arbol ENTERO
	nodoBB<Clave>* getraiz();

	int insertar(nodoBB<Clave>* aux, nodoBB<Clave>* nodo, int modo);
	int buscar(Clave X, nodoBB<Clave> **padre, nodoBB<Clave> **nodo_actual, int modo);
	void eliminar(Clave X);
	void eliminar_final(nodoBB<Clave> *pad, nodoBB<Clave> *nd_act); //elimina nodo sin hijos
	void eliminar_unhijo(nodoBB<Clave> *pad, nodoBB<Clave> *nd_act); //elimina nodo con un solo hijo
	void eliminar_doshijos(nodoBB<Clave> *pad, nodoBB<Clave> *nd_act); //elimina nodo con dos hijos

	void niveles1(nodoBB<Clave>* nodo, int nivel); //muestra el árbol en vertical
	void niveles1_hijos(nodoBB<Clave>* nodo, int nivel);
	void niveles2(nodoBB<Clave>* nodo, int nivel); //muestra el árbol en horizontal

};
