#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double Y = 0, x;
    cout << "Введiть Х: ";
    cin >> x;

    if (0 < x && x < 5) Y = pow(x + 1, 2);

    else if (x == 5) Y = pow(x - 1, 2);
    
    else if (x > 5) Y = (x - 1) / (x + 1);

    else if (x < 0) Y = (x - 1) * (x + 1);

    cout << "\nY = " << Y << endl;

    return 0;
}
