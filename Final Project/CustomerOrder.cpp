// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"

namespace sdds{
    size_t CustomerOrder::m_widthField = 0u;
    CustomerOrder::CustomerOrder() {
        m_name = "";
        m_product = "";
        m_cntItem = 0u;
        m_lstItem = nullptr;
    }
    CustomerOrder::CustomerOrder(const std::string &customer) : CustomerOrder(){
        Utilities aux;
        size_t next_pos {0u};
        bool more{true};
        if(more){
            m_name = aux.extractToken(customer, next_pos, more);
        }
        if(more){
            m_product = aux.extractToken(customer, next_pos, more);
        }
        while(more) {
            Item **temp = new Item *[m_cntItem + 1];
            for (size_t i = 0u; i < m_cntItem; i++) {
                temp[i] = m_lstItem[i];
            }
            delete[] m_lstItem;
            m_lstItem = temp;
            m_lstItem[m_cntItem] = new Item(aux.extractToken(customer, next_pos, more));
            if(m_widthField < aux.getFieldWidth())
                m_widthField = aux.getFieldWidth();
            m_cntItem++;
        }
    }
    CustomerOrder::CustomerOrder(const CustomerOrder &src) {
        throw "Copy const not allowed";
    }
    CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept : CustomerOrder(){
        *this = std::move(src);
    }
    CustomerOrder & CustomerOrder::operator=(CustomerOrder &&src) noexcept {
        if (this != &src) {
            for (size_t i = 0; i < m_cntItem; i++)
                delete m_lstItem[i];
            delete[] m_lstItem;
            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;
            m_lstItem = src.m_lstItem;
            src.m_name = "";
            src.m_product = "";
            src.m_lstItem = nullptr;
            src.m_cntItem = 0u;
        }
        return *this;
    }
    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; i++)
            delete m_lstItem[i];
        delete[] m_lstItem;
    }
    bool CustomerOrder::isFilled() const {
        auto filled = [](Item* i){
            return i->m_isFilled;
        };
        return std::all_of(m_lstItem, m_lstItem+m_cntItem, filled);
    }
    bool CustomerOrder::isItemFilled(const std::string &itemName) const {
        bool fill_result{true};
        for(size_t i = 0; i < m_cntItem; i++){
            if (m_lstItem[i]->m_itemName == itemName)
                fill_result = m_lstItem[i]->m_isFilled;
        }
        return fill_result;
    }
    void CustomerOrder::fillItem(Station &station, std::ostream &os) {
        auto fill = [&](Item* i){
            if (i->m_itemName == station.getItemName()) {
                if (station.getQuantity() > 0) {
                    station.updateQuantity();
                    i->m_serialNumber = station.getNextSerialNumber();
                    i->m_isFilled = true;
                    os << "    Filled " << m_name << ", " << m_product << " [" << i->m_itemName << "]" << std::endl;
                } else {
                    os << "    Unable to fill " << m_name << ", " << m_product << " [" << i->m_itemName << "]" << std::endl;
                }
            }
        };
        std::for_each(m_lstItem, m_lstItem + m_cntItem, fill);
    }
    void CustomerOrder::display(std::ostream &os) const {
        auto print = [&](const Item* item)
        {
            os << "[" << std::setfill('0') << std::setw(6) << item->m_serialNumber << "] " <<
               std::setfill(' ') << std::setw(m_widthField) << std::left << item->m_itemName
               << " - " << std::right;
            if (item->m_isFilled)
                os << "FILLED" << std::endl;
            else
                os << "TO BE FILLED" << std::endl;
        };
        os << m_name << " - " << m_product << std::endl;
        std::for_each(m_lstItem, m_lstItem + m_cntItem, print);
    }
}