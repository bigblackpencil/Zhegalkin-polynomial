#include "Functions.h"
#include <iostream> 
#include <fstream>
#include <string>

void printBinary(int num, int count)
{
	int* PlnmlNmbr = new int[count];//������ ��� ���� ��������
	int zeroCounter = 0;

	for (int i = count - 1, j = 0; i >= 0; --i, j++)//������������� ������ ������� �������������� ���������� � �������� ����
	{											   //����������� ������� ������� � ��������� ������������ ������������ �������� ������� ����������  
		int bit = (num >> i) & 1;
		PlnmlNmbr[j] = bit;
	}

	for (int i = 0; i < count; i++)//��������� ������������� ��� ��� ������������ 
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

int* TrianglePascal(int* BoolFunc, int* Result, int size)//������� ����������� �������
{
	int newsize = size;
	for (int i = 0; i < size; i++)//��� ����� ������ ����������� ������� 
	{
		Result[i] = BoolFunc[0];//������������ ������� ������������� �����������(������� ����� "�����" ������������)
		newsize--;					  //� ������� ������� ����� ����������� ����� �������� ��������� 

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

	// ������ ����� ��������� � ���������
	std::string line;

	std::cout << "\n\n����� �������� ���������, ������� xor���� ����� �����: \n\n";

	while (std::getline(readFile, line))
	{
		//���������� ������ ������, ���� ��� ��������� ������ � �����
		if (line == "") continue;
		// ���������� ������� � ������� �� ������
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
				printBinary(i, countOfVariables);//����� ������ �������� ��������� 
				std::cout << "   ";
			}
		}
		std::cout << "\n\n";
	}

	readFile.close();
}
