#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

void print(std::array<int, 20> arr)
{
    for( int i = 0; i < 20; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}


void merge(std::array<int, 10> one, std::array<int, 10> two){
    int i = 0;
    int j = 0;
    int k = 0;

    std::array<int, 20> res;
    while (i < (int)one.size() && j < (int)two.size()){
        if (one[i] < two[j])
        {
            res[k] = one[i];
            i++;
            k++;
        }
        else{
            res[k] = two[j];
            k++;
            j++;
        }
    }

    while( (int)one.size() > i){
        res[k] = one[i];
        i++;
        k++;
    }
    while( (int)two.size() > j){
        res[k] = two[j];
        k++;
        j++;
    }
    print(res);
}

int main(void){
    
    std::array<int, 10> one = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> two = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};


    merge(one, two);
    return 0;
}