//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#include "CustomerOrder.h"
#include "Utilities.h"
#include <iomanip>
#include <algorithm>

size_t CustomerOrder::m_widthField{ 0 };

CustomerOrder::CustomerOrder(const std::string& str) {

	Utilities utility;
	char delimiter = utility.getDelimiter();
	bool more{ true };

	size_t start = 0;
	size_t end = str.find(delimiter);
	m_name = str.substr(start, end);

	start = end + 1;
	end = str.find(delimiter, start);
	m_product = utility.extractToken(str, start, more);

	m_cntItem = std::count(str.begin(), str.end(), utility.getDelimiter()) - 1;

	if (m_cntItem > 0)
	{
		m_lstItem = new Item * [m_cntItem];

		for (auto i = 0u; i < m_cntItem - 1; i++)
		{
			start = end + 1;
			end = str.find(delimiter, start);
			m_lstItem[i] = new Item(utility.extractToken(str, start, more));
		}

		start = end + 1;
		m_lstItem[m_cntItem - 1] = new Item(str.substr(start));
	}

	if (m_widthField < utility.getFieldWidth()) m_widthField = utility.getFieldWidth();

}

// move constructor & assignment operator
CustomerOrder::CustomerOrder(CustomerOrder&& move) noexcept {

	*this = std::move(move);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& move) noexcept {

	if (this != &move) {

		if (m_lstItem) {
			for (auto i = 0u; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
		}

		m_name = move.m_name;
		m_product = move.m_product;
		m_cntItem = move.m_cntItem;
		m_lstItem = move.m_lstItem;
		move.m_name = "";
		move.m_product = "";
		move.m_cntItem = 0;
		move.m_lstItem = nullptr;
	}
	return *this;
	
}

// destructor
CustomerOrder::~CustomerOrder() {

	for (auto i = 0u; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
	m_lstItem = nullptr;

}

// check if all the items in the order have been filled
bool CustomerOrder::isOrderFilled() const {

	bool check = true;

	for (auto i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false)
			check = false;
	}
	return check;

}

// returns the ItemInfo::m_fillState of the item specified as a parameter. 
// If the item doesn't exist in the order, return true.
bool CustomerOrder::isItemFilled(const std::string& itemName) const {

	bool check = true;

	for (auto i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) check = m_lstItem[i]->m_isFilled;
	}
	return check;

}

// fills the item in the current order that corresponds to the station passed into the function.
void CustomerOrder::fillItem(Station& station, std::ostream& os) {

	for (auto i = 0u; i < m_cntItem; i++){

		if (station.getItemName() == m_lstItem[i]->m_itemName){

			if (station.getQuantity() > 0){

				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;

				os << "    Filled " << m_name << ", "
					<< m_product << " [" << station.getItemName() << "]" << std::endl;
			}
			else {
				os << "    Unable to fill " << m_name << ", "
					<< m_product << " [" << station.getItemName() << "]" << std::endl;
			}
		}
	}
}

// Elliott C. - Gaming PC
// [000000] CPU - MISSING
void CustomerOrder::display(std::ostream& os) const {

	os << m_name << " - " << m_product << std::endl;

	for (auto i = 0u; i < m_cntItem; i++) {
		
		os << "[" << std::setfill('0') << std::setw(6) << std::right << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] "
			<< std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - "
			<< (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
	}
}