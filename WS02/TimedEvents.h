// Workshop 2 - Copy and Move Semantics
// Victor Lozano - 2021/09/25
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel
// 2020/01/14 - Cornel
// 2021/01/14 - Chris
#ifndef WS02_P1_TIMEDEVENTS_H
#define WS02_P1_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
    const int MAX_EVENTS = 10;
    class TimedEvents {
        int nEvents{ 0 };
        std::chrono::steady_clock::time_point ts;
        std::chrono::steady_clock::time_point te;
        struct Event {
            std::string msg{};
            std::string units{};
            std::chrono::steady_clock::duration duration{};
        } events[MAX_EVENTS];
    public:
        TimedEvents() {};
        void startClock();
        void stopClock();
        void addEvent(const char*);
        friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
    };
}
#endif //WS02_P1_TIMEDEVENTS_H
