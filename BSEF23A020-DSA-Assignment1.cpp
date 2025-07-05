//#include<iostream>
//using namespace std;
//class BinaryGrid
//{
//private:
//	int** grid;
//	int rows;
//	int cols;
//	void allocateGrid(int r, int c)
//	{
//		rows = r;
//		cols = c;
//		grid = new int* [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			grid[i] = new int[cols];
//		}
//	}
//public:
//	BinaryGrid(int r, int c)
//	{
//		allocateGrid(r, c);
//	}
//	BinaryGrid(const BinaryGrid& other)
//	{
//		allocateGrid(other.rows, other.cols);
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				grid[i][j] = other.grid[i][j];
//			}
//		}
//	}
//	~BinaryGrid()
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			delete[]grid[i];
//			grid[i] = nullptr;
//		}
//		delete[]grid;
//		grid = nullptr;
//	}
//	void set(int ro, int co, int val)
//	{
//		grid[ro][co] = val;
//	}
//	void display() const
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				cout << grid[i][j] << " ";
//			}
//			cout << "\n";
//		}
//	}
//	void scaleUp(int factor)
//	{
//		int newRows = rows * factor;
//		int newCols = cols * factor;
//		int** newGrid = new int* [newRows];
//		for (int i = 0; i < newRows; i++)
//		{
//			newGrid[i] = new int[newCols];
//		}
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				for (int x = 0; x < factor; x++)
//				{
//					for (int y = 0; y < factor; y++)
//					{
//						newGrid[i * factor + x][j * factor + y] = grid[i][j];
//					}
//				}
//			}
//		}
//		for (int i = 0; i < rows; i++)
//		{
//			delete[]grid[i];
//			grid[i] = nullptr;
//		}
//		delete grid;
//		grid = nullptr;
//		grid = newGrid;
//		rows = newRows;
//		cols = newCols;
//	}
//	void scaleDown(int factor)
//	{
//		int c1 = 0, c0 = 0, val = 0;
//		int newRows = rows / factor;
//		int newCols = cols / factor;
//		int** newGrid = new int* [newRows];
//		for (int i = 0; i < newRows; i++)
//		{
//			newGrid[i] = new int[cols];
//		}
//		for (int i = 0; i < newRows; i++)
//		{
//			for (int j = 0; j < newCols; j++)
//			{
//				for (int x = 0; x < factor; x++)
//				{
//					for (int y = 0; y < factor; y++)
//					{
//						val = grid[i * factor + x][j * factor + y];
//						if (val == 1)
//							c1++;
//						else
//							c0++;
//					}
//				}
//				if (c0 > c1)
//				{
//					newGrid[i][j] = 0;
//				}
//				else
//				{
//					newGrid[i][j] = 1;
//				}
//			}
//		}
//		for (int i = 0; i < rows; i++)
//		{
//			delete[]grid[i];
//			grid[i] = nullptr;
//		}
//		delete[] grid;
//		grid = nullptr;
//		grid = newGrid;
//		rows = newRows;
//		cols = newCols;
//	}
//	static BinaryGrid combine(const BinaryGrid& g1, const BinaryGrid& g2)
//	{
//		BinaryGrid result(g1.rows,g1.cols);
//		for (int i = 0; i < g1.rows; i++)
//		{
//			for (int j = 0; j < g1.cols; j++)
//			{
//				if (g1.grid[i][j] && g2.grid[i][j] == 0)
//				{
//					result.grid[i][j] = 0;
//				}
//				else
//				{
//					result.grid[i][j] = 1;
//				}
//			}
//		}
//		return result;
//	}
//	BinaryGrid** divideBlocks(int blockRows,int blockCols)
//	{
//		int nBlockRow = (rows + blockRows - 1) / blockRows;
//		int nBlockCol = (cols + blockCols - 1) / blockCols;
//		BinaryGrid** blocks = new BinaryGrid * [nBlockRow * nBlockCol];
//		int blockIndex = 0;
//		for (int i = 0; i < rows; i += blockRows)
//		{
//			for (int j = 0; j < cols; j += blockCols)
//			{
//				int cRows = min(blockRows, rows - i);
//				int cCols = min(blockCols, cols - j);
//				blocks[blockIndex] = new BinaryGrid(cRows,cCols);
//				for (int x = 0; x < cRows; x++)
//				{
//					for (int y = 0; y < cCols; y++)
//					{
//						blocks[blockIndex]->set(x, y, grid[i + x][j + y]);
//					}
//				}
//				blockIndex++;
//			}
//		}
//		return blocks;
//	}
//	int getRows() const
//	{
//		return rows;
//	}
//	int getCols() const
//	{
//		return cols;
//	}
//};
//int main()
//{
//	BinaryGrid grid1(3, 3);
//	int arr1[3][3] = { 1,0,1,0,1,0,1,0,1 };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			grid1.set(i, j, arr1[i][j]);
//		}
//	}
//	cout << "\n\t\t\t\t\tDisplay of G1 : \n";
//	grid1.display();
//	grid1.scaleUp(2);
//	cout << "\n\t\t\t\t\tDisplay of G1 after scaleup : \n";
//	grid1.display();
//	BinaryGrid grid2(4, 4);
//	int arr2[4][4] = { 1,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1 };
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			grid2.set(i, j, arr2[i][j]);
//		}
//	}
//	cout << "\n\t\t\t\t\tDisplay of G2 : \n";
//	grid2.display();
//	grid2.scaleDown(2);
//	cout << "\n\t\t\t\t\tDisplay of G2 after scaleup : \n";
//	grid2.display();
//	BinaryGrid alpha(3,3),beta(3,3);
//	int arr3[3][3] = {1,0,1,0,1,0,1,0,1};
//	int arr4[3][3] = {0,1,1,1,0,0,1,1,0};
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			alpha.set(i, j, arr3[i][j]);
//			beta.set(i, j, arr4[i][j]);
//		}
//	}
//	cout << "\n\t\t\t\t\tDisplay of a : \n";
//	alpha.display();
//	cout << "\n\t\t\t\t\tDisplay of b : \n";
//	beta.display();
//	BinaryGrid combined = BinaryGrid::combine(alpha, beta);
//	cout << "\n\t\t\t\t\tDisplay of Combined BinaryGrid : \n";
//	combined.display();
//	BinaryGrid** blocks = alpha.divideBlocks(3, 1);
//	cout << "\n\t\t\t\t\tDisplay of Block : \n";
//	for (int i = 0; i < 3; i++)
//	{
//		blocks[i]->display();
//		cout << "\n";
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		delete blocks[i];
//	}
//	delete[]blocks;
//	blocks = nullptr;
//	return 0;
//}