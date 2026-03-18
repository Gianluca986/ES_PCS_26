# include <iostream>

int main()
{
double ad[4] = {0.0, 1.1, 2.2, 3.3}; // in memoria è salvato in 0x7ffe773afaa0
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
int ai[3] = {0, 1, 2};
                    // sizeof(double) = 8 byte
int x = 1;          // sizeof(int) = 4 byte
float y = 1.1;      // sizeof(float) = 4 byte

(&y)[1] = 0;        // &y prende l'indirizzo di y 
                    // [1] signfica: vai avanti all'indirizzo <base + i * sizeof(T)>
                    // ma a quell'indirizzo c'è salvata x che diventa = 0
std::cout << x << "\n";
// stampo gli indirizzi di memoria di x e y
std::cout << &x << "\n";       // stampa l'indirizzo di x
std::cout << &y << "\n";       // stampa l'indirizzo di y

return 0;
}