#include <iostream>
#include "sorts.hpp"
#include <random>
#include <time.h>
#include <fstream>

int main(){
    srand(time(nullptr));
    std::ofstream file("Array_qsort.txt");
    CommonCompare<long long int> compar;
    QSort<long long int> qsort;
    MergeSort<long long int> mergesort;
    for(int j = 5000; j < 100000; j= j + 50){
        ArraySequence<long long int> VASYA;
        for(int i = 0; i < j ; i++ ){
            VASYA.Append(rand()%1000000000);
        }
        clock_t t = clock();
        qsort.sort(VASYA, 0, VASYA.GetLength() - 1, compar);
        t = clock() - t;
        double time = (double)t / CLOCKS_PER_SEC;
        file << j  <<" "<< time << "\n";
        std:: cout<< time <<"  "<< VASYA.GetLength()  << "\n";

    }
    return 0;
}