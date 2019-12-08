
#include <stdexcept>
#include <iostream>
#include <algorithm> // подключаем STL для shuffle
using namespace std;
#define endk (cout << endl)
#define endh (cout << "--------------------------------------------------------------------------" << endl)
/*
В массиве K с индексами от 0 до 9, заданном начальными значениями,
содержатся разные числа от 0 до 9 в произвольном порядке.
Требуется поместить в массив Y зашифрованную произвольную 
последовательность X длины L≤30 из целых чисел от 0 до 9. 
Шифрование выполнить по следующему правилу : Yi = i - Kxi.
Затем по данным из Y расшифровать последовательность и поместить в массив P.
Использовать дополнительный массив T с начальными значениями, заданными следующим образом :
Ti  равно номеру ячейки массива K со значением i.
Следует реализовать ввод исходного массива, вывод требуемого массива и подпрограмму
реализации работы с массивом в отдельных функциях, которые должны вызываться в функции main().
Выделение памяти под массив производится динамически
*/

void arrK(int *arrK, const int size);
void arrKRandom(int *arrK, const int size);
void arrT(int *arrK, int *arrT, int size);
void arrXY(int *arrX, int *arrY, int size, int *arrK);
void arrP(int *arrP, int sizeL, int * arrT, int *arrY);

int main()
{endh;
	const int size = 10;
	const int sizeL = 30;
	int *K = new int[size];
	int *T = new int[size];
	int *Y = new int[sizeL];
	int *X = new int[sizeL];
	int *P = new int[sizeL];

	arrK(K, size); // проинициализировали массив K
	
	arrKRandom(K, size); //перемешали  массив K

	arrT(K,T, size); // проинициализировали массив T

	arrXY(X, Y, sizeL, K); //создаем X рандом и шифуем по формуле Y[i] = i - K[X[i]]
		
	arrP(P, sizeL, T, Y);// дешифруем и выдаем оригинал
	
		delete[] K;
		delete[] T;
		delete[] X;
		delete[] Y;
		delete[] P;

	//	cin.get();
	return 0;
	}

void arrK(int *arrK, const int size)
{
	cout << "entered K elements: " << endl;
	int numArr=0;
	
	for (int i = 0; i < size; i++)// заполняем массив К
	{
		cin >> numArr;
		//arrK[size] = numArr;
		arrK[i] = numArr;
			
	}
	for (int i = 0; i < size; i++)// заполняем массив К
	{

		cout << arrK[i] << "\t";
	}
	endk;
	endh;
}
void arrKRandom(int *arrK, const int size)
{
	random_shuffle(arrK, arrK + size); // перемешиваем элементы массива K
	cout << "K  random: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrK[i] << "\t";
	}
	endk;
	endh;
}
void arrT(int *arrK, int *arrT, int size)
{
	for (int i = 0; i < size; i++) {
		arrT[arrK[i]] = i;
	}
	cout << "T elements: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arrT[i] << '\t';
	}
	endk;
	endh;
}
void arrXY(int *arrX, int *arrY, int size, int *arrK)
{
	cout << "X elements : " << endl;

	for (int i = 0; i < size; i++)
	{
		arrX[i] = rand() % 10;
		cout << arrX[i] << "\t";
	}
	endk;
	endh;
	cout << "Y elements to Y[i] = i - K[X[i]]: " << endl;
	for (int i = 0; i < size; i++)
	{
		arrY[i] = i - arrK[arrX[i]];
		cout << arrY[i] << "\t";

	}
	endk;
	endh;
}
void arrP(int *arrP, int sizeL, int *arrT, int *arrY)
{
	cout << "P: deshifrate " << endl;
	for (int i = 0; i < sizeL; i++)
	{
		arrP[i] = arrT[i - arrY[i]];
		cout << arrP[i] << "\t";
	}
	endk;
	endh;
}
