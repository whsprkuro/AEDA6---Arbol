/*
 * DNI.hpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mad18
 */

#pragma once

#include <sstream>
#include <iostream>
#include <string.h>		//strcpy
#include <stdlib.h>     //srand, rand, strtoul

using namespace std;

class DNI{

private:

	string numdni;
//	string nombre, dnitotal;

public:

	DNI();
	DNI(string s);
	~DNI();
	void destroy();

	bool operator ==(DNI &d);
	bool operator !=(DNI &d);
	bool operator <(DNI &d);
	bool operator >(DNI &d);
	bool operator <=(DNI &d);
	bool operator >=(DNI &d);
	friend ostream& operator<<(ostream& os, const DNI& dni);
	friend istream& operator>>(istream& is, DNI& dni);

	operator unsigned long();
	operator char*();

	string get_numDNI();
	void set_numDNI(string d);
	void mostrar();
};
