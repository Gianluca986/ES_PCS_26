#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "randfiller.h"
#include "timecounter.h"
#include "sorts.hpp"

using namespace std;

template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
        
    }
    std::cout << "\n";
}


int main(void) {
    randfiller rf; 
    timecounter tc;

    vector<double> times_sel_sort;
    vector<double> times_bub_sort;
    vector<double> times_ins_sort;
    vector<double> times_std_sort;
    vector<double> times_mer_sort;
    vector<double> times_qck_sort;
    vector<double> times_qckhyb_sort;

    size_t N = 100;   // 100 prove diverse con la stessa dimensione //

    /*cercare la dimensione di cutoff facendo delle prove sui cicli for*/
    for (size_t i=150; i <= 300; i++) {

        /* creo una matrice 100 x i */
        std::vector<std::vector<double>> data(N,std::vector<double>(i)); 
        
        /* riempio TUTTA la matrice in modo casuale scorrendola per riga*/
        for (size_t k = 0; k < N; k++) {
            rf.fill(data[k], -500.0, 500.0);
        }   
        
        /*TEST SELECTION SORT*/
        std::vector<std::vector<double>> data_sel = data;
        tc.tic();
        for (size_t k = 0; k < N; k++) {
            selection_sort(data_sel[k]);
        }           
        double t_sel = tc.toc()/N; // tempo mediato
        times_sel_sort.push_back(t_sel);

        /*TEST BUBBLE SORT*/
        std::vector<std::vector<double>> data_bub = data;
        tc.tic();
        for (size_t k = 0; k < N; k++) {
            bubble_sort(data_bub[k]);
        }    
        double t_bub = tc.toc()/N;
        times_bub_sort.push_back(t_bub);

        /*TEST INSERTION SORT*/
        std::vector<std::vector<double>> data_ins = data;
        tc.tic(); 
        for (size_t k = 0; k < N; k++) {
            insertion_sort(data_ins[k]);
        }    
        double t_ins = tc.toc()/N;
        times_ins_sort.push_back(t_ins);

        /*TEST MERGE SORT*/
        std::vector<std::vector<double>> data_mer = data;
        tc.tic();
        for (size_t k = 0; k < N; k++) {
            merge_sort(data_mer[k], 0, data_mer[k].size()-1);
        }    
        double t_mer = tc.toc()/N;
        times_mer_sort.push_back(t_mer);

        /*TEST QUICK SORT*/
        std::vector<std::vector<double>> data_qck = data;
        tc.tic();
        for (size_t k = 0; k < N; k++) {
            quick_sort(data_qck[k], 0, data_qck[k].size()-1);
        }    
        double t_qck = tc.toc()/N;
        times_qck_sort.push_back(t_qck);

        /*TEST QUICK SORT HYBRID*/
        std::vector<std::vector<double>> data_qckhyb = data;
        tc.tic();
        for (size_t k = 0; k < N; k++) {
            quick_sort_hybrid(data_qckhyb[k], 0, data_qckhyb[k].size()-1);
        }    
        double t_qckhyb = tc.toc()/N;
        times_qckhyb_sort.push_back(t_qckhyb);

        /*TEST STD SORT*/
        std::vector<std::vector<double>> data_std = data;
        tc.tic();
        for (size_t k = 0; k < N; k++) {
            std::sort(data_std[k].begin(), data_std[k].end());
        }    
        double t_std = tc.toc()/N;
        times_std_sort.push_back(t_std);

    } 

  /*  cout << "BUBBLE SORT times:\n";
    print_vector(times_bub_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "SELECTION SORT times:\n";
    print_vector(times_sel_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "INSERTION SORT times:\n";
    print_vector(times_ins_sort);
    cout << "--------------------------------------------------------------------\n\n";  

    cout << "MERGE SORT times:\n";
    print_vector(times_mer_sort);
    cout << "--------------------------------------------------------------------\n\n";  
    
    cout << "QUICK SORT times:\n";
    print_vector(times_qck_sort);
    cout << "--------------------------------------------------------------------\n\n";  
    
    cout << "QUICK SORT HYBRID times";
    print_vector(times_qckhyb_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "STD SORT times:\n";
    print_vector(times_std_sort);
    cout << "--------------------------------------------------------------------\n\n";
*/

    print_vector(times_bub_sort); cout<<";";
    print_vector(times_sel_sort); cout<<";";
    print_vector(times_ins_sort); cout<<";";
    print_vector(times_mer_sort); cout<<";";
    print_vector(times_qck_sort); cout<<";";
    print_vector(times_qckhyb_sort); cout<<";";
    print_vector(times_std_sort); cout<<";";

    return EXIT_SUCCESS;
}
