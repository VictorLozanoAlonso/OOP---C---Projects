// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <vector>
#include "Autoshop.h"

namespace sdds{
    Autoshop::~Autoshop() {
        std::vector<Vehicle *>::iterator i;
        for(i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            delete *i;
            *i = nullptr;
        }
    }
    Autoshop & Autoshop::operator+=(Vehicle *theVehicle) {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream &out) const {
        out << "--------------------------------" << std::endl
            << "| Cars in the autoshop!        |" << std::endl
            << "--------------------------------" << std::endl;
        std::vector<Vehicle *>::const_iterator i;
        for(i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i)->display(out);
            out << std::endl;
        }
        out << "--------------------------------" << std::endl;
    }
}