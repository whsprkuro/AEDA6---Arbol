/*
 * arbol.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#include "arbol.hpp"

template <class Clave>
ABB<Clave>::ABB():
	raiz(0){}

template <class Clave>
ABB<Clave>::~ABB(){
	podar(raiz->hijoizq);
	podar(raiz->hijodch);

	delete raiz;
	raiz = 0;
}

template <class Clave>
void ABB<Clave>::podar(nodoBB<Clave>* nodo){
	return;
}

template <class Clave>
nodoBB<Clave>* ABB<Clave>::getraiz(){
	return raiz;
}

template <class Clave>
void ABB<Clave>::insertar(Clave& dato, nodoBB<Clave>* nodo){

	if(nodo == 0){//Caso arbol vacío
		nodo = new nodoBB<Clave>(dato);
		raiz = nodo;
		return;
	}

	if(dato < nodo->dato){//Izquierda

		if(nodo->hijoizq != 0)
			insertar(dato, nodo->hijoizq);
		else{
			nodo->hijoizq = new nodoBB<Clave>(dato);
			return;
		}
	}

	if(dato > nodo->dato){//Derecha
		if(nodo->hijodch != 0)
			insertar(dato, nodo->hijodch);
		else{
			nodo->hijodch = new nodoBB<Clave>(dato);
			return ;
		}
	}
	else//No se pueden insertar nodos iguales
		return;
}

template <class Clave>
void ABB<Clave>::preorden(nodoBB<Clave>* nodo){

	if(raiz == 0)//Si el arbol esta vacio, salimos
		return;

	cout << nodo->dato << endl;

	if(nodo->hijoizq != 0)
		preorden(nodo->hijoizq);

	if(nodo->hijodch != 0){
		preorden(nodo->hijodch);
	}
}

template <class Clave>
void ABB<Clave>::inorden(nodoBB<Clave>* nodo){

	if(raiz == 0)//Si el arbol esta vacio, salimos
		return;

	if(nodo->hijoizq != 0)
		inorden(nodo->hijoizq);

	cout << nodo->dato << endl;

	if(nodo->hijodch != 0){
		inorden(nodo->hijodch);
	}
}

template <class Clave>
void ABB<Clave>::posorden(nodoBB<Clave>* nodo){

	if (raiz == 0)//Si el arbol esta vacio, salimos
		return;

	if (nodo->hijoizq != 0)
		posorden(nodo->hijoizq);

	if (nodo->hijodch != 0){
		posorden(nodo->hijodch);
	}

	cout << nodo->dato << endl;
}

template <class Clave>
void ABB<Clave>::niveles() {

	queue<nodoBB<Clave>*> cola_nodos;

	nodoBB<Clave>* nodo = 0; // este es un puntero llevara el recorrido

	if(raiz == 0)
		return;

	cola_nodos.push(raiz);

	while(!cola_nodos.empty()){
		nodo = cola_nodos.front(); // de la cola saldran los nodos ordenados por nivel
		cola_nodos.pop();

		cout << nodo->dato << endl;//Se imprime el nodo

		if (nodo->hijoizq != 0) // si existe, ponemos el hijo izquierdo en la cola
			cola_nodos.push(nodo->hijoizq);

		if (nodo->hijodch != 0) // si existe, ponemos el hijo derecho en la cola
			cola_nodos.push(nodo->hijodch);
	}
}

template class ABB<class DNI>;
