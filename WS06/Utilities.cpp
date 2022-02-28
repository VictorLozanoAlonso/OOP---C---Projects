// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream &in) {
        char buffer;
        Vehicle* temp {nullptr};
        in >> buffer;
        if(in.good()) {
            in.ignore(1000, ',');
            if(buffer == 'c' || buffer == 'C')
                temp = new Car(in);
            else if(buffer == 'r' || buffer == 'R')
                temp = new Racecar(in);
            else
                throw std::string("Unrecognized ")
                      + "record type: "
                      + "[" + buffer + "]";
        }
        return temp;
    }
}