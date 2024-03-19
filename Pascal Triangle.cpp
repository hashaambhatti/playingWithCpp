#include <iostream>

using namespace std;

int PascalsTriangle(int rows, int cols)
{
	if (cols == 0 || cols == rows)
	{
		return 1;
	}
	return PascalsTriangle(rows - 1, cols - 1) + PascalsTriangle(rows - 1, cols);
}

int main()
{
	int row, col;
	cout << "Enter the rows no:" << endl;
	cin >> row;

	cout << "Enter the coloumn no:" << endl;
	cin >> col;

	int check = PascalsTriangle(row - 1, col - 1);

	cout << "The element is:\n"
		 << check;
	return 0;
}