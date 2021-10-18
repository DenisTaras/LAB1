#ifndef sorts_hpp
#define sorts_hpp
#include "Sequence.hpp"
#include "node.hpp"


template<typename T>
class Compare{
    public:
    virtual bool comp(const T &, const T &);
};

template<typename T>
class Sorts{
public:
    virtual void sort(Sequence<T> &, int, int, Compare<T> &);
};


template<typename T>
class CommonCompare: public Compare<T>{
    public:
    bool comp(const T& a, const T& b){
        return a > b;
    }
};

template<typename T>
void SWAP(Sequence<T> &data, int start, int end){
    T qq = data.Get(start);
    data.Set(start,data.Get(end));
    data.Set(end, qq);
    return;
}

template<typename T>
class QSort: public Sorts<T>{
public:

    void sort(Sequence<T> &data, int left, int right, Compare<T> &comp){
            if(right - left == 1){
        if(data.Get(left) > data.Get(right)){
            SWAP_QSORT(left,right);
        }
        return;
    }
    int start = left;
    int end = right;
    T support = data.Get((end + start)/2);
    while (start < end)
    {
        while (comp.comp(support, data.Get(start)))
        {
            start++;
        }
        while (comp.comp(data.Get(end), support)){
            end--;
        }
        if( start < end)
        {
            SWAP(data, start, end);
            start++;
            end--;
        }
    }
    if(left < end){
        sort(data, left, end, comp);
    }
    if(right > start){
        sort(data, start, right, comp);
    }  
    }
};

template<typename T>
class MergeSort: public Sorts<T>{
public:
    void sort(Sequence<T> &data, int start, int end, Compare<T> &comp){
        T* tmp = new T[data.GetLength()];
        MergeSortMain(data, start, end,comp, tmp);
        delete[] tmp;
    }

    void MergeSortMain(Sequence<T> &data, int start, int end, Compare<T> &comp, T* tmp){
        if(end - start == 0){
            return;
        }
        int mid = (start + end)/2;
        MergeSortMain(data, start, mid, comp, tmp);
        MergeSortMain(data, mid  + 1, end, comp, tmp);
        int left = start;
        int right = mid + 1;
        int k = 0;
        while (left <= mid || right <= end)
        {
            if(right <= end && left <= mid && comp.comp(data.Get(left), data.Get(right))){
                tmp[k] = data.Get(right);
                k++;
                right++;
            }
            else if (left <= mid && right <= end && !comp.comp(data.Get(left), data.Get(right))){
                tmp[k] = data.Get(left);
                k++;
                left++;
            }
            else if (left > mid){
                tmp[k] = data.Get(right);
                k++;
                right++;
            }
            else if (right > end){
                tmp[k] = data.Get(left);
                k++;
                left++;
            }
        }
        for(k--; k>=0; k--){
            data.Set(start + k, tmp[k]);
        }
    }
};

template<typename T>
class BubleSort: public Sorts<T>{
    public:
    void sort(Sequence<T> &data, int left, int right, Compare<T> &comp){
    int j,nn, n = right - 1;

    do{
        nn = 0;
        for(j = left ; j<n + 1; ++j){
            if(comp.comp(data.Get(j), data.Get(j +1))){
                SWAP(data, j,j +1);
                nn=j;
            }
        }
        n = nn;
    }while (n);
}

};
/*
template<typename T>
class TreeSort: public Sorts<T>{
    
    public:
    void p (T* elem){
        newd.Append(*elem);
    }
    
    ArraySequence<T> newd;

    void sort(Sequence<T> &data, int left, int right, Compare<T> &comp){
        Tree<T, T> tree;
        for(int i = left; i <= right; i++){
            tree.insert(data.Get(i), data.Get(i));
        }
        for(int i = left; i <= right; i++){
        tree.map(this->p);
        }
        for(int i = left; i<= right; i++){
            data.Set(i, newd.Get(i));
        }
    }
    
    
    
};*/
#endif