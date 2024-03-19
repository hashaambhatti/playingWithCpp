#include <iostream>
using namespace std;

void printCols(int nSpc)
{
    if (nSpc > 0)
    {
        cout << "*";
        printCols(nSpc - 1);
    }
}

void printCols2(int nSpc)
{
    if (nSpc > 0)
    {
        printCols2(nSpc - 1);
        cout << "*";
    }
}

void printSpace(int nCols)
{
    if (nCols > 0)
    {
        cout << "  ";
        printSpace(nCols - 1);
    }
}
void printSpace2(int nCols)
{
    if (nCols > 0)
    {
        printSpace2(nCols - 1);
        cout << "  ";
    }
}
void printRows(int total, int n)
{
    if (n > 0)
    {
        printCols(n);
        printSpace(total - (n - 1));
        printCols(n);
        cout << endl;
        printRows(total, n - 1);
    }
}
void printRows2(int total, int n)
{
    if (n > 0)
    {
        printCols2(total - (n - 1));
        printSpace2(n);
        printCols2(total - (n - 1));
        cout << endl;
        printRows2(total, n - 1);
    }
}
void printStars(int n)
{
    if (n > 0)
    {
        cout << "*";
        printStars(n - 1);
    }
}
int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;
    printStars(2 * (n + 1));
    cout << endl;
    printRows(n, n);
    printRows2(n, n);
    printStars(2 * (n + 1));
    return 0;
}