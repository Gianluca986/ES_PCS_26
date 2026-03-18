#include <iostream>
#include <cmath>

int main() {
static const int N = 10;
double arr[N] = {4.0, 19.0, 17.0, 7.2, 3.7, 0, 21.0, 7.12, 5.12, 9.11};
double m=arr[0];
double M=arr[0];
double s=0;
double sd=0;
double var=0;
for (int n=0; n<N; n++) {
    m = std::min(arr[n],m);
    M = std::max(arr[n],M);
    s += arr[n];
}
double mean = s/N;
for (int i=0; i<N; i++) {
    var += (arr[i]-mean)*(arr[i]-mean);
}
sd = std::sqrt(var/N);

std::cout << "Minimum value is: " << m << "\n" << "Maximum value is: " << M << "\n";
std::cout << "The mean is: " << mean << "\n" << "The standard Deviation is: " << sd << "\n";
return 0;
}

