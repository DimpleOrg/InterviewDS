//	1	2	3
//	4	5	6

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//int countPaths(char mat[][4], int r, int c, int row, int col, int& path);
//
//int row = 3, col = 4;
//
//void PrintAllPaths(int r, int c, string path)
//{
//	
//	if (r == row - 1)
//	{
//		for (int i = c; i < col; i++)
//		{
//			path = path + "(" + std::to_string(r) + "," + std::to_string(i) + ")->";
//		}
//		cout << path << endl;
//		return;
//	}
//
//	if (c == col - 1)
//	{
//		for (int i = r; i < row; i++)
//		{
//			path = path + "(" + std::to_string(i) + "," + std::to_string(c) + ")->";
//		}
//		cout << path << endl;
//		return;
//	}
//
//	path = path + "(" + std::to_string(r) + "," + std::to_string(c) + ")->";
//
//	PrintAllPaths(r + 1, c, path);
//	PrintAllPaths(r, c + 1, path);
//}
//
//
//int main()
//{
//	std::cout << "Hello World!\n";
//	PrintAllPaths(0, 0, "");
//}
void printAllPaths(char mat[][4], int r, int c, int row, int col, std::vector<char>& path)
{
	/*cout << "\nmat[r][c]:	" << mat[r][c] << "\tr: " << r << "\tc: " << c;
	cout << "\tpath:	";
	for (auto each : path)
		cout << each;
	cout << endl;*/

	if (r == (row-1))
	{
		for (int i = c; i < col; i++)
		{
			path.push_back(mat[r][i]);
		}
		
		for (auto each : path)
			cout << each;
		cout << endl;
		
		for (int i = c; i < col; i++)
		{
			path.pop_back();
		}
			
		return;
	}
	if (c == (col - 1))
	{
		for (int i = r; i < row; i++)
		{
			path.push_back(mat[i][c]);
		}

		for (auto each : path)
			cout << each;
		cout << endl;
		
		for (int i = r; i < row; i++)
		{
			path.pop_back();
		}
		return;
	}
	
	path.push_back(mat[r][c]);

	printAllPaths(mat, r + 1, c, row, col, path);
	printAllPaths(mat, r, c + 1, row, col, path);

	path.pop_back();
}

int countPaths(char mat[][4], int r, int c, int row, int col, int& path)
{
	if (r == (row - 1))
	{
		path++;
		return path;
	}
	if (c == (col - 1))
	{
		path++;
		return path;
	}

	countPaths(mat, r + 1, c, row, col, path);
	countPaths(mat, r, c + 1, row, col, path);
}

int main()
{
	char mat[4][4] = { 'a','b','c','d',
	'e','f','g','h',
	'i','j','k','l',
	'm','n','o','p'};
	std::vector<char> vec;
	printAllPaths(mat, 0, 0, 4, 4, vec);
	int numberofpaths = 0;
	std::cout<<"\n"<<countPaths(mat, 0, 0, 4, 4, numberofpaths);
}


