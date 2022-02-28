// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Victor Lozano - 2021/11/21
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
        bool found {false};
        for(size_t i {0ul}; i < desc.size(); i++) {
            for(size_t j {0ul}; j < price.size() && !found; j++) {
                if(desc[i].code == price[j].code) {
                    found = true;
                    Product *aux {new Product(desc[i].desc, price[j].price)};
                    try {
                        aux->validate();
                    } catch(const std::string& msg) {
                        Product::Trace = false;
                        delete aux;
                        Product::Trace = true;
                        throw;
                    }
                    priceList += aux;
                    delete aux;
                }
            }
            found = false;
        }
        return priceList;
	}
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for(size_t i = 0; i < desc.size(); i++) {
            for(size_t j = 0ul; j < price.size() ; j++) {
                if(desc[i].code == price[j].code) {
                    std::unique_ptr<Product> aux (new Product(desc[i].desc, price[j].price));
                    aux->validate();
                    priceList += aux;
                }
            }
        }
        return priceList;
    }
}