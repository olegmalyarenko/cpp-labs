#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define RO 3
#define COL 3
#define V_SIZE 3

void fill_m(std::vector< std::vector<int> >& m){
    int counter = 0;
    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL; j++){
            m[i].push_back(counter++);
        }
    }
}

void print_m(std::vector< std::vector<int> > m){
    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL; j++){
            std::cout << m[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void print_v(std::vector<int> v){
    for (int j = 0; j < V_SIZE; j++){
        std::cout << v[j] << ' ';
    }
    std::cout << std::endl;
}

void transpose_m(std::vector< std::vector<int> >& m){
    std::vector< std::vector<int> > tmp(RO);

    for (int i=0; i < COL; i++){
        tmp[i].resize(3);
    }

    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL; j++){
            tmp[i][j] = m[j][i];
        }
    }

    std::cout << "Transposed matrix :\n";
    m = tmp;
    print_m(m);

}

void mult_m(std::vector< std::vector<int> >& m, std::vector<int> v){
    std::vector< int > res(V_SIZE);
    int tmp = 0;
    for (int i = 0; i < RO; i++)
    {
        for (int j = 0; j < COL && j < V_SIZE; j++){
            tmp += m[i][j] * v[j];
        }
        res[i] = tmp;
        tmp = 0;
    }
    std::cout << "Multiplication result :\n";
    print_v(res);

}

int main(void){
    std::vector< std::vector<int> > M(RO);
    std::vector<int> v;
    int inp;

    for (int i = 0; i < V_SIZE; i++){
        std::cin >> inp;
        v.push_back(inp);
    }
    std::cout << "Vector :\n";
    print_v(v);

    fill_m(M);
    std::cout << "Matrix at the begining :\n";
    print_m(M);

    transpose_m(M);

    mult_m(M, v);    
    return 0;
}