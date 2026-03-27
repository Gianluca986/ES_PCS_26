#include <iostream>
#include <concepts>
#include "rational.hpp"

int main() {
    rational<int> inf(3,0);
    rational<int> _inf(-3,0);
    rational<int> nan(0,0);
    rational<int> r1(1,2);
    rational<int> r2(4,-3);

    std::cout << "Inf: " << inf << "\n";
    std::cout << "-Inf: " << _inf << "\n";
    std::cout << "NaN: " << nan << "\n";
    std::cout << "r1:  " << r1 << "\n";
    std::cout << "r2:  " << r2 << "\n";

    /* Test Di comportamento per Inf e NaN */

    // Inf + rational = Inf //
    rational<int> r3 = inf + r1;    
    std::cout << "Inf + " << r1 << " = " << r3 << " (Expected: Inf)\n";
    
    rational<int> r3_ = inf + r2;    
    std::cout << "Inf + " << r2 << " = " << r3_ << " (Expected: Inf)\n";

    // NaN + qualcosa = NaN //
    rational<int> r4 = nan + r1;   
    rational<int> r5 = nan + inf;   
    std::cout << "NaN + " << r1  << " = " << r4 << " (Expected: NaN)\n";
    std::cout << "NaN + Inf" << " = " << r5 << " (Expected: NaN)\n";

    // Inf * rational = +- Inf //
    rational<int> r6 = inf * r1;
    rational<int> r7 = inf * r2;
    std::cout << "Inf * " << r1 << " = " << r6 << "\n";
    std::cout << "Inf * " << r2 << " = " << r7 << "\n";

    // Inf + (-Inf) = NaN //
    rational<int> r8 = inf + _inf;
    std::cout << "Inf + (-Inf)" << " = " << r8 << "\n";

    /* Test Sottrazione */
    rational<int> r9 = r1 - r2;
    std::cout << r1 << " - (" << r2 << ") = " << r9 << " (Expected: 11/6)\n";

    rational<int> r10 = inf - r1;
    std::cout << "Inf - " << r1 << " = " << r10 << " (Expected: +Inf)\n";

    rational<int> r11 = r1 - inf;
    std::cout << r1 << " - Inf = " << r11 << " (Expected: -Inf)\n";

    // Inf - Inf (Che equivale a Inf + (-Inf))
    rational<int> r12 = inf - inf;
    std::cout << "Inf - Inf = " << r12 << " (Expected: NaN)\n";

    /* Test Divisione */
    rational<int> r13 = r1 / r2;
    std::cout << r1 << " / (" << r2 << ") = " << r13 << " (Expected: -3/8)\n";

    // Divisione per zero (1/2 / 0 = Inf)
    rational<int> zero(0, 1);
    rational<int> r14 = r1 / zero;
    std::cout << r1 << " / 0 = " << r14 << " (Expected: +Inf)\n";

    // Divisione per Inf (1/2 / Inf = 0)
    rational<int> r15 = r1 / inf;
    std::cout << r1 << " / Inf = " << r15 << " (Expected: 0/1)\n";

    // Inf / Inf = NaN
    rational<int> r16 = inf / inf;
    std::cout << "Inf / Inf = " << r16 << " (Expected: NaN)\n";


    return 0;
}
