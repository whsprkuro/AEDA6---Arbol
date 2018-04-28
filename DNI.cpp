/*
 * DNI.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#include "DNI.hpp"

using namespace std;

DNI::DNI(){ //valor aleatorio entre 0 y 99999999
	numdni = "";
//	nombre = "";
//	dnitotal = "";

	for (int i = 0; i < 8; ++i){ //coge cada número del DNI y le da un valor aleatorio entre 0 y 9
		int n = rand() % 10;

		ostringstream convert;
		convert << n;
		numdni += convert.str();
	}

//	unsigned long dniul = strtoul(numdni.c_str(), NULL, 0); //convierto a unsigned long el DNI
//	char letra = 'A' + rand()%24; //genero letra aleatoria
//
//	unsigned long letraul = (unsigned long)letra; //convierto a unsigned long el char
//
//		letraul += dniul; //los sumo
//
//		ostringstream convert;
//		convert << letraul;
//		nombre += convert.str();
//
//		dnitotal = numdni + letra;
//
//	cout << "DNI sin suma: " << numdni << endl;
//	cout << "DNI con suma: " << nombre << endl;
//	cout << "DNI con letra: " << dnitotal << endl;
}
/*
DNI::DNI(string s){
	numdni = "";

	char *arr = new char[s.length() + 1];
	copy(s.begin(), s.end(), arr);
	arr[s.size()] = '\0';
	numdni = arr;
}
*/
DNI::~DNI(){
	destroy();
}

void DNI::destroy(){
	numdni.erase(numdni.begin(), numdni.end());
}

bool DNI::operator ==(DNI &d){
	return numdni.compare(d.get_numDNI()) == 0;
}

bool DNI::operator !=(DNI &d){
	return numdni.compare(d.get_numDNI()) != 0;
}

bool DNI::operator <(DNI &d){
	return numdni.compare(d.get_numDNI()) < 0;
}

bool DNI::operator >(DNI &d){
	return numdni.compare(d.get_numDNI()) > 0;
}

bool DNI::operator <=(DNI &d){
	return numdni.compare(d.get_numDNI()) <= 0;
}

bool DNI::operator >=(DNI &d){
	return numdni.compare(d.get_numDNI()) >= 0;
}

ostream& operator<<(ostream& os, const DNI& dni){
    return os << dni.numdni;
}

istream& operator>>(istream& is, DNI& dni){
	return is >> dni.numdni;
}

DNI::operator unsigned long(){
	return strtoul(numdni.c_str(), NULL, 0);
}

DNI::operator char*(){
	char *arr = new char[numdni.length() + 1];
	strcpy(arr, numdni.c_str());
	return arr;
}

string DNI::get_numDNI(){
	return numdni;
}

void DNI::set_numDNI(string d){
	numdni = d;
}

void DNI::mostrar(){
	cout << numdni;
}
