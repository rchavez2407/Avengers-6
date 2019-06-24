#pragma once
#include "Columna.h"
#include "Fila.h"
#include <map>

typedef map<string, CColumna *> colmap;

class CDataFrame {

private:

	vector<CFila *> fil;
	vector<CColumna*> col;
	colmap  Ncols;

public:
	CDataFrame() {
		for (CColumna * c : col) {

			Ncols[c->GetNombre()] = c;

		}


	}
	~CDataFrame(){}

	//Metodos del DataFrame

	void ImportarDatos(){}
	void CrearDataFrame(){}
	void ImprimirDataFrame(){}
	void IndexarDataFrame(){}
	CDataFrame *SeleccionarDataFrame(int F , int C){}
	CDataFrame *FiltrarDataFrame(string n){}
	CDataFrame *OrdenarDataFrame(string n){}
	void ExportarDataFrame(){}

};