// Workshop 5 - Functions and Error Handling
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Movie.h"

namespace sdds {
    const std::string &Movie::title() const {
        return movieTitle;
    }

    void Movie::trim(std::string &str) const {
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; ++i);
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
        str = str.substr(0, i);
    }

    Movie::Movie(const std::string &strMovie) {
        size_t posS = 0;
        size_t posE = strMovie.find(',');
        this->trim(movieTitle = strMovie.substr(posS, posE - posS));
        posS = posE + 1;
        posE = strMovie.find(',', posS);
        movieYear = std::stoi(strMovie.substr(posS, posE - posS));
        posS = posE + 1;
        this->trim(movieDescription = strMovie.substr(posS));
    }

    std::ostream &operator<<(std::ostream &out, const Movie &theMovie) {
        out << std::setw(40) << std::right << theMovie.movieTitle << " | "
            << std::setw(4) << theMovie.movieYear << " | "
            << theMovie.movieDescription << std::endl;
        return out;
    }
}