// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS06_CAR_H
#define WS06_CAR_H

#include <iostream>
#include <iomanip>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle{
        std::string m_maker{};
        std::string m_condition{};
        double m_topSpeed{0.0};
        void trim(std::string &str) const;
    public:
        Car(std::istream& car);
        ~Car(){}
        virtual double topSpeed() const;
        virtual void display(std::ostream&) const;
        virtual std::string condition() const;
    };
}
#endif //WS06_CAR_H
