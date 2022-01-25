#include <iostream>
#include <cmath>
using namespace std;

// Функція для визначення факторіалу
int factorial(int i)  
{
    if (i == 0) return 1;
    else return i * factorial(i - 1); 
}

int main()
{
    int st_k = 20;// k від 0 до 20
    int result = 0;
    // Обчислення суми ряду
    for (int x = 1; x <= 5; x++) {
        int nomenator = 0;
        for (int k = 0; k < st_k; k++)
        {
            if (k == 0)
            {
                nomenator = x * (x + 1);
                int denomninator = factorial(k);
                result += nomenator / denomninator;
                continue;
            }
            nomenator += (x + k) * pow(x, k);
            int denomninator = factorial(k);
            result += nomenator / denomninator;
        }


    }
    // Вивід результату обчислень
    cout << "Result: " << result << endl;
    return 0;
}
