#pragma once
#include "Columna.h"
#include "Fila.h"




class CDataFrame {

private:

	vector<CFila *> fil;
	vector<CColumna*> col;

public:
	CDataFrame() {
		/*
		col[0] = new CColumna<int>;//una columna de enteros
		col[1] = new CColumna<string>;//una columna de strings */
		//.............
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