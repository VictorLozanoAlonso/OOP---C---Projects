// Workshop 3 - Templates
// Victor Lozano - 2021/09/30
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS03_P1_PAIR_H
#define WS03_P1_PAIR_H

namespace sdds {
    template<typename V, typename K>
    class Pair {
        K m_key;
        V m_value;
    public:
        Pair() : m_key{}, m_value {}
        {
        }
        Pair(const K& key, const V& value) : m_key{key}, m_value{value}
        {
        }
        const K& key() const{
            return m_key;
        }
        const V& value() const {
            return m_value;
        }
        virtual void display (std::ostream& os) const{
            os << m_key << " : " << m_value << std::endl;
        };
    };
    template<typename V, typename K>
    std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
    {
        pair.display(os);
        return os;
    }
}
#endif //WS03_P1_PAIR_H
