//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/04/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <algorithm>
#include "Autoshop.h"

namespace sdds {

	// adds the vehicle received as parameter into the m_vehicles vector
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	// iterates over the vehicles stored in m_vehicles and prints them into the parameter
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl
			<< "| Cars in the autoshop!        |" << std::endl
			<< "--------------------------------" << std::endl;
		for (auto& v : m_vehicles) {
			v->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() {
		for (auto& v : m_vehicles) {
			delete v;
			v = nullptr;
		}
	}

}
