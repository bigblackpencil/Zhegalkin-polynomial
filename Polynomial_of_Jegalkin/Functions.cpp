#include "Functions.h"
#include <iostream> 
#include <fstream>
#include <string>

void printBinary(int num, int count)
{
	int* PlnmlNmbr = new int[count];//память под член полинома
	int zeroCounter = 0;

	for (int i = count - 1, j = 0; i >= 0; --i, j++)//преддставляет индекс вектора проможетучного результата в двоичном виде
	{											   //соответсвие индекса вектора и двоичного предствление производится согласно таблице истинности  
		int bit = (num >> i) & 1;
		PlnmlNmbr[j] = bit;
	}

	for (int i = 0; i < count; i++)//формирует удобочитаемый вид для пользователя 
	{
		if (PlnmlNmbr[i] == 1)
		{
			int k = i;
			k++;
			std::cout << 'x' << k;
		}
		else zeroCounter++;

		if (zeroCounter == count) std::cout << '1';
	}
}

int* TrianglePascal(int* BoolFunc, int* Result, int size)//считает труегольник паскаля
{
	int newsize = size;
	for (int i = 0; i < size; i++)//два цикла сторят труегольник паскаля 
	{
		Result[i] = BoolFunc[0];//формарование вектора промежуточных результатов(крайнее левое "ребро" треугольника)
		newsize--;					  //с помощью данного ребра вычисляются члены полинома Жегалкина 

		for (int i = 0; i < newsize; i++)
			BoolFunc[i] = (BoolFunc[i] + BoolFunc[i + 1]) % 2;
	}

	return Result;
}

void ReadingFileOutputResults(int* BoolFunc, int* RsltTrnglPscl, int size, int countOfVariables)
{
	std::ifstream readFile("E:\\C++\\Zhegalkin-polynomial\\BoolFunctions.txt");
	if (!readFile.is_open())
	{
		std::cerr << "Error." << std::endl;
		exit(1);
	}

	// Чтение файла построчно и обработка
	std::string line;

	std::cout << "\n\nЧлены полинома Жегалкина, которые xorятся между собой: \n\n";

	while (std::getline(readFile, line))
	{
		//Пропускаем пустые строки, если ими раздедены сторки в файле
		if (line == "") continue;
		// Пропускаем пробелы и запятые из строки
		for (int i = 0, j = 0; j < size; i++)
		{
			char c = line[i];

			if (c == ' ' || c == ',') continue;

			BoolFunc[j] = c - '0';
			//std::cout << BoolFunc[j] << ' ';

			j++;
		}
		RsltTrnglPscl = TrianglePascal(BoolFunc, RsltTrnglPscl, size);


		for (int i = 0; i < size; i++)
		{
			if (1 == RsltTrnglPscl[i])
			{
				printBinary(i, countOfVariables);//вывод членов полинома Жегалкина 
				std::cout << "   ";
			}
		}
		std::cout << "\n\n";
	}

	readFile.close();
}
