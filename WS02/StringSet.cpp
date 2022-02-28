// Workshop 2 - Copy and Move Semantics
// Victor Lozano - 2021/09/25
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <utility>
#include <fstream>
#include "StringSet.h"

namespace sdds{
    StringSet::StringSet() : m_strings(nullptr), m_cnt(0){};
    StringSet::StringSet(const std::string& filename) {
        std::ifstream f(filename.c_str());
        m_cnt = 1;
        if (!f){
            return;
        }
        do {
            char c = f.get();
            if (c == ' ')
                m_cnt++;
        }while (!f.eof());
        f.clear();
        f.seekg(std::ios::beg);
        m_strings = new std::string[m_cnt];
        for (auto i = 0u; i < m_cnt; i++){
            std::getline(f, m_strings[i], ' ');
        }
    }
    StringSet::StringSet(const StringSet & src) {
        *this = src;
    }
    StringSet & StringSet::operator=(const StringSet &src) {
        if (this != &src){
            m_cnt = src.m_cnt;
            delete [] m_strings;
            m_strings = nullptr;
            if(m_cnt != 0){
                m_strings = new std::string[m_cnt];
                for (auto i = 0u; i < m_cnt; i++){
                    m_strings[i] = src.m_strings[i];
                }
            }
        }
        return *this;
    }
    StringSet::StringSet(StringSet && src) {
        *this = std::move(src);
    }
    StringSet & StringSet::operator=(StringSet && src) {
        if (this != &src){
            m_cnt = src.m_cnt;
            src.m_cnt = 0;
            delete [] m_strings;
            m_strings = nullptr;
            if(m_cnt != 0){
                m_strings = new std::string[m_cnt];
                for (auto i = 0u; i < m_cnt; i++){
                    m_strings[i] = src.m_strings[i];
                }
            }
            delete [] src.m_strings;
            src.m_strings = nullptr;
        }
        return *this;
    }
    StringSet::~StringSet() {
        delete [] m_strings;
    }
    std::string StringSet::operator[](size_t idx) {
        if (idx < m_cnt)
            return m_strings[idx];
        return "";
    }
}