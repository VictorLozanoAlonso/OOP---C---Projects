#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Victor Lozano - 2021/11/21
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.

#include "List.h"
#include "Element.h"

namespace sdds {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif