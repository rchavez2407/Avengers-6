#pragma once

#include <vector>

using namespace std;

class CColumna {

private:

	string nombre;// las columnas pueden tener diferentes nonmbres como "NOMBRE", "EDAD" , "DNI"
	vector<string>datos;//cada columna debere tener un vector de datos del mismo tipo para NOMBRE serian strings , para EDAD seria int , para DNI seria string

public:

	CColumna(){}
	~CColumna(){}

};