//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/04/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds {

	// read a single record from the stream
	// extract information about a car and store it in the attributes.
	Car::Car(std::istream& is) {
		std::string temp;

		getline(is, temp, ',');
		getline(is, temp, ',');
		trim(temp);
		m_maker = temp;

		getline(is, temp, ',');
		trim(temp);
		if (temp.at(0) == 'n') m_condition = Condition::New;
		else if (temp.at(0) == 'u') m_condition = Condition::Used;
		else if (temp.at(0) == 'b') m_condition = Condition::Broken;
		else m_condition = Condition::Invalid;

		getline(is, temp);
		m_topSpeed = stod(temp);
	}
	    
	// query that returns new, used or broken
	std::string Car::condition() const {
		std::string temp;
		if (m_condition == Condition::New) temp = "new";
		else if (m_condition == Condition::Used) temp = "used";
		else if (m_condition == Condition::Broken) temp = "broken";
		else temp = "invalid";
		return temp;
	}

	double Car::topSpeed() const{
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const{
		out << "| " << std::setw(10) << m_maker
			<< " | " << std::setw(6) << std::left << condition()
			<< " | " << std::setw(6) << std::right << std::fixed << std::setprecision(2) << topSpeed()
			<< " |";
		out.unsetf(std::ios::fixed);
	}

	void trim(std::string& str)
	{
		size_t i = str.find_first_not_of(' ');
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}
}


