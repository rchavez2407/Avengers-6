#pragma once
#include "fila.h"
#include "Columna.h"

template<typename T>
class DataFrame3 {

	CFila * fil;
	CColumna<T> * col;
public:
	void AccederColumna() {}
	void SetValor() {}
};