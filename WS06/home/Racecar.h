//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/08/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_RACECAR_H__
#define SDDS_RACECAR_H__
#include "Car.h"

namespace sdds {
	class Racecar : public Car {

		// the percentage (stored as a number between 0 an 1) by which this Racecar can boost its top speed.
		double m_booster{};

	public:

		// extracts the last field from the stream containing the booster bonus.
		Racecar(std::istream& in);

		// adds * at the end.
		void display(std::ostream& out) const;

		//  returns the top speed of the car, including any booster effects.
		double topSpeed()const;

		~Racecar() {}
	};
}
#endif