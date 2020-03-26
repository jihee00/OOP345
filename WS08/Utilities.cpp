//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/19/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	// This function compares the elements in the two received lists for common product codes and builds the user-friendly list from the matching pairs. 
	// For each successful comparison, your function allocates dynamic memory of Product type using that description and the price. 
	// Your function then validates the Product object and adds it to its list. Your function returns a copy of this list.
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++) {

			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {

					Product* tempProduct = new Product(desc[i].desc, price[j].price);
					tempProduct->validate();
					priceList += tempProduct;
					delete tempProduct;

				}
			}		
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {

			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {

					std::unique_ptr<Product> p { new Product(desc[i].desc, price[j].price) };
					p->validate();
					priceList += p;
				}
			}
		}
		return priceList;
	}
}