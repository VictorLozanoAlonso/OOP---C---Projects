// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "Workstation.h"


namespace sdds{
    std::deque<CustomerOrder> pending {};
    std::deque<CustomerOrder> completed {};
    std::deque<CustomerOrder> incomplete {};
    Workstation::Workstation(const std::string &reference) : Station(reference){
        m_pNextStation = nullptr;
    }
    void Workstation::fill(std::ostream &os) {
        if (m_orders.size() != 0) {
            m_orders.front().fillItem(*this, os);
        }
    }
    bool Workstation::attemptToMoveOrder() {
        if(m_orders.size() > 0){
            if(m_orders.front().isItemFilled(getItemName())) {
                if (m_pNextStation == nullptr) {
                    if (m_orders.front().isFilled()) {
                        completed.push_back(std::move(m_orders.front()));
                    } else {
                        incomplete.push_front(std::move(m_orders.front()));
                    }
                } else {
                        *m_pNextStation += std::move(m_orders.front());
                }
                    m_orders.pop_front();
                    return true;
                }
            if(getQuantity() == 0){
                if(m_pNextStation == nullptr){
                    incomplete.push_front(std::move(m_orders.front()));
                } else{
                    *m_pNextStation += std::move(m_orders.front());
                }
                m_orders.pop_front();
                return true;
            }
        }
        return false;
    }
    void Workstation::setNextStation(Workstation *station) {
        m_pNextStation = station;
    }
    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }
    void Workstation::display(std::ostream &os) const {
        os << getItemName() << " --> ";
        if(m_pNextStation != nullptr)
            os << m_pNextStation->getItemName();
        else
            os << "End of Line";
        os << std::endl;
    }
    Workstation& Workstation::operator+=(CustomerOrder &&newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}