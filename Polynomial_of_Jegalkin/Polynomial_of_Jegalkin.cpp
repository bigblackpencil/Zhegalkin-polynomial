#include <iostream> 
#include <fstream>
#include <string>
#include "Functions.h"



int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	std::cout << "Введите размерность вектора N булевой функции. Помните количество переменых должно быть равно log2(N): " << '\n';
	std::cin >> size;
	
	int newsize = size;
	int countOfVariables = log2(size);

	if (countOfVariables != log2(size))
	{
		std::cout << "Неверный размер ветора булевой функции!\n";
		exit(0);
	}

	int* BoolFunc = new int[size];
	int* RsltTrnglPscl = new int[size];

	ReadingFileOutputResults(BoolFunc, RsltTrnglPscl, size, countOfVariables);
	
	delete[] BoolFunc;
	delete[] RsltTrnglPscl;

	std::cout << "\n\n";

	return 0;
}