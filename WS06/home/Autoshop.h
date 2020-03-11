//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/08/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_AUTOSHOP_H__
#define SDDS_AUTOSHOP_H__
#include <list>
#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {

		std::vector<Vehicle*> m_vehicles;

	public:

		// adds the vehicle received as parameter into the m_vehicles vector
		Autoshop& operator +=(Vehicle* theVehicle);

		// iterates over the vehicles stored in m_vehicles and prints them into the parameter
		void display(std::ostream& out) const;

		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			for (auto& v : m_vehicles)
				if (test(v)) vehicles.push_back(v);

		}    
	};
}

#endif
