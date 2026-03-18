#include <iostream>

using namespace std;
int main() {
    static const int N=10;  // dimensione dell'array
    double arr[N]={4.0, 19.0, 17.0, 7.2, 3.7, 0, 21.0, 7.12, 5.12, 9.11};
   
    bool swapped = true;
    while (swapped == true) {
        swapped = false;
        for (int i=0; i<N-1; i++){
            if  (arr[i] > arr[i+1])  {
                double temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swapped = true;
            }
        } 
    }   
    for (int i=0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
