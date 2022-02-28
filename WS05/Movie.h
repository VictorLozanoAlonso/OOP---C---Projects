// Workshop 5 - Functions and Error Handling
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS05_MOVIE_H
#define WS05_MOVIE_H

#include <iostream>

namespace sdds {
    class Movie {
        std::string movieTitle = "";
        size_t movieYear = 0;
        std::string movieDescription = "";
        void trim(std::string &str) const;
    public:
        Movie() {}
        const std::string &title() const;
        Movie(const std::string &strMovie);
        template<class T>
        void fixSpelling(T &spellChecker) {
            spellChecker(movieTitle);
            spellChecker(movieDescription);
        }
        friend std::ostream &operator<<(std::ostream &out, const Movie &theBook);
    };
}

#endif //WS05_MOVIE_H
