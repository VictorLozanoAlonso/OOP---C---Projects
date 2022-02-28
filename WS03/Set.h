// Workshop 3 - Templates
// Victor Lozano - 2021/09/30
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS03_P1_SET_H
#define WS03_P1_SET_H
#include <iostream>

namespace sdds {
    template<size_t N, typename T>
    class Set {
        T m_data[N] {};
        size_t m_cnt {0u};
    public:
        size_t size() const
        {
            return m_cnt;
        }
        const T& get(size_t idx) const{
            return m_data[idx];
        }
        void operator+=(const T& item){
            if(m_cnt < N){
                m_data[m_cnt++] = item;
            }
        }
    };
}

#endif //WS03_P1_SET_H
