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
	vector<string> NombreColumnas; // nombre de las columnas
	colmap col;//manera de insertar columnas
	//Primero se llenan columnas y despues las filas


private:
	//Datos para importar dataframe
	ofstream writteFile;
	ifstream miArchivo;

private:

	bool ExisteColumna(string nombre) {

		for (string c : NombreColumnas) {

			if (nombre == c) { return 1; break; }

		}
		return 0;

	}
	bool EsNumero(string s) {
		int cont = 1;
		for (char e : s) {

			if (!(e >= 48 && e <= 57)) {

				return 0; break;
			}

		}
		return 1;

	}
	bool ComparaStrings(string a, string b) {
		if (EsNumero(a)) {
			int num1,num2;

			num1 = atoi(a.c_str());
			num2 = atoi(b.c_str());

			return (num2 > num1);
		}
		else {
			int numen = a.size();
			if (b.size() < numen) numen = b.size();

			for (int i = 0; i < numen; i++) {

				if (a[i] > b[i]) { return 0; break; }
				else if(a[i] < b[i]) { return 1; break; }
				else if (a[i] == b[i]) { continue; }

			}
			if (b.size() <= a.size()) return 0;
			else { return 1; }


		}
		

	}
	void CambioStrings(vector<string> & vec, int i, int min) {

		string aux = vec[i];
		vec[i] = vec[min];
		vec[min] = aux;

	}
	void CambioEnteros(vector<int> & vec, int i, int min) {

		int aux = vec[i];
		vec[i] = vec[min];
		vec[min] = aux;

	}
	////////////////////Codigos de ordenamiento
	////////////////////Codigos de ordenamiento
	////////////////////Codigos de ordenamiento
	////////////////////Codigos de ordenamiento

	int PartiotingQuick(vector<string> & vc, vector<int> & vf, int lo, int hi) {

		string pivot = vc[lo];
		int i = lo + 1; int j = hi;

		while (1) {

			while (ComparaStrings(vc[i], pivot)) { if (i == hi)  break; i++; }
			while (ComparaStrings(pivot, vc[j])) { if (j == lo)break; j--; }
			if (i >= j)break;
			CambioStrings(vc, i, j);
			CambioEnteros(vf,i,j);

		}
		CambioStrings(vc, lo, j);
		CambioEnteros(vf, lo, j);
		return j;

	}

	void QsORT(vector<string> & vc, vector<int> & vf, int lo, int hi) {

		if (lo >= hi)return;

		int j = PartiotingQuick(vc,vf, lo, hi);

		QsORT(vc, vf, lo, j - 1);
		QsORT(vc,vf, j + 1, hi);

	}

	void QuickSort(vector<string> & vc, vector<int> & vf) {

		QsORT(vc,vf, 0, vc.size()-1);

	}

	void ColumnaOrdenada(vector<int> &vf, vector<string> & Co) {

		QuickSort(Co, vf);

	}

	//////////////////////Codigos de ordenamiento
	////////////////////Codigos de ordenamiento
	////////////////////Codigos de ordenamiento
public:
	CDataFrame() {
	}
	~CDataFrame(){}

	//Metodos del DataFrame

	void ImportarDatos(string nombreArchivo){

		if (fil.size() == 0 && col.size() == 0) {

			miArchivo.open(nombreArchivo);

			string linea;
			int NumFil = 0;

			//Agregamos Columnas
			while (getline(miArchivo, linea)) {//mientras no termine una linea
				istringstream ss(linea);
				string Dato;
				int NumCol = 0;
				if (NumFil == 0) {
					string NombreCol;
					while (getline(ss, NombreCol, ',')) {
						CColumna * c = new CColumna(NombreCol);
						col[NombreCol] = c;
						NombreColumnas.push_back(NombreCol);
					}
				}
				else {
					while (getline(ss, Dato, ',')) {

						col[NombreColumnas[NumCol]]->AgregarDato(Dato);
						NumCol++;
						
					}
				}
				NumFil++;
			}

			//Agregamos Filas
			for (int i = 0; i < NumFil-1; i++) {

				CFila * f = new CFila(i,col);
				fil.push_back(f);

			}

		}
		else
			cout << "El dataFrame esta lleno";
	
	}
	void CrearDataFrame(){}
	void ImprimirDataFrame(){
	
		//impresion de nombres de columnas

		for (string n : NombreColumnas) {

			cout << n << "  ";
		}
		cout << endl;

		//Impresion de los datos

		for (CFila * f : fil) {
			for (string c:NombreColumnas) {
				
				cout << f->getData(c)<<"  ";
			}
			cout << endl;
		}
	
	}
	void IndexarDataFrame(){}
	CDataFrame *SeleccionarDataFrame(vector<string> ColSeleccion){
	
		CDataFrame * selDF = new CDataFrame();

		for (string c : ColSeleccion) {

			if (ExisteColumna(c)) {
				(selDF->NombreColumnas.push_back(c));
				(selDF->col)[c] = (this->col)[c];
			}
		}
		 
		selDF->fil = this->fil;

		return selDF;
	
	}//listo
	CDataFrame *FiltrarDataFrame(string n){}

	CDataFrame *OrdenarDataFrame(string nombreCol){
	
		if (ExisteColumna(nombreCol)) {

			CDataFrame * ordDf = new CDataFrame();
			vector<string> vo = col[nombreCol]->Getdatos();
			vector<int> vectorIndice;
			for (int i = 0; i < vectorIndice.size(); i++) {

				vectorIndice[i] = i;
			}

			ColumnaOrdenada(vectorIndice, vo);

			ordDf->NombreColumnas = this->NombreColumnas;

			for (int i = 0; i < fil.size(); i++) {

				CColumna * c = new CColumna(NombreColumnas[i]);
				(ordDf->col)[NombreColumnas[i]] = c;

				for (int j = 0; j < col.size(); j++) {

					(ordDf->col)[NombreColumnas[j]] = 

				}

			}


		}
	}
	void ExportarDataFrame(){}

};