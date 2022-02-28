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

#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
    // start timer
    //
    void TimedEvents::startClock()
    {
        ts = std::chrono::steady_clock::now();
    }

    // stop timer
    //
    void TimedEvents::stopClock()
    {
        te = std::chrono::steady_clock::now();
    }

    // record an event
    //
    void TimedEvents::addEvent(const char* msg)
    {
        auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
        if (nEvents < MAX_EVENTS)
        {
            this->events[nEvents].msg = msg;
            this->events[nEvents].units = "nanoseconds";
            this->events[nEvents].duration = ms;
            nEvents++;
        }
    }

    // report the set of times recorded
    //
    std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
    {
        out << "--------------------------\n";
        out << "Execution Times:\n";
        out << "--------------------------\n";
        for (int i = 0; i < events.nEvents; i++)
            out << std::setw(21) << std::left
                << events.events[i].msg << ' ' << std::setw(13) << std::right
                << events.events[i].duration.count() << ' '
                << events.events[i].units << '\n';
        out << "--------------------------\n";
        return out;
    }
}