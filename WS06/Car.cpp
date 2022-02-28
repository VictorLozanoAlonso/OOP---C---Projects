// Workshop 6 - STL Containers
// Victor Lozano - 2021/11/07
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "Car.h"

namespace sdds{
    void Car::trim(std::string &str) const {
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; ++i);
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
        str = str.substr(0, i);
    }


    Car::Car(std::istream &car) {
        std::string strCar;
        getline(car, strCar, ',');
        this->trim(strCar);
        m_maker = strCar;
        getline(car, strCar, ',');
        if (strCar.length() == 0 || strCar == " ")
            m_condition = "n";
        else {
            this->trim(strCar);
            if (strCar == "n" || strCar == "u" || strCar == "b")
                m_condition = strCar;
            else
                throw std::string("Invalid record!");
        };
        car >> m_topSpeed;
        if(car.fail()){
            car.clear();
            throw std::string("Invalid record!");
        }
        car.ignore();
    }
    double Car::topSpeed() const {
        return m_topSpeed;
    }
    std::string Car::condition() const {
        std::string condition;
        if(m_condition == "n") {
            condition = "new";
        }
        if(m_condition == "u") {
            condition = "used";
        }
        if(m_condition == "b") {
            condition = "broken";
        }
        return condition;
    }
    void Car::display(std::ostream &carOut) const {
        carOut << "| " << std::right << std::setw(10) << m_maker;
        carOut << " | " << std::left << std::setw(6) << condition();
        carOut << " | " << std::right << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }
}