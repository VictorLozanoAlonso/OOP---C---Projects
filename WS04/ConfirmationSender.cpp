// Workshop 4 - Containers
// Victor Lozano - 2021/10/08
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "ConfirmationSender.h"

namespace sdds {
    ConfirmationSender::~ConfirmationSender() {
        delete [] cs_reservations;
        cs_reservations = nullptr;
    }
    ConfirmationSender::ConfirmationSender(const ConfirmationSender &src) {
        *this = src;
    }
    ConfirmationSender & ConfirmationSender::operator=(const ConfirmationSender &src) {
        if (this != &src) {
            delete[] cs_reservations;
            cs_reservations = new const sdds::Reservation *[src.cs_nOfReservations];
            for (size_t i = 0u; i < src.cs_nOfReservations; i++) {
                cs_reservations[i] = src.cs_reservations[i];
            }
            cs_nOfReservations = src.cs_nOfReservations;
        }
        return *this;
    }
    ConfirmationSender::ConfirmationSender(ConfirmationSender &&src) {
        *this = std::move(src);
    }
    ConfirmationSender & ConfirmationSender::operator=(ConfirmationSender &&src) {
        if (this != &src) {
            delete[] cs_reservations;
            cs_reservations = new const sdds::Reservation *[src.cs_nOfReservations];
            for (size_t i = 0u; i < src.cs_nOfReservations; i++) {
                cs_reservations[i] = src.cs_reservations[i];
            }
            for (size_t i = 0u; i < cs_nOfReservations; i++) {
                src.cs_reservations[i] = nullptr;
            }
            cs_nOfReservations = src.cs_nOfReservations;
            src.cs_nOfReservations = 0u;
        }
        return *this;
    }
    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res) {
        bool isIncluded = false;
        for (size_t i = 0u; i < cs_nOfReservations && !isIncluded; i++) {
            if (cs_reservations[i] == &res)
                isIncluded = true;
        }
        if (!isIncluded) {
            const Reservation **tempReserv = nullptr;
            tempReserv = new const Reservation *[cs_nOfReservations + 1];
            for (auto i = 0u; i < cs_nOfReservations; i++) {
                tempReserv[i] = cs_reservations[i];
            }
            tempReserv[cs_nOfReservations] = &res;
            cs_nOfReservations++;
            delete[] cs_reservations;
            cs_reservations = tempReserv;
        }
        return *this;
    }

    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res) {
        if (cs_nOfReservations > 0) {
            bool isIncluded = false;
            for (size_t i = 0u; i < cs_nOfReservations && !isIncluded; i++) {
                if (cs_reservations[i] == &res) {
                    isIncluded = true;
                }
            }
            if(isIncluded) {
                size_t j = 0u;
                const Reservation **tempReserv = nullptr;
                tempReserv = new const Reservation *[cs_nOfReservations - 1];
                for(auto i = 0u; i < cs_nOfReservations; i++){
                    if(cs_reservations[i] != &res){
                        tempReserv[j] = cs_reservations[i];
                        j++;
                    }
                }
                cs_nOfReservations--;
                delete[] cs_reservations;
                cs_reservations = tempReserv;
            }
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const ConfirmationSender &cs) {
        out << "--------------------------" << std::endl <<
            "Confirmations to Send" << std::endl <<
            "--------------------------" << std::endl;
        if(cs.cs_nOfReservations > 0) {
            for (size_t i = 0u; i < cs.cs_nOfReservations; i++) {
                    out << *cs.cs_reservations[i];
            }
        } else{
            out << "There are no confirmations to send!" << std::endl;
        }
        out << "--------------------------" << std::endl;
        return out;
    }
}