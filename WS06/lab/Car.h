//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/04/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {

	enum class Condition : char { New, Used, Broken, Invalid };

	class Car : public Vehicle {

		    std::string m_maker{};
			Condition m_condition{};
			double m_topSpeed{};

	public:

		// custom constructor that receives an object
		// read a single record from the stream
		// extract information about a car and store it in the attributes.
		Car(std::istream& is);
		// query that returns new, used or broken
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		~Car() {}
	};

	// helper function
	void trim(std::string& str);
}
#endif