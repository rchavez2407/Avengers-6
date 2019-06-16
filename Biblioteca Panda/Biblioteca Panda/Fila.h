#pragma once
#include "vector"

using namespace std;



class CFila {

private:

	int indice;
	
public:

	CFila(){}
	~CFila(){}


	int GetIndice() {}
	template<typename T>
	void SetValor(T valor ,string nombre , vector<T> columna) {}
	template<typename T>
	T GetValor(string nombre , vector<T> columna ){}
};