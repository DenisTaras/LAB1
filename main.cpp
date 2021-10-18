#include <iostream>
#include "sorts.hpp"
#include <random>
#include <time.h>
#include <fstream>
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()
const std::string MSG[] = {"1.Manual input  \n", "2.Random input \n", "3.Exit \n" };
const int SMSG = 3;
int getmenu() {
    std::string error = "\n";
    int ch = 0;
    do {
        std::cout << error;
        error = "You're wrong. Try again!\n";
        for (int i = 0; i < SMSG; i++) {
        std::cout <<MSG[i];
        }
        puts("Make your choice: \n");
        ch = getchar() - '0';
        while (getchar() != '\n') {}    
    } while(ch < 1 || ch > SMSG);
    
    return ch;
}
int main(){
    int turn = 1;
    int res = 0;
    CommonCompare<long long int> comp;
    srand(time(nullptr));
    while(turn) {
        res = getmenu();
        switch (res)
        {
            case 1:
            {
                std:: cout << "Choose type of sequence:\n "<< "1.Array sequence \n" <<"2.Linked list sequence \n";
                int seq;
                std:: cin >> seq;
                switch (seq)
                {
                    case 1:
                    {
                        ArraySequence<long long int> Data;
                        int n;
                        long long int a;
                        std:: cout << "Enter the number of elements \n";
                        std:: cin >> n;
                        std:: cout << "Enter elements \n";
                        for(int i = 0; i < n; i++){
                            std::cin >> a;
                            Data.Append(a);
                        }
                        std:: cout << "Choose type of sort:\n "<< "1.Qsort \n" <<"2.Merge sort \n"<< "3.Buble sort \n";
                        int sorts;
                        std:: cin >> sorts;
                        switch (sorts)
                        {
                            case 1:
                            {
                                QSort<long long int> qsort;
                                qsort.sort(Data, 0, Data.GetLength() - 1, comp);

                                for(int i = 0; i < Data.GetLength(); i++){
                                    std::cout << Data.Get(i) << " ";
                                }
                                std::cout << "\n";
                                CIN_FLUSH;
                                break;
                            }
                            case 2:
                            {
                                MergeSort<long long int> mergesort;
                                mergesort.sort(Data, 0, Data.GetLength() - 1, comp);

                                for(int i = 0; i < Data.GetLength(); i++){
                                    std::cout << Data.Get(i) << " ";
                                }
                                std::cout << "\n";
                                CIN_FLUSH;
                                break;
                            }
                            case 3:
                            {
                                BubleSort<long long int> insertsort;
                                insertsort.sort(Data, 0, Data.GetLength() - 1, comp);

                                for(int i = 0; i < Data.GetLength(); i++){
                                    std::cout << Data.Get(i) << " ";
                                }
                                std::cout << "\n";
                                CIN_FLUSH;
                                break;
                            }
                        }
                        CIN_FLUSH;
                        break;
                    }
                    case 2:
                    {
                        LinkedListSequence<long long int> Data;
                        int n;
                        long long int a;
                        std:: cout << "Enter the number of elements \n";
                        std:: cin >> n;
                        std:: cout << "Enter elements \n";
                        for(int i = 0; i < n; i++){
                            std::cin >> a;
                            Data.Append(a);
                        }
                        int sorts;
                        std:: cout << "Choose type of sort:\n "<< "1.Qsort \n" <<"2.Merge sort \n"<< "3.Buble sort \n";
                        std:: cin >> sorts;
                        switch (sorts)
                        {
                            case 1:
                            {
                                QSort<long long int> qsort;
                                qsort.sort(Data, 0, Data.GetLength() - 1, comp);
                                std::cout << "Your sequence: \n";
                                for(int i = 0; i < Data.GetLength(); i++){
                                    std::cout << Data.Get(i) << " ";
                                }
                                std::cout << "\n";
                                CIN_FLUSH;
                                break;
                            }
                            
                            case 2:
                            {
                                MergeSort<long long int> mergesort;
                                mergesort.sort(Data, 0, Data.GetLength() - 1, comp);
                                std::cout << "Your sequence: \n";
                                for(int i = 0; i < Data.GetLength(); i++){
                                    std::cout << Data.Get(i) << " ";
                                }
                                std::cout << "\n";
                                CIN_FLUSH;
                                break;
                            }
                            case 3:
                            {
                                BubleSort<long long int> insertsort;
                                insertsort.sort(Data, 0, Data.GetLength() - 1, comp);

                                for(int i = 0; i < Data.GetLength(); i++){
                                    std::cout << Data.Get(i) << " ";
                                }
                                std::cout << "\n";
                                CIN_FLUSH;
                                break;
                            }
                            
                        }
                        CIN_FLUSH;
                        break;
                    }
                }
                CIN_FLUSH;
                break;
            }
            case 2:
            {
                std:: cout << "Choose type of sequence:\n "<< "1.Array sequence \n" <<"2.Linked list sequence \n";
                int seq;
                std:: cin >> seq;
                switch (seq)
                {
                    case 1:
                    {
                        ArraySequence<long long int> Data;
                        int n = 0;
                        std:: cout << "Enter the number of elements \n";
                        while (n == 0)
                        {
                            std::cin >> n;
                            if ( ( n > 100000001)  || ( n < 0))
                            {
                                std:: cout << "incorrect n, try agayn\n";
                                n = 0;
                            }    
                        }
                        for(int i = 0; i < n; i++)
                        {
                            Data.Append(rand()%100000000000);
                        }

                        std:: cout << "Choose type of sort:\n "<< "1.Qsort \n" <<"2.Merge sort \n"<< "3.Buble sort \n";
                        int sorts;
                        std:: cin >> sorts;
                        switch (sorts)
                        {
                            case 1:
                            {
                                QSort<long long int> qsort;
                                clock_t t = clock();
                                qsort.sort(Data, 0, Data.GetLength() - 1, comp);
                                t = clock() - t;
                                double time = (double)t / CLOCKS_PER_SEC;
                                std::cout << "Sorting time: " << time << "\n" << "Print data?(enter 1 if yes, 0 if no)" << "\n";
                                int print;
                                std:: cin >> print;
                                if(print == 1)
                                {
                                    std::cout << "Your sequence: \n";
                                    for(int i = 0; i < Data.GetLength() - 1; i++){
                                        std::cout << Data.Get(i) << " ";
                                    }
                                    std::cout << "\n";
                                }
                                CIN_FLUSH;
                                break;
                            }
                                
                            case 2:
                            {
                                MergeSort<long long int> mergesort;
                                clock_t t = clock();
                                mergesort.sort(Data, 0, Data.GetLength() - 1, comp);
                                t = clock() - t;
                                double time = (double)t / CLOCKS_PER_SEC;
                                std::cout << "Sorting time: " << time << "\n" << "Print data?(enter 1 if yes, 0 if no)" << "\n";
                                int print;
                                std:: cin >> print;
                                if(print == 1)
                                {
                                    std::cout << "Your sequence: \n";
                                    for(int i = 0; i < Data.GetLength() - 1; i++){
                                        std::cout << Data.Get(i) << " ";
                                    }
                                    std::cout << "\n";
                                }
                                CIN_FLUSH;
                                break;
                            }
                            case 3:
                            {
                                BubleSort<long long int> insertsort;
                                clock_t t = clock();
                                insertsort.sort(Data, 0, Data.GetLength() - 1, comp);
                                t = clock() - t;
                                double time = (double)t / CLOCKS_PER_SEC;
                                std::cout << "Sorting time: " << time << "\n" << "Print data?(enter 1 if yes, 0 if no)" << "\n";
                                int print;
                                std:: cin >> print;
                                if(print == 1)
                                {
                                    std::cout << "Your sequence: \n";
                                    for(int i = 0; i < Data.GetLength() - 1; i++){
                                        std::cout << Data.Get(i) << " ";
                                    }
                                    std::cout << "\n";
                                }
                                CIN_FLUSH;
                                break;
                            }
                        }
                        CIN_FLUSH;
                        break;
                    }
                    case 2:
                    {
                        LinkedListSequence<long long int> Data;
                        std:: cout << "Enter the number of elements \n";
                        int n = 0;
                        while (n == 0)
                        {
                            std::cin >> n;
                            CIN_FLUSH;
                            if ( ( n > 100001)  || ( n < 0))
                            {
                                std:: cout << "incorrect n, try agayn\n";
                                n = 0;
                                CIN_FLUSH;
                            }    
                        }
                        for(int i = 0; i < n; i++)
                        {
                            Data.Append(rand()%100000000000);
                        }
                        std:: cout << "Choose type of sort:\n "<< "1.Qsort \n" <<"2.Merge sort \n"<< "3.Buble sort \n";
                        int sorts;
                        std:: cin >> sorts;
                        switch (sorts)
                        {
                            case 1:
                            {   
                                QSort<long long int> qsort;
                                clock_t t = clock();
                                qsort.sort(Data, 0, Data.GetLength() - 1, comp);
                                t = clock() - t;
                                double time = (double)t / CLOCKS_PER_SEC;
                                std::cout << "Sorting time: " << time << "\n" << "Print data?(enter 1 if yes, 0 if no)" << "\n";
                                int print;
                                std:: cin >> print;
                                if(print == 1)
                                {
                                    std::cout << "Your sequence: \n";
                                    for(int i = 0; i < Data.GetLength() - 1; i++){
                                        std::cout << Data.Get(i) << " ";
                                    }
                                    std::cout << "\n";
                                }
                                CIN_FLUSH;
                                break;
                            }
                            case 2:
                            {
                                MergeSort<long long int> mergesort;
                                clock_t t = clock();
                                mergesort.sort(Data, 0, Data.GetLength() - 1, comp);
                                t = clock() - t;
                                double time = (double)t / CLOCKS_PER_SEC;
                                std::cout << "Sorting time: " << time << "\n" << "Print data?(enter 1 if yes, 0 if no)" << "\n";
                                int print;
                                std:: cin >> print;
                                if(print == 1)
                                {
                                    std::cout << "Your sequence: \n";
                                    for(int i = 0; i < Data.GetLength() - 1; i++){
                                        std::cout << Data.Get(i) << " ";
                                    }
                                    std::cout << "\n";
                                }
                                CIN_FLUSH;
                                break;
                            }
                            case 3:
                            {
                                BubleSort<long long int> insertsort;
                                clock_t t = clock();
                                insertsort.sort(Data, 0, Data.GetLength() - 1, comp);
                                t = clock() - t;
                                double time = (double)t / CLOCKS_PER_SEC;
                                std::cout << "Sorting time: " << time << "\n" << "Print data?(enter 1 if yes, 0 if no)" << "\n";
                                int print;
                                std:: cin >> print;
                                if(print == 1)
                                {
                                    std::cout << "Your sequence: \n";
                                    for(int i = 0; i < Data.GetLength() - 1; i++){
                                        std::cout << Data.Get(i) << " ";
                                    }
                                    std::cout << "\n";
                                }
                                CIN_FLUSH;
                                break;
                            }
                        }
                        CIN_FLUSH;
                        break;
                    }
                }
                CIN_FLUSH;
                break;
            }
            case 3:
            {
                std::cout << "Goodbye";
                turn  = 0;
                CIN_FLUSH;
                break;
            }
            CIN_FLUSH;
        }
    }
    return 0;
}