#include <stdio.h>

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x, a, b, c, d;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;

    x = a / (1 + b / (c + log(d + a)));
    cout << "X = " << x;
    cin.get();
    return 0;
}
