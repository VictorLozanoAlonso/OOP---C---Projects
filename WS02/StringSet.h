// Workshop 2 - Copy and Move Semantics
// Victor Lozano - 2021/09/25
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef W2_P1_CPP_STRINGSET_H
#define W2_P1_CPP_STRINGSET_H
#include <string>

namespace sdds {
    class StringSet {
        std::string* m_strings {nullptr};
        size_t m_cnt {0};
    public:
        StringSet();
        StringSet(const std::string&);
        StringSet(const StringSet&);
        StringSet& operator=(const StringSet&);
        StringSet(StringSet&&);
        StringSet& operator=(StringSet&&);
        ~StringSet();
        size_t size() const {return m_cnt;};
        std::string operator[](size_t idx);
    };
}
#endif //W2_P1_CPP_STRINGSET_H
