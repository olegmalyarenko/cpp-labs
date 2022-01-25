#include <iostream>
#include <math.h> 
using namespace std;

double Tg(float x)
{
    float sum = x - 1; //сума членів ряду
    int i = 1; // знаменник елемента ряду
    float t = 0.001; //точність обчислення
    float member = x - 1; //поточний елемент ряду
    while (member > t)
    {
        member = member * (x - 1); //поточний елемент за формулою Тейлора
        sum += member / i; // сума
        i++;
    }
    return sum;
}
int main()
{
    float y, // Вираз за формулою Тейлора
        st, // значення стандартної функції tg
        x, // аргумент функції
        err; // похибка
    cout << "--------------------------------------------------" << endl;
    printf("     x             y          standart        error \n");
    cout << "--------------------------------------------------" << endl;

    for (x = -3; x <= 3; x += 0.5) // цикл перебору значень аргументу функції
    {
        int flag = 0;
        if (-2 <= x && x < 0) //перевірка умов вибору розрахункової функції
        {
            y = (Tg(x) - (x / 2)) / Tg(2 * x); // Визначення функції за формулою Тейлора
            st = (tan(x) - (x / 2)) / tan(2 * x); //Визначення функції за стандартною формулою
            err = st - y; //Розбіжність між точним і наближеним значеннями функції
        }
        else if (0 < x && x <= 2)
        {
            y = Tg(x + 2) - pow(Tg(x), 2);
            st = tan(x + 2) - pow(tan(x), 2);
            err = st - y;
        }
        else if (x < 0)
            flag = 1;
        if (flag == 0)
            printf("  %f     %f     %f      %f \n", x, y, st, err);
        else
            printf("  %f     not define    \n", x);
    }
    return 0;
}
