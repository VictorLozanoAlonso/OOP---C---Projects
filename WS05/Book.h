// Workshop 5 - Functions and Error Handling
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS05_BOOK_H
#define WS05_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
    class Book {
        std::string m_author = "";
        std::string m_title = "";
        std::string m_country = "";
        std::string m_description = "";
        double m_price = 0;
        size_t m_year = 0u;
        void trim(std::string &str) const;

    public:
        Book() {}
        Book(const std::string &strBook);
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;
        double &price();
        void setPrice(const double price);

        template<class T>
        void fixSpelling(T &spellChecker) {
            spellChecker(m_description);
        }
        friend std::ostream &operator<<(std::ostream &out, const Book &theBook);
    };
}

#endif //WS05_BOOK_H
