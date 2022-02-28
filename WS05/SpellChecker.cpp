// Workshop 5 - Functions and Error Handling
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <fstream>
#include "SpellChecker.h"

namespace sdds {
    SpellChecker::SpellChecker(const char *filename) {
        try {
            std::ifstream file(filename);
            if (!file)
                throw "Bad file name!";
            std::string line;
            size_t i = 0u;
            do {
                std::getline(file, line);
                if (line.length() > 0) {
                    size_t posSpace = line.find(' ');
                    m_badWords[i] = line.substr(0, posSpace);
                    while (line[posSpace] == ' ')
                        posSpace++;
                    m_goodWords[i] = line.substr(posSpace, line.length());
                    i++;
                }
            } while (file);
            file.close();
        } catch (const char msg) {
            std::cout << msg << std::endl;
        }
    }

    void SpellChecker::operator()(std::string &text) {
        for (auto i = 0u; i < 6; i++) {
            size_t position = text.find(m_badWords[i]);
            if (position != std::string::npos) {
                do{
                    text.replace(position, m_badWords[i].length(), m_goodWords[i]);
                    misspelledCounter[i]++;
                    position = text.find(m_badWords[i]);
                }while(position != std::string::npos);
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream &out) const {
        out << "Spellchecker Statistics" << std::endl;
        for (auto i = 0u; i < 6; i++) {
            out.width(15);
            out << std::right << m_badWords[i] << ": "
                << misspelledCounter[i] << " replacements" << std::endl;
        }
    }
}