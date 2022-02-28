// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef MS03_LINEMANAGER_H
#define MS03_LINEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Workstation.h"

namespace sdds {
    class LineManager {
        std::vector<Workstation*> activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;
    public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void linkStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };

}
#endif //MS03_LINEMANAGER_H
