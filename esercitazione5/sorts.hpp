#pragma once
#include <iostream>
#include <algorithm>
#include <vector> 
#include <optional> 
#include <cmath> 


using namespace std;

/* =============== BUBBLE SORT ==================== */

template<typename T> 
void bubble_sort(vector<T>& vec) {

    if (vec.size() <= 1) return; 

    int N = size(vec);
    for (int i=0; i <= N-2; i++) {
        for (int j = N-1; j >= i+1; j--) { 
            if (vec[j] < vec[j-1]) {
                swap(vec[j],vec[j-1]);
            }
        }
    }
}
/* =================================================== */

/* =============== SELECTION SORT ==================== */

template<typename T>
void selection_sort(vector<T>& vec) {
    
    if (vec.size() <= 1) return; 

    int N = size(vec);
    for (int i = 0; i <= N-2; i++) {
        int min_index = i;
        for (int j = i+1; j <= N-1; j++) { 
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(vec[i],vec[min_index]);
        }
    }
}
/* =================================================== */

/* =============== INSERTION SORT ==================== */

template<typename T>
void insertion_sort(vector<T>& vec) {

    if (vec.size() <= 1) return; 

    int N = size(vec);
    for (int i = 1; i <= N-1; i++) {
        T value = vec[i];
        int j = i-1;
        while (j >= 0 && vec[j] > value ) { 
            vec[j+1] = vec[j];
            j--;
        }
    vec[j+1] = value;
    }
}
/* =================================================== */

/* ================== MERGE SORT ===================== */

// NOTA: la struttura è diversa pseudo-codice fornito //
template<typename T> 
void merge(vector<T>& vec, size_t left, size_t center, size_t right) {
    size_t size_left = center - left + 1;
    size_t size_right = right - center;
    size_t i=0; // indice per vettore Left
    size_t j=0; // indice per vettore Right
    size_t k=left; // indice per vettore unito

    // il +1 dello psuedo-codice era per infilarci gli infiniti [che in questa versione non ci sono]
    vector<T> L(size_left); vector<T> R(size_right);

    /* Riempo il vettore Left con gli elementi da left a center */
    for (size_t iter = 0; iter < size_left; iter++) {
        L[iter] = vec[left+iter];
    }

    /* Riempo il vettore Right con gli elementi da center+1 a Right*/
    for (size_t iter = 0; iter < size_right; iter++) {
        R[iter] = vec[center+1+iter];
    }

    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++; 
    }

    // questi while avvengono solo dopo il while di prima quindi si "attivano"
    // se i < size_left (ovvero se l'indice per il vettore Left è più piccolo della 
    // della dimensione di Left [quindi se Left ha ancora degli elementi])
    while (i < size_left) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < size_right) {
        vec[k] = R[j];
        j++;
        k++;
    }
       
}
template<typename T>
void merge_sort(vector<T>& vec, size_t left, size_t right) {
    if (vec.size() <= 1) return; 
    if (left < right) {
        size_t center = (left+right)/2; // floor non serve perché stiamo restituendo un size_t [intero] quindi c++ lo fa in automatico
        merge_sort(vec, left, center);
        merge_sort(vec, center+1, right);
        merge(vec, left, center, right);
    }
}
/* =================================================== */

/* ================= QUICK SORT ====================== */

template<typename T>
int my_partition(vector<T>& vec, int left, int right) {
    T x = vec[right]; 
    int i = left-1; 
    for (int j = left; j <= right-1; j++) {
        if (vec[j] <= x) {
            i++; 
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i+1],vec[right]);
    return i+1;
}

template<typename T>
/* rispetto alle note qui il pivot p è sempre right*/
void quick_sort(vector<T>& vec, int left, int right) {
    if (vec.size() <= 1) return; 
    if (left < right) {
        int rank = my_partition(vec,left,right);
        quick_sort(vec, left, rank-1);
        quick_sort(vec, rank+1, right);
    }
}
/* =================================================== */

/* =============== QUICK SORT HYBRID ==================== */

template<typename T>
void insertion_sort_range(vector<T>& vec, int left, int right) {

    if (right - left <= 0) return; 

    for (int i = left+1; i <= right; i++) {
        T value = vec[i];
        int j = i-1;
        while (j >= left && vec[j] > value ) { 
            vec[j+1] = vec[j];
            j--;
        }
    vec[j+1] = value;
    }
}


template<typename T>
void quick_sort_hybrid(vector<T>& vec, int left, int right) {
    const int cutoff = 200; // soglia dopo cui l'insertion sort è peggio del quick sort
    if (vec.size() <= 1) return; 

    if (right-left+1 < cutoff) {
        insertion_sort_range(vec, left, right);
    }
    else { 
        if (left < right) {
        int rank = my_partition(vec, left, right);
        quick_sort_hybrid(vec, left, rank-1);
        quick_sort_hybrid(vec, rank+1, right);
        }
    }
}


/* =================================================== */

/* ================= IS SORTED ======================= */

template<typename T>
bool is_sorted(const vector<T>& vec) {
    if (size(vec) <= 1) return true; 
    int N=size(vec);

    for (int i=0; i < N-1; i++) {
        if (vec[i] > vec[i+1]) {
            return false;
        }   
    }
    return true;
}
