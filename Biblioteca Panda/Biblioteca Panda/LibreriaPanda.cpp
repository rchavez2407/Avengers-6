#include <iostream>
#include <conio.h>
#include "DataFrame.h"

using namespace std;

//MENU DE PRUEBA
void Imprimir()
{
	cout << "PRUEBA" << endl;
}




int main()
{

	//CDataFrame * dataFrame;
	//dataFrame = new CDataFrame(5,3);



	int n;
	do
	{
		system("cls");
		cout << "\t\tMenu" << endl;
		cout << "\t\t---------" << endl << endl;
		cout << "1. Cargar Archivo " << endl;
		cout << "2. Crear Nuevo DataFrame" << endl;
		cout << "3. Imprimir" << endl;
		cout << "4. Listar los Data frames" << endl;
		cout << "5. Guardar DataFrame" << endl;
		cout << "6. Indexar" << endl;
		cout << "7.Salir" << endl;
		cout << endl << "Ingrese una opcion: "; cin >> n;


		switch (n)
		{
		case 1:
		{
			int sep;
			cout << "Ingrese el separador"; cin >> sep;
		}break;
		case 2:
		{
			int data;
			int filtro;
			int select;
			int orden;
			bool k;
			cout << "Desea crear el DataFrame desde cero (1.Si  0.No)? "; cin >> k;

			if (k == true)
			{
				cout << "Crear desde otro DataFrame" << endl << endl;
				cout << "cual DataFrame desea escoger: " << endl; cin >> data;
				cout << "Desea filtrar el DataFrame?: " << endl; cin >> filtro;
				cout << "Desea Seleccionar el DataFrame?: " << endl; cin >> select;
				cout << "Desea ordenar el DataFrame?: " << endl; cin >> orden;
				if (data == 1)
				{
					Imprimir();
				}
				system("pause");
				cout << endl << endl;
			}
		}break;
		case 3:
		{
			cout << "Imprimiendo..." << endl;
		}break;
		case 4:
		{
			cout << "Listando..." << endl;
		}break;
		case 5:
		{
			int guardar;
			int sep;
			cout << "Cual DataFrame desea guardar? "; cin >> guardar;
			cout << "Ingrese el separador para el DataFrame: "; cin >> sep;
		}break;
		case 6:
		{

			int data;
			int fila, columna;
			cout << "Cual DataFrame desea indexar?: "; cin >> data;
			cout << "Ingrese la fila y columna a indexar: "; cin >> fila; cin >> columna;
		}

		}





	} while (n >= 1 && n <= 6);

	return 0;
}