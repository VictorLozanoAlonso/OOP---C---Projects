// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "Utilities.h"

namespace sdds{
    char Utilities::m_delimiter = ',';
    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more) {
        size_t end_pos {0u};
        std::string token {};
        end_pos = str.find(m_delimiter, next_pos);
        if (end_pos != std::string::npos){
            if (str[next_pos] == getDelimiter()) {
                more = false;
                throw "Error: Delimiter found in start position";
            }
            token = str.substr(next_pos, end_pos - next_pos);
            next_pos = end_pos + 1;
            more = true;
        } else {
            token = str.substr(next_pos, str.length());
            more = false;
        }
        if (m_widthField < token.length())
            setFieldWidth(token.length());
        return token;
    }
    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}