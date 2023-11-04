#include "Functions.h"
#include <iostream> 
#include <fstream>
#include <string>

void printBinary(int num, int count)
{
	int* PlnmlNmbr = new int[count];//memory for a number of polynomail 
	int zeroCounter = 0;

	for (int i = count - 1, j = 0; i >= 0; --i, j++)//represents the index of the promotional result vector in binary form
	{						//the correspondence between the vector index and the binary representation is made according to the truth table 
		int bit = (num >> i) & 1;
		PlnmlNmbr[j] = bit;
	}

	for (int i = 0; i < count; i++)//creates a readable view for the user
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

int* TrianglePascal(int* BoolFunc, int* Result, int size)//count Pascal's triangle
{
	int newsize = size;
	for (int i = 0; i < size; i++)//these two loops make Pascal's triangle
	{
		Result[i] = BoolFunc[0];//forming a vector of intermediate results (the leftmost “edge” of the triangle)
		newsize--;					  //using this edge, the terms of the Zhegalkin polynomial are calculated
		for (int i = 0; i < newsize; i++)
			BoolFunc[i] = (BoolFunc[i] + BoolFunc[i + 1]) % 2;
	}

	return Result;
}

void ReadingFileOutputResults(int* BoolFunc, int* RsltTrnglPscl, int size, int countOfVariables)
{
	std::ifstream readFile("BoolFunctions.txt");
	if (!readFile.is_open())
	{
		std::cerr << "Error." << std::endl;
		exit(1);
	}

	// ×òåíèå ôàéëà ïîñòðî÷íî è îáðàáîòêà
	std::string line;

	std::cout << "\n\n×ëåíû ïîëèíîìà Æåãàëêèíà, êîòîðûå xorÿòñÿ ìåæäó ñîáîé: \n\n";

	while (std::getline(readFile, line))
	{
		//skipping empty lines in the file
		if (line == "") continue;
		// skipping commas and spaces 
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
				printBinary(i, countOfVariables);//output numbers of Zhegalkin's polynomial 
				std::cout << "   ";
			}
		}
		std::cout << "\n\n";
	}

	readFile.close();
}
