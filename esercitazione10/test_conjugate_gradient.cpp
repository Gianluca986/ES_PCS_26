#include <iostream>
#include <Eigen/Dense>
#include "randfiller.h"
#include "conjugate_gradient.hpp"


/*Funzione per generare la dimensione della matrice di test*/
/* Uguale a quella del file randfiller.h*/
int random_dim(int min, int max) {
    randfiller rf;
    std::vector<int> v(1);
    rf.fill(v, min, max);
    return v[0];
}

/*Per tutto il TEST la soluzione esatta è il vettore unitario*/
int main() {
    const double res_tol = 1.0e-12;
    const double tol = 1.0e-15;  // tolleranza per verificare se la matrice è invertibile
    int steps = 0;
    int it_max = 1000;

    /*TEST: matrice non simmetrica*/
    int m = random_dim(10,100);
    Eigen::MatrixXd M = Eigen::MatrixXd::Random(m,m);
    Eigen::VectorXd x_ex_ = Eigen::VectorXd::Ones(m);
    Eigen::VectorXd b_ = M * x_ex_;
    Eigen::VectorXd x0_ = Eigen::VectorXd::Random(m);    // il vettore x0 può essere qualunque: lo riempo in modo casuale
    Eigen::VectorXd x_ = conjugate_gradient(M, b_, x0_, it_max, res_tol, steps);

    // passo 0.0 come tolleranza perché mi aspetto uno zero perfetto (VectorXd::Zero)
    if (!x_.isZero(0.0)) { 
        // Se il vettore NON è zero, la funzione non ha bloccato la matrice asimmetrica
        std::cerr << "Test Failed: the program accepted a non-symmetric matrix!" << std::endl;
        return EXIT_FAILURE;
    }

    /*TEST: matrice simmetrica e definita positiva*/
    for (int i=1; i <= 10; i++) {
        int n = random_dim(10,100); // testo la funzione su matrici di dimensioni casuali  
        Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

        // se il determinante di B è 0 passo alla prossima iterazione
        if (abs(B.determinant()) < tol) {
            std::cout << "Matrix at step " << i << " is not Invertible!" << std::endl;
            continue;
        }
        // altrimenti costruisco una matrice A simmetrica e definita positiva come A = B'*B su cui testare il gradiente coniugato 
        Eigen::MatrixXd A = B.transpose() * B;

        //inizializzo le variabili che mi servono
        Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
        Eigen::VectorXd b = A * x_ex;

        Eigen::VectorXd x0 = Eigen::VectorXd::Random(n); // x0 casuale
        Eigen::VectorXd x = conjugate_gradient(A, b, x0, it_max, res_tol, steps);
        
        // se la norma relativa della soluzione è > 1.0e-8: EXIT_FAILURE
        if (!x.isApprox(x_ex, 1.0e-8)) {
            std::cerr << "Test Failed: The solution is not accurate enough!" << std::endl;
            return EXIT_FAILURE;
        }

        // l'algoritmo termina perché ho raggiunto le iterazioni massime
        if (steps >= it_max) {
            std::cerr << "Test Failed: Maximum iterations reached!" << std::endl;
            return EXIT_FAILURE; 

        }
    }


    std::cout << "Test Successful \n";
    return EXIT_SUCCESS;
}