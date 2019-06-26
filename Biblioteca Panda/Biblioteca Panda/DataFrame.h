#pragma once
#include "Columna.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Fila.h"
#include <map>

typedef map<string, CColumna *> colmap;

class CDataFrame {

private:

	vector<CFila *> fil;//manera de insertar filas
	colmap col;//manera de insertar columnas
	//Primero se llenan columnas y despues las filas


private:
	//Datos para importar
	ofstream writteFile;
	ifstream readFile;


public:
	CDataFrame() {
	}
	~CDataFrame(){}

	//Metodos del DataFrame

	void ImportarDatos(string nombreArchivo){

		if (fil.size() == 0 && col.size() == 0) {

			string rescate;
			CColumna * c = new CColumna(rescate);
			
			readFile.open(nombreArchivo);
			col[rescate] = c;

		}
	


	}
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