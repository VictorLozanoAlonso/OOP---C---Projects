// Workshop 3 - Templates
// Victor Lozano - 2021/09/30
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef PAIRSUMMABLE_H_SETSUMMABLE_H
#define PAIRSUMMABLE_H_SETSUMMABLE_H
#include <string>
#include "Set.h"

namespace sdds{
    template<size_t N, typename T>
    class SetSummable : public Set<N, T>{
    public:
        T accumulate (const std::string& filter) const{
            T sum(filter);
            for(size_t i = 0; i < this->size();i++){
                if(this->get(i).isCompatibleWith(sum))
                    sum += this->get(i);
            }
            return sum;
        }
    };
}
#endif //PAIRSUMMABLE_H_SETSUMMABLE_H
