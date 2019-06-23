#pragma once
#include "vector"
#include "Columna.h"
#include <map>


using namespace std;

typedef map<string, CColumna*> colmap;

class CFila {

private:

	int indice;
	colmap * cols;

public:

	CFila(colmap * cols):cols(cols){}
	~CFila(){}

	string getData(string name) {

		return (*cols)[name][indice];

	}

	
};