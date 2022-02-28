// Workshop 4 - Containers
// Victor Lozano - 2021/10/08
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS04_P2_RESERVATION_H
#define WS04_P2_RESERVATION_H
#include <string>
#include <ostream>
namespace sdds {
    class Reservation {
        std::string m_id = "";
        std::string m_name = "";
        std::string m_email = "";
        size_t m_partysize = 0;
        size_t m_day = 0;
        size_t m_time = 0;
        void trim(std::string& str) const;

    public:
        Reservation() = default;
        Reservation(const std::string& res);
        void update (size_t day, size_t time) {m_day = day; m_time = time;}
        friend std::ostream& operator<<(std::ostream& out, const Reservation& res);
    };

}

#endif //WS04_P2_RESERVATION_H
