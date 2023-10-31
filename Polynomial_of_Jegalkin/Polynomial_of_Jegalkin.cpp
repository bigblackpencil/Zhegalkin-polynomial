//0 0 0 1 0 1 1 1
// 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 0
#include <iostream> 

void printBinary(int num, int count) 
{
	int* PlnmlNmbr = new int[count];
	int zeroCounter = 0;

	for (int i = count - 1, j = 0; i >= 0, j < count; --i, j++) {
		int bit = (num >> i) & 1; // Используем сдвиг и побитовое И, чтобы получить очередной бит
		PlnmlNmbr[j] = bit;
		std::cout << PlnmlNmbr[j] << ' ';
	}

	for (int i = 0; i < count; i++)
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

int main()
{
	int size;

	std::cin >> size;
	
	int newsize = size;
	int countOfVariables = log2(size);
	int* BoolFunc = new int[size];
	int* RsltTrnglPscl = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> BoolFunc[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		RsltTrnglPscl[i] = BoolFunc[0];
		newsize--;
		for (int i = 0; i < newsize; i++)
		{
			BoolFunc[i] = (BoolFunc[i] + BoolFunc[i + 1]) % 2;
			std::cout << BoolFunc[i] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << '\n';

	for (int i = 0; i < size; i++)
	{
		std::cout <<  RsltTrnglPscl[i] << ' ';
	}

	std::cout << '\n';


	for (int i = 0; i < size; i++)
	{
		if (1 == RsltTrnglPscl[i])
		{
			printBinary(i, countOfVariables);
			std::cout << "\n\n";
		}
	}

	delete[] BoolFunc;
	delete[] RsltTrnglPscl;

	return 0;
}