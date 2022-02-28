// Workshop 4 - Containers
// Victor Lozano - 2021/10/08
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Reservation.h"

namespace sdds{
    void Reservation::trim(std::string &str) const {
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; ++i);
        str = str.substr(i);

        for(i = str.length(); i > 0 && str[i - 1] == ' '; --i);
        str = str.substr(0, i);
    }

    // The string has the format (assume correct format)
    // ID : NAME , EMAIL , PARTY SIZE , DAY , TIME
    Reservation::Reservation(const std::string &res) {
        size_t posS = 0;
        size_t posE = res.find(':');
        this->trim(m_id = res.substr(posS, posE - posS));

        posS = posE + 1;
        posE = res.find(',', posS);
        this->trim(m_name = res.substr(posS, posE - posS));

        posS = posE + 1;
        posE = res.find(',', posS);
        this->trim(m_email = res.substr(posS, posE - posS));

        posS = posE + 1;
        posE = res.find(',', posS);
        m_partysize = std::stoi(res.substr(posS, posE - posS));

        posS = posE + 1;
        posE = res.find(',', posS);
        m_day = std::stoi(res.substr(posS, posE - posS));

        posS = posE + 1;
        posE = res.find(',', posS);
        m_time = std::stoi(res.substr(posS, posE - posS));
    }

    // Breakfast: 6:00 -- 9:00
    // Lunch: 11:00 -- 15:00
    // Dinner: 17:00 -- 21:00
    std::ostream& operator<<(std::ostream& out, const Reservation& res){
        std::string email = "<" + res.m_email + ">";
        out << "Reservation " << std::setw(10) << res.m_id << ": "
            << std::setw(20) << std::right << res.m_name << "  "
            << std::setw(20) << std::left << email << std::right;
        if (6 <= res.m_time && res.m_time <= 9)
            out << "    Breakfast ";
        else if (11 <= res.m_time && res.m_time <= 15)
            out << "    Lunch ";
        else if (17 <= res.m_time && res.m_time <= 21)
            out << "    Dinner ";
        else
            out << "    Drinks ";
        out << "on day " << res.m_day << " @ " << res.m_time
            << ":00 for " << res.m_partysize
            << (res.m_partysize > 1 ? " people" : " person") << ".\n";
        return out;
    }
}