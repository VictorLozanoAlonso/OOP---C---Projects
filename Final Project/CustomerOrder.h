// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef MS02_CUSTOMERORDER_H
#define MS02_CUSTOMERORDER_H

#include <iostream>
#include "Station.h"

namespace sdds {
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};
        Item(const std::string& src) : m_itemName(src) {};
    };
    class CustomerOrder {
        std::string m_name;
        std::string m_product;
        size_t m_cntItem;
        Item** m_lstItem;
        static size_t m_widthField;
    public:
        CustomerOrder();
        CustomerOrder(const std::string& customer);
        CustomerOrder(const CustomerOrder& src);
        CustomerOrder& operator=(const CustomerOrder& src) = delete;
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& source) noexcept;
        ~CustomerOrder();
        bool isFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}

#endif //MS02_CUSTOMERORDER_H
