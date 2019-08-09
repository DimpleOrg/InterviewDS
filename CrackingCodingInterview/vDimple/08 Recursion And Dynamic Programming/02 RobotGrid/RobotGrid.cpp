#include"RobotGrid.h"

bool isInvalidCell(int r, int c)
{
	return (invalidCells.find({ r,c }) != invalidCells.end());
}

void findPath(int r, int c, int R, int C, std::vector<point>& path, std::vector<std::vector<point>>& res)
{
	if (isInvalidCell(r, c))
		return;

	if (r > R || c > C)
		return;

	path.push_back({ r,c });

	if ((r == R) && (c == C))
		res.push_back(path);

	findPath(r, c + 1, R, C, path, res);
	findPath(r + 1, c, R, C, path, res);

	path.pop_back();
}

MY02ROBOTGRID_API std::vector<std::vector<point>> findPath(int R, int C)
{
	std::vector<point> path;
	std::vector<std::vector<point>> res;
	findPath(0, 0, R-1, C-1, path, res);
	return res;
}

MY02ROBOTGRID_API std::vector<point> findPathDP(std::vector<std::vector<int>>& matrix, int R, int C)
{
	std::vector<point> res;
	findPathDP(matrix, R-1, C-1, R-1, C-1, res);
	return res;
}

int findPathDP(std::vector<std::vector<int>>& matrix, int r, int c, int R, int C, std::vector<point>& res)
{
	std::cout << "\nStarting of function\t" << r << "," << c;

	if (r < 0 && c < 0)
		return 0;
	
	if (r == 0 && c == 0)
	{
		res.push_back({ 0,0 });
		return 1;
	}
	
	if (matrix[r][c] > -1)
		return matrix[r][c];

	std::cout << "\nprocessing r,c\t" << r << "," << c;

	if (r > 0)
	{
		int x = findPathDP(matrix, r - 1, c, R, C, res);
		
		if (x == 0 || x == 1)
			matrix[r][c] = x;

		if (x == 1)
		{
			res.push_back({ r, c });
			return 1;
		}
	}

	if (c > 0)
	{
		//std::cout << "\nr, c-1\t" << r << "," << c-1;
		int y = findPathDP(matrix, r, c-1, R, C, res);
		
		if (y == 0 || y == 1)
			matrix[r][c] = y;

		if (y == 1)
		{
			res.push_back({ r, c });
			return 1;
		}
	}
}