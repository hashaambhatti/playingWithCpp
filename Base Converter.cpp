
#include <iostream>

using namespace std;

char *BaseConverter(float n, int base)
{
    char *p = new char[25];

    int intpoint = n, count = 0;
    float pointAfter = n - intpoint;

    for (int i = 0; intpoint > 0; i++)
    {

        p[i] = intpoint % base + 48;

        p[i + 1] = '\0';
        intpoint = intpoint / base;
        count++;
    }

    int i = 0, cPoint = count;
    while (i < count / 2)
    {

        char temp = p[--count];
        p[count] = p[i];
        p[i] = temp;
        i++;
    }

    if (pointAfter == 0.0)
    {
        return p;
    }

    p[cPoint] = 46;
    cPoint++;

    int counter = 0;
    while (pointAfter != 0.0 && counter < 5)
    {
        pointAfter *= base;
        int pInt = pointAfter;

        p[cPoint++] = pInt + 48;

        pointAfter -= pInt;
        counter++;
    }

    p[cPoint] = '\0';

    return p;
}

int main()
{
    int base, neg = 0;
    float n;
    cout << "Enter a number in decimal number system (Base 10): " << endl;
    cin >> n;

    if (n < 0)
    {
        n = -n;
        neg = 1;
    }

    cout << "Enter the base you want your number to be converted to: " << endl;
    cin >> base;

    while (base <= 1)
    {
        cout << "Enter a base greater than or equal to 2: " << endl;
        cin >> base;
    }

    if (n == 0)
    {
        cout << "0";
        return 0;
    }

    char *ptr = BaseConverter(n, base);
    if (neg == 1)
    {
        cout << "The number in base " << base << " is: -" << ptr;
    }
    else
    {
        cout << "The number in base " << base << " is: " << ptr;
    }
    delete[] ptr;
    return 0;
}