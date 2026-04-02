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

    /* TEST SELECTIONSORT*/

    vector<double> times_sel_sort;
    vector<double> times_bub_sort;
    vector<double> times_ins_sort;
    vector<double> times_std_sort;
    
   // cout << "Test Selection sort \n";
   for (size_t i=4; i <= 8192; i*=2) {

        vector<double> v;
        v.resize(i); 
        rf.fill(v, -500.0, 500.0);    

        /*TEST SELECTION SORT*/
        vector<double> v_sel=v;
        tc.tic();
        selection_sort(v_sel);
        double t_sel = tc.toc();
        times_sel_sort.push_back(t_sel);

        /*TEST BUBBLE SORT*/
        vector<double> v_bub=v;
        tc.tic();
        bubble_sort(v_bub);
        double t_bub = tc.toc();
        times_bub_sort.push_back(t_bub);

        /*TEST INSERTION SORT*/
        vector<double> v_ins=v;
        tc.tic();
        insertion_sort(v_ins);
        double t_ins = tc.toc();
        times_ins_sort.push_back(t_ins);

        /*TEST STD SORT*/
        vector<double> v_std=v;
        tc.tic();
        sort(v_std.begin(), v_std.end());
        double t_std = tc.toc();
        times_std_sort.push_back(t_std);

    } 

    cout << "BUBBLE SORT times:\n";
    print_vector(times_bub_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "SELECTION SORT times:\n";
    print_vector(times_sel_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "INSERTION SORT times:\n";
    print_vector(times_ins_sort);
    cout << "--------------------------------------------------------------------\n\n";  
    
    cout << "STD SORT times:\n";
    print_vector(times_std_sort);
    cout << "--------------------------------------------------------------------\n\n";




    return EXIT_SUCCESS;
}
