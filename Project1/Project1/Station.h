//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#ifndef STATION_H__
#define STATION_H__
#include <iostream>
#include <string>

	class Station {

		size_t m_staionId{};
		std::string m_itemName{};
		std::string m_stationDesc{};
		size_t m_serialNumber{};
		size_t m_quantity{};

		static size_t m_widthField;
		static int idGenerator;

	public:

		// custom constructor
		Station(const std::string& str);

		//  returns the name of the current Station object
		const std::string& getItemName() const;

		//  returns the next serial number to be used on the assembly line and increments m_serialNumber
		const unsigned int getNextSerialNumber();

		// returns the remaining quantity of the current Station object
		const unsigned int getQuantity() const;

		// subtracts 1 from the available quantity; should not go below 0
		void updateQuantity();

		// inserts the content of the current object into first parameter
		void display(std::ostream& os, bool full) const;
		
	};

#endif