/*
 * arbol.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#include "arbol.hpp"

template <class Clave>
ABB<Clave>::ABB():
	raiz(NULL){}

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
int ABB<Clave>::insertar(nodoBB<Clave>* aux, nodoBB<Clave>* nodo, int modo){
	int contador = 0;

	if(raiz == NULL){ //añade dato en la raíz si no lo tiene
		raiz = new nodoBB<Clave>;
		raiz->dato = aux->dato;
		raiz->hijoizq = NULL;
		raiz->hijodch = NULL;

		if(modo == 1)
			cout << "Raíz Añadida" << endl << endl;
		contador++;
		return 0;
	}

	if(nodo->dato == aux->dato){
		if(modo == 1)
			cout << "El Elemento ya Existe" << endl << endl;
		contador++;
		return 0;
	}

	if(nodo->dato > aux->dato){ //inserta a la izquierda si el dato introducido es menor que el encontrado
		contador++;
		if(nodo->hijoizq != NULL){
			insertar(aux, nodo->hijoizq, modo);
			contador++;
		}
		else{
			nodo->hijoizq = aux;
			(nodo->hijoizq)->hijoizq = NULL;
			(nodo->hijoizq)->hijodch = NULL;

			if(modo == 1)
				cout << "Elemento Añadido a la Izquierda" << endl << endl;
			contador++;
			return 0;
		}
	}
	else{ //inserta a la derecha si el dato introducido es mayor que el encontrado
		contador++;
		if(nodo->hijodch != NULL){
			insertar(aux, nodo->hijodch, modo);
			contador++;
		}
		else{
			nodo->hijodch = aux;
			(nodo->hijodch)->hijoizq = NULL;
			(nodo->hijodch)->hijodch = NULL;

			if(modo == 1)
				cout << "Elemento Añadido a la Derecha" << endl << endl;
			contador++;
			return 0;
		}
	}
	return contador;
}

template <class Clave>
int ABB<Clave>::buscar(Clave X, nodoBB<Clave> **padre, nodoBB<Clave> **nodo_actual, int modo){
	nodoBB<Clave> *aux1, *aux2;
	int contador = 0;

	if(raiz == NULL){
		*nodo_actual = NULL;
		*padre = NULL;
		contador++;

		if(modo == 1)
			return 0;
	}

	if(X == raiz->dato){
		*nodo_actual = raiz;
		*padre = NULL;
		contador++;

		if(modo == 1)
			return 0;
	}

	if(X < raiz->dato){
		aux1 = raiz->hijoizq;
		contador++;
	}
	else{
		aux1 = raiz->hijodch;
		contador++;
	}

	aux2 = raiz;

	while (aux1 != NULL){
		if(X == aux1->dato){
			*nodo_actual = aux1;
			*padre = aux2;
			contador++;

			if(modo == 1)
				return 0;
		}
		aux2 = aux1;

		if(X < aux1->dato){
			aux1 = aux1->hijoizq;
			contador++;
		}
		else{
			aux1 = aux1->hijodch;
			contador++;
		}
	}
	*nodo_actual = NULL;
	*padre = aux2;

	return contador;
}

template <class Clave>
void ABB<Clave>::eliminar(Clave X){

	nodoBB<Clave> *padre, *nodo_actual;

    if(raiz == NULL){
        cout << "¡Árbol Vacío!" << endl;
        return;
    }

    buscar(X, &padre, &nodo_actual, 1);

    if(nodo_actual == NULL){
        cout << "El Elemento no está en el Árbol" << endl << endl;
        return;
    }

    if((nodo_actual->hijoizq == NULL) && (nodo_actual->hijodch == NULL)){
    	eliminar_final(padre, nodo_actual);
    }

    if(((nodo_actual->hijoizq != NULL) && (nodo_actual->hijodch == NULL)) || ((nodo_actual->hijoizq == NULL) && (nodo_actual->hijodch != NULL))){
    	eliminar_unhijo(padre, nodo_actual);
    }

    if((nodo_actual->hijoizq != NULL) && (nodo_actual->hijodch != NULL)){
    	eliminar_doshijos(padre, nodo_actual);
    }
}

template <class Clave>
void ABB<Clave>::eliminar_final(nodoBB<Clave> *pad, nodoBB<Clave> *nd_act){
	if(pad == NULL){
		raiz = NULL;
	}
	else{
		if(nd_act == pad->hijoizq)
			pad->hijoizq = NULL;
		else
			pad->hijodch = NULL;
	}
}

template <class Clave>
void ABB<Clave>::eliminar_unhijo(nodoBB<Clave> *pad, nodoBB<Clave> *nd_act){
	nodoBB<Clave> *hijo;

	if(nd_act->hijoizq != NULL)
		hijo = nd_act->hijoizq;
	else
		hijo = nd_act->hijodch;

	if(pad == NULL){
		raiz = hijo;
	}
	else{
		if(nd_act == pad->hijoizq)
			pad->hijoizq = hijo;
		else
			pad->hijodch = hijo;
	}
}

template <class Clave>
void ABB<Clave>::eliminar_doshijos(nodoBB<Clave> *pad, nodoBB<Clave> *nd_act){

	nodoBB<Clave> *aux1, *aux2, *sucesor1, *sucesor2;
	aux2 = nd_act;
	aux1 = nd_act->hijoizq;

	while(aux1->hijoizq != NULL){
		aux2 = aux1;
		aux1 = aux1->hijoizq;
	}

	sucesor1 = aux1;
	sucesor2 = aux2;

	if(sucesor1->hijoizq == NULL && sucesor1->hijodch == NULL)
		eliminar_final(sucesor2, sucesor1);
	else
		eliminar_unhijo(sucesor2, sucesor1);

	if(pad == NULL){
		raiz = sucesor1;
	}
	else{
		if(nd_act == pad->hijoizq)
			pad->hijoizq = sucesor1;
		else
			pad->hijodch = sucesor1;
	}
	sucesor1->hijoizq = nd_act->hijoizq;
	sucesor1->hijodch = nd_act->hijodch;
}

template <class Clave>
void ABB<Clave>::niveles1(nodoBB<Clave>* nodo, int nivel){
	if(nodo != NULL){ //si el nodo tiene contenido
		if(nodo == raiz){ //Si el nodo es igual a la raiz, la muestra junto con sus hijos
			cout << "Nivel " << nivel << ": [" << nodo->dato << "]" << endl;
			niveles1_hijos(nodo, nivel);
		}
		else
			niveles1_hijos(nodo, nivel);

		niveles1(nodo->hijoizq, nivel + 1);
		niveles1(nodo->hijodch, nivel + 1);
	}
	if(raiz == NULL)
		cout << endl << "Árbol Vacío:" << endl << endl << "Nivel 0: [.]" << endl << endl;
}

template <class Clave>
void ABB<Clave>::niveles1_hijos(nodoBB<Clave>* nodo, int nivel){
	if((nodo->hijoizq == NULL) && (nodo->hijodch == NULL)){
		cout << "Nivel " << nivel + 1 << ": [.] [.]";
	}
	if((nodo->hijoizq != NULL) && (nodo->hijodch == NULL)){
		cout << "Nivel " << nivel + 1 << ": [" << (nodo->hijoizq)->dato << "] [.]";
	}
	if((nodo->hijoizq == NULL) && (nodo->hijodch != NULL)){
		cout << "Nivel " << nivel + 1 << ": [.] [" << (nodo->hijodch)->dato << "]";
	}
	if((nodo->hijoizq != NULL) && (nodo->hijodch != NULL)){
		cout << "Nivel " << nivel + 1 << ": [" << (nodo->hijoizq)->dato << "] [" << (nodo->hijodch)->dato << "]";
	}
	cout << endl;
}

template <class Clave>
void ABB<Clave>::niveles2(nodoBB<Clave>* nodo, int nivel){
	if(nodo != NULL){
		niveles2(nodo->hijodch, nivel + 1);
		cout << endl;

		if(nodo == raiz)
			cout << "Raiz: ";
		else{
			for(int i = 0; i < nivel; i++)
				cout << "       ";
		}
		cout << "[" << nodo->dato << "]";
		niveles2(nodo->hijoizq, nivel + 1);
	}
	if(raiz == NULL)
		cout << endl << "Árbol Vacío:" << endl << endl << "Nivel 0: [.]" << endl << endl;
}

template class ABB<class DNI>;
