// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS06_RACECAR_H
#define WS06_RACECAR_H
#include "Car.h"

namespace sdds {
    class Racecar : public Car{
        double m_booster{0.0};
    public:
        Racecar(std::istream& in);
        virtual void display(std::ostream& out) const;
        virtual double topSpeed() const;
    };

}
#endif //WS06_RACECAR_H
