#include <iostream>
#include <conio.h>
#include "DataFrame.h"

using namespace std;

int main() {

	CDataFrame * df = new CDataFrame();
	vector<string> nombres;

	nombres.push_back("Region");
	nombres.push_back("Item Type");


	df->ImportarDatos("Pruebas7.txt");

	CDataFrame * dfOrd;
	dfOrd = df->OrdenarDataFrame("Region");

	dfOrd->ImprimirDataFrame();
	
	system("pause");
	return 0;
}