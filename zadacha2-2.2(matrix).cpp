#include <iostream>
#include <iomanip>
using namespace std;

void showArray(int **arr, const int col, const int row);
void MatArr(int **arr, int col, int row);
void transpose(int **arr, int col, int row);
void fillArr(int **arr, int col, int row);
void subRowArr(int **arr, int col, int row);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "start to create matrix...\n";
	cout << "select rows and cols...\n";
	//
	int col, row;
	cout << "col :";		cin >> col;
	cout << "row :";		cin >> row;
	//
//row m= 10; m≤10 
//col n= 12; n≤12
//A(m, n)

	cout << "...create matrix...\n";
	int **matrix = new int*[col];
	/////////////////////

	MatArr(matrix, col, row);

	cout << "...subRowArr... " << endl;

	subRowArr(matrix, col, row);
	///////////////////

	cout << "...del[col]..." << endl;
	for (int i = 0; i < col; i++)
	{
		delete[] matrix[i];
	}
	cout << "...del[row]..." << endl;
	delete[] matrix;

	system("pause");
	return 0;
}

void subRowArr(int **arr, int col, int row)
{
	cout << "...pre sorted - subRowArr... " << endl;
	showArray(arr, col, row);

	int temp, max_el, min_el;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = j; k < row; k++)
			{
				if ((arr[i][j] < arr[i][k]) && (arr[i][j] > 0))//((arr[j][i] < arr[k][i]) && (arr[j][i] < 0) && (arr[k][i] < 0))
				{
					temp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = temp;
				}
			}
		}
		min_el = temp;
		max_el = temp;

	}
	cout << "Sorted matrix: " << endl;
	showArray(arr, col, row);

	int saveMaxCOL, saveMaxROW, saveMinCOL, saveMinROW;
	saveMaxCOL = saveMaxROW = saveMinCOL = saveMinROW = 0;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (max_el < arr[i][j]) {
				max_el = arr[i][j];
				saveMaxCOL = i;
				saveMaxROW = j;
			}
			if (min_el > arr[i][j]) {
				min_el = arr[i][j];
				saveMinCOL = i;
				saveMinROW = j;
			}
		}
		cout << endl;
	}
	cout << "min_element: " << " [." << saveMinCOL << ".]" << "[." << saveMinROW << ".] " << min_el << endl;
	cout << "max_element: " << " [." << saveMaxCOL << ".]" << "[." << saveMaxROW << ".] " << max_el << endl;
	if (saveMinROW == saveMaxROW) {
		/*Если минимальный и максимальный элементы расположены в одной строке(row),
		то поменять местами столбцы(col), содержащие эти элементы.*/
		transpose(arr, col, row);
	}
	else {
		temp = arr[saveMinCOL][saveMinROW];
		arr[saveMinCOL][saveMinROW] = arr[saveMaxCOL][saveMaxROW];
		arr[saveMaxCOL][saveMaxROW] = temp;
		cout << "___ max_element <-> min_element ___" << endl;
	}

	showArray(arr, col, row);

}
void showArray(int **arr, const int col, const int row) {
	cout << "showArray " << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << " [." << i << ".]" << "[." << j << ".] " << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void MatArr(int **arr, int col, int row)
{
	cout << "MatArr " << endl;
	for (int i = 0; i < col; i++)
	{
		arr[i] = new int[row];
	}
	fillArr(arr, col, row);

}
void fillArr(int **arr, int col, int row)
{
	cout << "fillArr " << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			//arr[i][j]= rand() % 100+2;//
			cin >> arr[i][j];
		}
	}
	showArray(arr, col, row);

}
void transpose(int ** arr, int col, int row)
{
	cout << "transpose " << endl;
	int temp;
	for (int i = 0; i < col; ++i)
	{
		for (int j = i; j < row; ++j)
		{
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	showArray(arr, col, row);
}

/*
Составить программу, которая в матрице A(m,n), m≤10, n≤12, меняет местами строку,
содержащую максимальный элемент со строкой, содержащей минимальный элемент.
Предполагается, что искомые элементы единственные. Вывести исходную и преобразованную матрицы,
минимальный и максимальный элементы, а также номера строк, в которых они расположены.
Если минимальный и максимальный элементы расположены в одной строке, то поменять местами столбцы,
содержащие эти элементы. Следует реализовать ввод исходного массива, вывод требуемого массива и
подпрограмму реализации работы с массивом в отдельных функциях, которые должны вызываться в функции main().
Выделение памяти под матрицу производится динамически
*/
