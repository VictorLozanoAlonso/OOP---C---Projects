// Workshop 4 - Containers
// Victor Lozano - 2021/10/08
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS04_P2_CONFIRMATIONSENDER_H
#define WS04_P2_CONFIRMATIONSENDER_H

#include<iostream>
#include "Reservation.h"
namespace sdds {

    class ConfirmationSender {
        const Reservation** cs_reservations {nullptr};
        size_t cs_nOfReservations {0u};
    public:
        ConfirmationSender(){};
        ~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& src);
        ConfirmationSender& operator=(const ConfirmationSender& src);
        ConfirmationSender(ConfirmationSender&& src);
        ConfirmationSender& operator=(ConfirmationSender&& src);
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& out, const ConfirmationSender& cs);
    };
}

#endif //WS04_P2_CONFIRMATIONSENDER_H
