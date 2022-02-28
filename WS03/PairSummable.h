// Workshop 3 - Templates
// Victor Lozano - 2021/09/30
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS03_P2_PAIRSUMMABLE_H
#define WS03_P2_PAIRSUMMABLE_H
#include <string>
#include "Pair.h"

namespace sdds{
    template<typename V, typename K>
    class PairSummable : public Pair<V,K>{
        static V initial;
        static size_t fieldWidth;
    public:
        PairSummable()
        {
        }
        PairSummable(const K& key, const V& value = initial) : Pair<V,K>(key, value){
            if(fieldWidth < key.size()){
                fieldWidth = key.size();
            }
        }
        bool isCompatibleWith(const PairSummable<V,K>& b) const{
            return this->key() == b.key();
        }
        PairSummable<V,K>& operator+=(const PairSummable<V,K>& b){
            *this = PairSummable(this->key(), this->value() + b.value());
            return *this;
        }
        void display (std::ostream& os) const{
            os << std::left << std::setw(fieldWidth);
            Pair<V,K>::display(os);
            os << std::right;
        }
    };
    //Initialize class variables
    template<typename V, typename K>
    size_t PairSummable<V,K>::fieldWidth = 0;

    template<typename V, typename K>
    V PairSummable<V,K>::initial;

    template<>
    PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(
            const PairSummable<std::string, std::string>& b){
        if(value() == ""){
            *this = PairSummable(this->key(), b.value());
        }else{
            *this = PairSummable(this->key(), this->value() + ", " + b.value());
        }
        return *this;
    }
}
#endif //WS03_P2_PAIRSUMMABLE_H
