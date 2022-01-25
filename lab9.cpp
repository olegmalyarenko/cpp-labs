#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>  
#include <wchar.h>
#include <cwchar>
#include <string>
#include "clocale"

bool test(wchar_t c){
    std::string v = "aioue";
    for (int i = 0; i < 7; i++){
        if(c == v[i])
            return true;
    }
    return false;
}

int count(std::string s){ // Рахує кількість голосних
    int amount = 0;

    for (int i = 0; i < s.length(); i++){
        if(test(s[i]))  //Перевіряємо чи це голосна буква 
            amount++;
    }
    return amount;
}

void split(std::string w)
{
    if (w.length() <= 3 || count(w) == 1){ //Якщо кількість літер меньше 3 або кількість голосних дорівнєю 1 
        std::cout << w << std::endl; //Виводимо все слово
        return ;
    }

    for (int i = 0; i < w.length(); i++){ //Йдемо через всю довжину слова
        if (test(w[i])){  //Якщо буква голосна 
            std::cout << w[i]; //Друкуємо
            if (i != w.length()-1 && count(&w[i+1])) //Якщо вона не остання та після неї є ще одна голосна 
                std::cout << "-"; //Додаємо прочерк
        }
        else
            std::cout << w[i]; //Просто друкуємо 
    }
    std::cout << std::endl; //Виводимо кінець строки
}




void pars_line(std::string s, bool & cnt){
    if (cnt){ //Якщо чотне
        std::reverse(s.begin(), s.end()); //Записуємо у зворотньому напрямку
        std::cout << s << std::endl; //Виводимо  отримане слово
    }
    else
        split(s);
    cnt = !cnt;

}

int main(void){
    std::string s; //Створюємо зміну для запису значення з терміналу
    bool cnt = true; //Змінна, що буде визначати парна чи не парна позиція слова
    std::cout << "Fill some words:\n";
    while(1){   
        
        std::cin >> s; //Якщо ввели слово

        pars_line(s, cnt);        
        if (std::cin.eof())  //Якщо натиснули кінець файлу - то закінчити
            break;
    }
    return 0;
}