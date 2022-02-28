// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "Station.h"
#include <iomanip>

namespace sdds{
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;
    Station::Station(const std::string &item) {
        Utilities aux;
        size_t next_pos {0u};
        bool more{true};
        if(more){
            m_name_station = aux.extractToken(item, next_pos, more);
        }
        if(more){
            m_serialNumber = std::stoi(aux.extractToken(item, next_pos, more));
        }
        if(more){
            m_stock = std::stoi(aux.extractToken(item, next_pos, more));
        }
        if(aux.getFieldWidth() > m_widthField)
            m_widthField = aux.getFieldWidth();
        if(more){
            m_description = aux.extractToken(item, next_pos, more);
        }
        m_id_station = ++id_generator;
    }
    const std::string & Station::getItemName() const {
        return m_name_station;
    }
    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }
    size_t Station::getQuantity() const {
        return m_stock;
    }
    void Station::updateQuantity() {
        if(m_stock > 0)
            m_stock--;
    }
    void Station::display(std::ostream &os, bool full) const {
        if(full){
            os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id_station << "] Item: "
               << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name_station
               << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber
               << std::setfill(' ') << std::left << "] Quantity: "
               << std::setw(m_widthField) << m_stock << " Description: "
               << m_description << std::endl;
        } else {
            os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id_station << "] Item: "
               << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name_station
               << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber
               << std::setfill(' ') << std::left << "]" << std::endl;
        }
    }
}