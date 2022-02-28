// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Victor Lozano - 2021/09/15
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <cstring>

size_t g_sysClock = 0;
namespace sdds{
    Event::Event() {
        m_startTime = 0;
        m_description = nullptr;
    }
    Event::~Event() {
        delete [] m_description;
    }
    void Event::display() const {
        static int counter {1};
        std::cout.width(2);
        std::cout << counter;
        std::cout << ". ";
        counter++;
        if(m_description != nullptr) {
            std::cout.width(2);
            std::cout.fill('0');
            std::cout << (m_startTime / 60) / 60;
            std::cout << ":";
            std::cout.width(2);
            std::cout.fill('0');
            std::cout << (m_startTime % (60 * 60)) / 60;
            std::cout << ":";
            std::cout.width(2);
            std::cout.fill('0');
            std::cout << m_startTime % 60;
            std::cout.fill(' ');
            std::cout << " => ";
            std::cout << m_description;
        }
        else {
            std::cout << "| No Event |";
        }
        std::cout << std::endl;
    }
    void Event::set(const char *desc) {
        m_startTime = ::g_sysClock;
        if(desc){
            delete [] m_description;
            m_description = new char[strlen(desc) + 1];
            strcpy(m_description, desc);
        }
        else {
            delete [] m_description;
            m_description = nullptr;
        }
    }
    Event::Event(const Event &src) {
        if(src.m_description != nullptr){
            m_description = new char[strlen(src.m_description) + 1];
            strcpy(m_description, src.m_description);
            m_startTime = src.m_startTime;
        } else{
            m_description = nullptr;
            m_startTime = 0;
        }
    }
    Event & Event::operator=(const Event &src) {
        if(this != &src){
            if (src.m_description != nullptr) {
                delete[] m_description;
                m_description = new char[strlen(src.m_description) + 1];
                strcpy(m_description, src.m_description);
            }
            m_startTime = src.m_startTime;
        }
        return *this;
    }
}