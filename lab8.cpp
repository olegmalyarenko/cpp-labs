#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define RO 3
#define COL 3
#define V_SIZE 3
//Заповнення матриці
void fill_m(std::vector< std::vector<int> >& m){
    int counter = 0;
    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL; j++){
            m[i].push_back(counter++);
        }
    }
}
//Виведення матриці
void print_m(std::vector< std::vector<int> > m){
    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL; j++){
            std::cout << m[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
//Виведення вектора
void print_v(std::vector<int> v){
    for (int j = 0; j < V_SIZE; j++){
        std::cout << v[j] << ' ';
    }
    std::cout << std::endl;
}

//Транспонування матриці
void transpose_m(std::vector< std::vector<int> >& m){
    std::vector< std::vector<int> > tmp(RO); //Задаем новую матрицу

    for (int i=0; i < COL; i++){
        tmp[i].resize(3); //Создаем 3 пустых колонки
    }

    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL; j++){
            tmp[i][j] = m[j][i]; //Проходимося по елементах нової матриці та присвоюємо їй зворотні по індексу і рядку значення від минулої
        }
    }

    std::cout << "Transposed matrix :\n";
    m = tmp;
    print_m(m);

}

void mult_m(std::vector< std::vector<int> >& m, std::vector<int> v){
    std::vector< int > res(V_SIZE); //Створюємо новий вектор
    int tmp = 0; // Значення по індексу визначеного ряду
    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL && j < V_SIZE; j++){
            tmp += m[i][j] * v[j]; //Сумма рядка
        }
        res[i] = tmp;
        tmp = 0;
    }
    std::cout << "Multiplication result :\n";
    print_v(res);

}

int main(void){
    std::vector< std::vector<int> > M(RO); //Матрицю з 3-ма рядками
    std::vector<int> v; 
    int inp; //Cтворюємо вектор з 3 елементів

    for (int i = 0; i < V_SIZE; i++){  //Заповнюємо вектор числами
        std::cout << "Fill numbers for vector:\n";
        std::cin >>inp;  
        v.push_back(inp);
    }
    std::cout << "Vector :\n";
    print_v(v);

    fill_m(M); //Заповнюємо матрицю 
    std::cout << "Matrix at the begining :\n";
    print_m(M);

    transpose_m(M); // Транпонуємо матрицю

    mult_m(M, v);    
    return 0;
}