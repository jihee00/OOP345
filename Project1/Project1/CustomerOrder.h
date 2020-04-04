//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#ifndef CUSTOMERORDER_H__
#define CUSTOMERORDER_H__
#include "Station.h"

	struct Item
	{
		std::string m_itemName;
		unsigned int m_serialNumber = 0;
		bool m_isFilled = false;

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {

		// the name of the customer
		std::string m_name{};

		// the name of the product being assembled (e.g., Desktop, Laptop, etc)
		std::string m_product{};

		// a count of the number of items for the customer's order
		unsigned int m_cntItem{};

		// Each element of the array is a dynamically allocated object of type Item. 
		// This is the resource that your class must manage.
		Item** m_lstItem{};

		// the maximum width of a field, used for display purposes
		static size_t m_widthField;

	public:

		// default constructor
		CustomerOrder() {}

		CustomerOrder(const std::string& str);

		// not allow copy operations
		CustomerOrder(const CustomerOrder& copy) { throw "Cannot make copies."; }
		CustomerOrder& operator=(const CustomerOrder& copy) = delete;

		// move constructor & assignment operator
		CustomerOrder(CustomerOrder&& move) noexcept;
		CustomerOrder& operator=(CustomerOrder&& move) noexcept;

		// destructor
		~CustomerOrder();

		// check if all the items in the order have been filled
		bool isOrderFilled() const;
		
		// returns the ItemInfo::m_fillState of the item specified as a parameter. 
		// If the item doesn't exist in the order, return true.
		bool isItemFilled(const std::string& itemName) const;

		// fills the item in the current order that corresponds to the station passed into the function.
		void fillItem(Station& station, std::ostream& os);

		void display(std::ostream& os) const;

	};

#endif 
