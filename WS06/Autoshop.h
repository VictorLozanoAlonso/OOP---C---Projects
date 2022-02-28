// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS06_AUTOSHOP_H
#define WS06_AUTOSHOP_H

#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles;
    public:
        ~Autoshop();
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        template<typename T>
        void select(T test, std::list<const Vehicle*>& vehicles){
            for(auto it = m_vehicles.cbegin(); it != m_vehicles.cend(); ++it){
                if (test(*it))
                    vehicles.push_back(*it);
            }
        }
    };
}

#endif //WS06_AUTOSHOP_H
