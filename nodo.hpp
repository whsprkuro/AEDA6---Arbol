/*
 * nodo.hpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#pragma once

#include <iostream>

#include "dni.hpp"

using namespace std;

template <class Clave>

class nodoBB{

public:
	Clave dato;
	nodoBB<Clave>* hijoizq;//izquierdo
	nodoBB<Clave>* hijodch;//derecho

public:
	nodoBB(Clave X);
	nodoBB(const nodoBB<Clave>&);
	~nodoBB();

	void mostrarNodo();

};
