#include "Insertion.h"

void printBitsOfInteger(int x)
{
	std::cout << std::endl;

	unsigned mask = 1U << 31;

	for (int i= 0; i < 32; i++)
	{
		(mask & x) == 0 ? std::cout << "0" : std::cout << "1";
		mask = mask >> 1;
	}
	std::cout << std::endl;

}

MY01INSERTIONA_API int Insert_M_into_N(int N, int M, int i, int j)
{

	static_assert (sizeof(int) == 4, "Interger Size is not 32 bit.");

	if ((i >= j) ||
		(i < 1 || i > 32)||
		(j < 1 || j > 32)
		)
	{
		throw std::exception("Invalid input.");
	}


	std::cout << "N";
	printBitsOfInteger(N);

	std::cout << "M";
	printBitsOfInteger(M);	

	unsigned mask1 = ~0;
	unsigned mask2 = ~0;
	unsigned mask3;

	mask1 = mask1 >> (32 - i);
	mask2 = mask2 << (j + 1);

	mask3 = mask1 | mask2;

	std::cout << "Zeroing mask";
	printBitsOfInteger(mask3);


	N = N & mask3;

	std::cout << "After Zeroing N range bits";
	printBitsOfInteger(N);


	M = M << i;

	std::cout << "M after shifting i places";
	printBitsOfInteger(M);

	
	N = N | M;



	std::cout << "After insertion N";
	printBitsOfInteger(N);


	return N;
}
