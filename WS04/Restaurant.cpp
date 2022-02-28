// Workshop 4 - Containers
// Victor Lozano - 2021/10/08
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "Reservation.h"
#include "Restaurant.h"

namespace sdds {
    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt) {
        m_reservations = new Reservation [cnt];
       for (size_t i = 0u; i < cnt; i++) {
           m_reservations[i] = *reservations[i];
       }
        nOfReservations = cnt;
    }

    Restaurant::Restaurant(const Restaurant &src) {
        *this = src;
    }

    Restaurant &Restaurant::operator=(const Restaurant &src) {
        if (this != &src) {
            delete[] m_reservations;
            m_reservations = new Reservation[src.nOfReservations];
            for (size_t i = 0u; i < src.nOfReservations; i++) {
                m_reservations[i] = src.m_reservations[i];
            }
            nOfReservations = src.nOfReservations;
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant &&src) {
        *this = std::move(src);
    }

    Restaurant &Restaurant::operator=(Restaurant &&src) {
        if (this != &src) {
            delete[] m_reservations;
            m_reservations = new Reservation[src.nOfReservations];
            for (size_t i = 0u; i < src.nOfReservations; i++) {
                m_reservations[i] = src.m_reservations[i];
            }
            delete [] src.m_reservations;
            src.m_reservations = nullptr;
            nOfReservations = src.nOfReservations;
            src.nOfReservations = 0u;
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        delete[] m_reservations;
        m_reservations = nullptr;
    }

    size_t Restaurant::size() const {
        return nOfReservations;
    }

    std::ostream &operator<<(std::ostream &out, const Restaurant &res) {
        static size_t cnt {1u};
            out << "--------------------------" << std::endl <<
                "Fancy Restaurant (" << cnt << ")" << std::endl <<
                "--------------------------" << std::endl;
        if(res.nOfReservations > 0) {
            for (size_t i = 0u; i < res.nOfReservations; i++) {
                out << res.m_reservations[i];
            }
        } else{
            out << "This restaurant is empty!" << std::endl;
        }
        out << "--------------------------" << std::endl;
        cnt++;
        return out;
    }
}