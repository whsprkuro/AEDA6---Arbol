/*
 * nodo.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#include "nodo.hpp"

template <class Clave>
nodoBB<Clave>::nodoBB(Clave X):
	dato(X), hijoizq(NULL), hijodch(NULL){}

template <class Clave>
nodoBB<Clave>::nodoBB(const nodoBB<Clave> &Obj):
dato(Obj.dato), hijoizq(Obj.hijoizq), hijodch(Obj.hijodch){
//	this->dato = Obj.dato;
//	this->hijoizq = Obj.hijoizq;
//	this->hijodch = Obj.hijodch;
}

template <class Clave>
nodoBB<Clave>::~nodoBB(){}

template <class Clave>
void nodoBB<Clave>::mostrarNodo(){
	cout << "|" << dato << "|";
}

template class nodoBB<class DNI>;
