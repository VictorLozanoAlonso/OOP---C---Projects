// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef MS01_STATION_H
#define MS01_STATION_H
#include <iostream>
#include <string>
#include "Utilities.h"

namespace sdds {
    class Station {
        int m_id_station {0};
        std::string m_name_station {};
        std::string m_description {};
        size_t m_serialNumber {0u};
        size_t m_stock {0u};
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string &item);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif //MS01_STATION_H
