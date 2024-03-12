using namespace std;
#include <iostream>
#include <iomanip>

int **createGrid(int rows, int cols)
{
    int **ptr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr[i][j] = 1;
        }
    }
    return ptr;
}

void DisplayGrid(int **grid, int rows, int cols)
{

    int m = 1;
    for (int n = 0; n < rows; n++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[n][j] != 0)
            {
                grid[n][j] = m;
                cout << setw(4) << '|';
            }
            else
            {
                cout << setw(4) << grid[n][j];
            }
            ++m;
        }
        cout << endl;
    }
}

void movePlayer(int **grid, int &playrow, int &playcol, int rows, int cols, char direction)
{

    if (direction == 'N')
    {
        if (playrow - 1 >= 0)
        {
            --playrow;
        }
        else
        {
            cout << "Out of bounds, try again: " << endl;
            cin >> direction;
            movePlayer(grid, playrow, playcol, rows, cols, direction);
        }
    }
    else if (direction == 'S')
    {
        if (playrow + 1 < rows)
        {
            ++playrow;
        }
        else
        {
            cout << "Out of bounds, try again:" << endl;
            cin >> direction;
            movePlayer(grid, playrow, playcol, rows, cols, direction);
        }
    }
    else if (direction == 'E')
    {
        if (playcol + 1 < rows)
        {
            ++playcol;
        }
        else
        {
            cout << "Out of bounds, try again:" << endl;
            cin >> direction;
            movePlayer(grid, playrow, playcol, rows, cols, direction);
        }
    }
    else if (direction == 'W')
    {
        if (playcol - 1 >= 0)
        {
            --playcol;
        }
        else
        {
            cout << "Out of bounds, try again:" << endl;
            cin >> direction;
            movePlayer(grid, playrow, playcol, rows, cols, direction);
        }
    }
    else
    {
        cout << "Invalid direction. Try again" << endl;
        cin >> direction;
        movePlayer(grid, playrow, playcol, rows, cols, direction);
    }
}
void updateGrid(int **grid, int rows, int cols, int playrow, int playcol)
{
    int m = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = m;
            ++m;
        }
    }
    grid[playrow][playcol] = 0;
}
int main()
{
    int rows = 3, cols = 3, **gameBoard;

    cout << "Ënter rows for your grid:";
    cin >> rows;
    cout << "Ënter cols for your grid:";
    cin >> cols;

    while (rows <= 0 || cols <= 0)
    {
        cout << "Ënter valid values" << endl;
        cout << "Ënter rows for your grid:";
        cin >> rows;
        cout << "Ënter cols for your grid:";
        cin >> cols;
    }
    int playrow = 0, playcol = 0;
    gameBoard = createGrid(rows, cols);
    gameBoard[playrow][playcol] = 0;
    int choice = 1;
    char direction;

    cout << "\nDo you want to move your player, or end the game?\n";
    cout << "0.End the game\n"
         << "1.Move player\n";
    cin >> choice;
    while (choice)
    {

        DisplayGrid(gameBoard, rows, cols);

        if (choice != 0)
        {
            cout << "Enter your direction of movement [(N)orth, (E)ast, (W)est, (S)outh]: ";
            cin >> direction;
            movePlayer(gameBoard, playrow, playcol, rows, cols, direction);
            updateGrid(gameBoard, rows, cols, playrow, playcol);
        }
        else
        {
            choice = 0;
        }
    }
    return 0;
}