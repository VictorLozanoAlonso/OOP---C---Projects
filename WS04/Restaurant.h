// Workshop 4 - Containers
// Victor Lozano - 2021/10/08
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS04_P2_RESTAURANT_H
#define WS04_P2_RESTAURANT_H

#include<iostream>

namespace sdds {
    class Reservation;

    class Restaurant {
        Reservation* m_reservations {nullptr};
        size_t nOfReservations {0u};
    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& src);
        Restaurant& operator=(const Restaurant& src);
        Restaurant(Restaurant&& src);
        Restaurant& operator=(Restaurant&& src);
        ~Restaurant();
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& out, const Restaurant& res);
    };

}
#endif //WS04_P2_RESTAURANT_H
