#pragma once
#include <iostream>
#include <concepts>
#include <numeric> 

template<typename I> requires std::integral<I>
class rational {
private: 
    I num_;
    I den_;

    /* Funzione di semplificazione */
    void semplify() {
    I MCD = 1;
    if (den_==0)  return ;
    MCD = std::gcd(num_,den_);      // uso il massimo comun divisore 
    num_ = num_ / MCD;
    den_ = den_ / MCD;
    };

public:
    // Costruttore di Default
    rational() {
        num_ = 0;
        den_ = 1;
        semplify();
    };
    // Costruttore definito dall'Utente
    rational(const I& num, const I& den) {
        num_ = num;
        den_ = den; 
        if (den_ < 0) {
            num_ = -num;
            den_ = -den;
        }
        // Controllo Inf e NaN
        if (den_==0) {
            if (num_ == 0) {
                // caso NaN
                return;
            }            
            if (num_ < 0) {
                // caso Inf
                num_ = -1;
            }
            else {
                num_ = 1;
            }
        }
        semplify();
    };

    /* Restituiscono i valori di num e den */
    I num() const { return num_; }
    I den() const { return den_; }
    
    /* OPERATORE * */
    rational& operator*=(const rational& other) {
        // Controllo caso NaN
        if ((den_==0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        } 
        // Controllo caso Inf * 0 = NaN
        if ((den_ == 0 && other.num_ == 0) || (other.den_ == 0 && num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }
        
        // Controllo caso Infinito (uno dei due è Inf, calcolo del segno)
        if (den_ == 0 || other.den_ == 0) {
            // Se i segni sono uguali (+ e +, oppure - e -), l'Infinito è positivo
            if ((num_ > 0 && other.num_ > 0) || (num_ < 0 && other.num_ < 0)) {
                num_ = 1;
            } 
            // Se i segni sono diversi, l'Infinito è negativo
            else {
                num_ = -1;
            }
            den_ = 0;
            return *this;
        }
        // fine controllo // 
        num_ *= other.num_;
        den_ *= other.den_;
        semplify();
        return *this;
    }
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    /* OPERATORE +*/
    rational& operator+=(const rational& s) {
        I mcm = 1;
        // Controllo caso Inf & NaN
        if ((den_==0 && num_ == 0) || (s.den_ == 0 && s.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }
    
        if (den_==0 || s.den_ == 0)  {
            if (den_ == 0 && s.den_ == 0 && num_ != s.num_) {
            // Inf + (-Inf) = NaN
            num_ = 0;
            den_ = 0;
            return *this;
        }
            if (den_ != 0) { 
                if (s.num_ > 0) {
                    num_ = 1;
                }
                else{
                    num_ = -1;
                }
            }
            den_ = 0;
            return *this;
        }
        // fine controllo // 

        mcm = std::lcm(den_, s.den_);  // minimo comune multiplo
        num_ = num_*mcm/den_ + s.num_*mcm/s.den_;
        den_ = mcm;
        semplify();
        return *this;
    }

    rational operator+(const rational& s) const {
        rational ret = *this;
        ret += s;
        return ret;
    }

    /* MENO UNARIO */
    rational operator-() const {
        return rational(-num_, den_);
    }
    
    /* Sottrazione e assegnamento */
    rational& operator-=(const rational& s) {
        *this += (-s); 
        return *this;
    }

    /* Sottrazione semplice */
    rational operator-(const rational& s) const {
        rational ret = *this;
        ret -= s;
        return ret;
    }

    /* Operatore divisione Unario */
    rational inverse() const {
        return rational(den_,num_);
    }

    /* Operatore divisione /= */
    rational& operator/=(const rational& d)  {
        *this *= d.inverse();
        return *this;
    }
    /* Operatore divisione classico*/
    rational operator/(const rational& d) const {
        rational ret = *this;
        ret /= d;
        return ret;
    }

};

template<typename I> requires std::integral<I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& rat)
{
        if (rat.den() == 0) {
        if (rat.num() == 0) {
            os << "NaN";
        } else if (rat.num() > 0) {
            os << "+Inf";
        } else {
            os << "-Inf";
        }
    } else {
        os << rat.num() << "/" << rat.den();
    }
    return os;
}