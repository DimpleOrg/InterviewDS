#include "Insertion.h"

int bitInsertion(int n, int m, int const i, int const j)
{
	std::cout << "n : \n";
	printBinary(n);
	
	std::cout << "\nm : \n";
	printBinary(m);
	
	std::cout << "\ni : " << i << "\tj : " << j;
	int mask = clearBits( i, j);
	
	printBinary(mask);
	std::cout << "\n";
	
	n = n & mask;
	
	printBinary(n);
	std::cout << "\n";
	
	m = m << i;
	
	printBinary(m);
	std::cout << "\n";
	
	n = n | m;
	
	printBinary(n);
	std::cout << "\n";
	
	return n;
}

int clearBits( int const i, int const j)
{
	unsigned int left = ~0, right = ~0;

	std::cout << "\n left before shift : \n";
	printBinary(left);

	left = left << (j + 1);
	
	std::cout << "\n left after shift : \n";
	printBinary(left);
	
	std::cout << "\n right before shift : \n";
	printBinary(right);
	
	std::cout << "\nshifting right by : " << 32 - j - 1 << "\n";

	right = right >> (32 - i);
	
	std::cout << "right after shift : \n";
	printBinary(right);
	
	return left | right;
}

void printBinary(unsigned int num)
{
	if (num == 1)
	{
		std::cout << 1;
		return;
	}
	if (num == 0)
	{
		std::cout << 0;
		return;
	}
	printBinary(num / 2);
	std::cout << num % 2;
}