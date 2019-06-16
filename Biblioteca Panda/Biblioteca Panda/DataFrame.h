#pragma once
#include "Columna.h"
#include "Fila.h"



template<typename T>
class CDataFrame {

private:

	CFila * fil;
	CColumna<T> * col;

public:
	CDataFrame(int F , int C) {
	
		fil = new CFila[F];
		col = new CColumna<T>[C];
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
	CDataFrame SeleccionarDataFrame(int F , int C){}
	CDataFrame FiltrarDataFrame(string n){}
	CDataFrame OrdenarDataFrame(string n){}
	void ExportarDataFrame(){}

};