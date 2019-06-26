#pragma once
#include "Columna.h"
#include "Fila.h"
#include <map>

typedef map<string, CColumna *> colmap;

class CDataFrame {

private:

	vector<CFila *> fil;//manera de insertar filas
	colmap col;//manera de insertar columnas
	//Primero se llenan columnas y despues las filas

public:
	CDataFrame() {

	}
	~CDataFrame(){}

	//Metodos del DataFrame

	void ImportarDatos(){}
	void CrearDataFrame(){}
	void ImprimirDataFrame(){}
	void IndexarDataFrame(){}
	CDataFrame *SeleccionarDataFrame(vector<string> ColSeleccion){
	
		CDataFrame * selDF = new CDataFrame();

		for (string c : ColSeleccion) {

			(selDF->col)[c] = (this->col)[c];

		}
		 
		selDF->fil = this->fil;

		return selDF;
	
	}//listo
	CDataFrame *FiltrarDataFrame(string n){}
	CDataFrame *OrdenarDataFrame(string n){}
	void ExportarDataFrame(){}

};