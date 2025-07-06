#include <iostream>
using namespace std;
class binaryGrid
{
private:
    int** grid;
    int rows;
    int cols;
    void allocateGrid(int r, int c)
    {
        grid = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            grid[i] = new int[cols];
        }
    }
public:
    binaryGrid(int r, int c)
    {
        rows = r;
        cols = c;
        allocateGrid(r, c);
    }
    binaryGrid(const binaryGrid& other)
    {
        allocateGrid(other.rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                grid[i][j] = other.grid[i][j];
            }
        }
    }
    void set(int ro, int co, int v)
    {
        if (ro >= 0 && ro < rows && co >= 0 && co < cols)
            grid[ro][co] = v;
    }
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int c = 0; c < cols; c++)
            {
                cout << grid[i][c] << " ";
            }
            cout << "\n";
        }
    }
    void entry()
    {
        int val = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                do
                {
                    cout << "\nEnter value (0 or 1) at position [" << i << "][" << j << "]: ";
                    cin >> val;
                } while (val != 0 && val != 1);
                set(i, j, val);
            }
        }
    }
    void scaleUp(int factor)
    {
        int newRows = rows * factor;
        int newCols = cols * factor;
        int** newGrid = new int* [newRows];
        for (int i = 0; i < newRows; i++)
        {
            newGrid[i] = new int[newCols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < factor; k++)
                {
                    for (int l = 0; l < factor; l++)
                    {
                        newGrid[i * factor + k][j * factor + l] = grid[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
        grid = newGrid;
        rows = newRows;
        cols = newCols;
    }
    ~binaryGrid()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
    }
};
int main()
{
    int r = 0, c = 0;
    cout << "\nEnter rows : ";
    cin >> r;
    cout << "\nEnter columns : ";
    cin >> c;
    if (r == c)
    {
        binaryGrid g(r, c);
        cout << "\n\t\tEntry of numbers in a Grid:\n";
        g.entry();
        cout << "\n\t\tDisplay of Original Grid:\n";
        g.display();
        g.scaleUp(2);
        cout << "\n\t\tDisplay of Scaled-Up Grid:\n";
        g.display();
    }
    else
    {
        cout << "\nRows and columns should be equal.\n";
    }
    return 0;
}

