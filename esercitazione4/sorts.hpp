#pragma once
#include <iostream>
#include <algorithm>
#include <vector> 
#include <optional> 

using namespace std;

template<typename T> 
void bubble_sort(vector<T>& vec) {

    if (vec.size() <= 1) return; 

    int N=size(vec);
    for (int i=0; i<= N-2; i++) {
        for (int j=N-1; j>=i+1; j--) { 
            if (vec.at(j) < vec.at(j-1)) {
                swap(vec.at(j),vec.at(j-1));
            }
        }
    }
}

template<typename T>
void selection_sort(vector<T>& vec) {
    
    if (vec.size() <= 1) return; 

    int N=size(vec);
    for (int i=0; i <= N-2; i++) {
        int min_index=i;
        for (int j=i+1; j<=N-1; j++) { 
            if (vec.at(j) < vec.at(min_index)) {
                min_index=j;
            }
        }
        if (min_index != i) {
            swap(vec.at(i),vec.at(min_index));
        }
    }
}

template<typename T>
void insertion_sort(vector<T>& vec) {

    if (vec.size() <= 1) return; 

    int N=size(vec);
    for (int i=1; i<= N-1; i++) {
        T value = vec.at(i);
        int j = i-1;
        while (j >= 0 && vec.at(j) > value ) { 
            vec.at(j+1) = vec.at(j);
            j--;
        }
    vec.at(j+1) = value;
    }
}


template<typename T>
bool is_sorted(const vector<T>& vec) {
    if (size(vec) <= 1) return true; 

    int N=size(vec);
    /* Caso generale*/
    for (int i=0; i < N-1; i++) {
        if (vec.at(i) > vec.at(i+1)) {
            return false;
        }   
    }
    return true;
}