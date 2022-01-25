#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

// обчислення числа Фібоначі
int* f(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        a += b;
        b = a - b;
    }
    int* l = &a; // Передаємо значення через посиланя
    return l;
}

// Функція для знаходження номера числа Фібоначчі, яке більше ніж передане число g
int* n(int g)
{
    int a = 0;
    int b = 1;
    int n = 1;
    for (int i = 0; i < n; i++)
    {
        a += b;
        b = a - b;
        if (a > g)
        {
            break; // Виходимо з циклу
        }
        else
        {
            n++;
        }
    }
    int* k = &n; // Передаємо значення через посиланя
    return k;
}

int main()
{
    int a;
    cout << "Enter A:";
    cin >> a;
    int b = *(n(a));
    cout << "B = " << b << "\n";
    int n = 1;
    while (*(f(n)) < a && *(f(n)) < b)
    {
        n++;
    }
    cout << "\nAnswer: " << *(f(n - 1)) << "\n";
    return 0;
} 
