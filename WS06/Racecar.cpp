// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Racecar.h"

namespace sdds {
    Racecar::Racecar(std::istream &in) : Car(in){
        in >> m_booster;
        in.ignore();
    }
    void Racecar::display(std::ostream &out) const {
        Car::display(out);
        out << "*";
    }
    double Racecar::topSpeed() const {
        return (m_booster + 1) * Car::topSpeed();
    }
}