#include <iostream>
#include <vector>
#include <string>
#include "randfiller.h"
#include "sorts.hpp"


template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

/*Genero un vettore lungo 1 che mi dice la dimensione casusale*/
std::vector<int> random_number(randfiller& rf) {
    std::vector<int> dim_vec;
    dim_vec.resize(1); 
    rf.fill(dim_vec, 0, 1000); 
    return dim_vec;
}

int main(void) {
    randfiller rf; 

    /* Riempo i miei 100 vettori con INTERI */
    for (size_t i=0; i < 100; i++) {
        std::vector<int> dim_vec = random_number(rf);
        /* Genero il vettore di dimensione "dim" */
        std::vector<int> vi;
        vi.resize(dim_vec.at(0)); 
        rf.fill(vi, -500, 500);   
        bubble_sort(vi);
        if (!is_sorted(vi)) {
            std::cout << "Test Failed: the vector number " << i << " is not sorted. \n";
            return EXIT_FAILURE;
        }
    }

    /* TEST SU STRINGHE */
    std::vector<string> vs = {"sdrogo", "hello world", "ciao mamma" , "gianluca", "programmazione e calcolo scientifico", "c++"};
    vs.push_back("blackjack");
    bubble_sort(vs);
        if (!is_sorted(vs)) {
        std::cout << "Test Failed: the String vector is not sorted! \n";
        return EXIT_FAILURE;
    }

    std::cout << "Test Successful \n";
    return EXIT_SUCCESS;
}
