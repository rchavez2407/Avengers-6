#include <iostream>
#include <conio.h>
#include "DataFrame.h"

using namespace std;

int main() {

	CDataFrame * df = new CDataFrame();
	vector<string> nombres;

	nombres.push_back("Region");
	nombres.push_back("Item Type");


	df->ImportarDatos("1000Datos.txt");

	CDataFrame * dfSel;
	dfSel = df->SeleccionarDataFrame(nombres);

	dfSel->ImprimirDataFrame();
	
	system("pause");
	return 0;
}