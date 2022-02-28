// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Victor Lozano - 2021/09/15
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS01_EVENT_H
#define WS01_EVENT_H

#include <iostream>

extern size_t g_sysClock;

namespace sdds{
    class Event {
        char* m_description;
        size_t m_startTime;
    public:
        Event();
        void display() const;
        void set(const char* desc = nullptr);
        Event(const Event&);
        Event& operator=(const Event&);
        ~Event();
    };
}

#endif //WS01_EVENT_H
