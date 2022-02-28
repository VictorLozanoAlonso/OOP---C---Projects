// Workshop 5 - Functions and Error Handling
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS05_SPELLCHECKER_H
#define WS05_SPELLCHECKER_H

#include <iostream>

namespace sdds {
    class SpellChecker {
        std::string m_badWords[6]{{""}};
        std::string m_goodWords[6]{{""}};
        size_t misspelledCounter[6]{0u};
    public:
        SpellChecker() {}

        SpellChecker(const char *filename);

        void operator()(std::string &text);

        void showStatistics(std::ostream &out) const;
    };
}

#endif //WS05_SPELLCHECKER_H
