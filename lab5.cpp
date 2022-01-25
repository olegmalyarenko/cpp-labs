#include <iostream>

using namespace std;
int k = 0;
double Nth(int n, double b, double q) { //Рекурсивна функція обчислення n-ого члена
    ++k; // Глибина рекурсії
    if (n == 1) return b; //База рекурсії
    if (n == 2) return b * q; //База рекурсії
    return Nth(n - 1, b, q) * q; //Рекурсивний виклик
}

int main() {
    setlocale(0, "");
    int n; 
    double b, q; 
    cout << "Перший член = ";
    cin >> b; //Вводимо перший член геометричної прогресії
    cout << "Знаменник = ";
    cin >> q; //Вводимо знаменник геометричної прогресії
    cout << "n = ";
    cin >> n; //Вводимо порядний номер (кількість членів прогресії)
    cout << "Результат: " << Nth(n, b, q) << "\n"; //Виводимо результат
    cout << "\nГлибина рекурсiї = " << k;
}
