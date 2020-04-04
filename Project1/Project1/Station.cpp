//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t Station::m_widthField{ 1 };
int Station::idGenerator{ 0 };

// custom constructor
Station::Station(const std::string& str){

	Utilities utility{};
	char delimiter = utility.getDelimiter();
	bool more{ false };

	m_staionId = ++idGenerator;

	size_t start = 0;
	size_t end = str.find(delimiter);
	m_itemName = str.substr(start, end);

	start = end + 1;
	end = str.find(delimiter, start);
	m_serialNumber = std::stoi(utility.extractToken(str, start, more));


	start = end + 1;
	end = str.find(delimiter, start);
	m_quantity = std::stoi(utility.extractToken(str, start, more));

	start = end + 1;
	m_stationDesc = utility.extractToken(str, start, more);

	if (m_widthField < m_itemName.length())m_widthField = m_itemName.length();
}

//  returns the name of the current Station object
const std::string& Station::getItemName() const {

	return m_itemName;
}

//  returns the next serial number to be used on the assembly line and increments m_serialNumber
const unsigned int Station::getNextSerialNumber(){

	return m_serialNumber++;
}

// returns the remaining quantity of the current Station object
const unsigned int Station::getQuantity() const{
	
	return m_quantity;
}

// subtracts 1 from the available quantity; should not go below 0
void Station::updateQuantity(){

	if (m_quantity > 0) m_quantity--;
}

// inserts the content of the current object into first parameter
void Station::display(std::ostream& os, bool full) const{

	// [001] Item: CPU          [123456]
	if (full == false) {

		os << std::right << "[" << std::setw(3) << std::setfill('0') << m_staionId << "] Item: "
			<< std::setfill(' ') << std::setw(m_widthField) << std::left << m_itemName
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::endl;
	}
	// [001] Item: CPU          [123456] Quantity: 5            Description: Central Processing Unit
	else {

		os << std::right << "[" << std::setw(3) << std::setfill('0') << m_staionId << "] Item: "
			<< std::setfill(' ') << std::setw(m_widthField) << std::left << m_itemName
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "] Quantity: " 
			<< std::setfill(' ') << std::setw(m_widthField) << std::left << m_quantity
			<< " Description: " << m_stationDesc << std::endl;
	}
}