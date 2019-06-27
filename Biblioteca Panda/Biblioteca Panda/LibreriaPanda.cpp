#include <iostream>
#include <conio.h>
#include "DataFrame.h"

using namespace std;

int main() {

	CDataFrame * df = new CDataFrame();
	vector<string> nombres;

	nombres.push_back("Region");
	nombres.push_back("Item Type");


	df->ImportarDatos("Prueba.txt");

	CDataFrame * dfOrd;
	dfOrd = df->OrdenarDataFrame("Item Type");

	dfOrd->ImprimirDataFrame();
	
	system("pause");
	return 0;
}