//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/08/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include "Racecar.h"

namespace sdds {

	// extracts the last field from the stream containing the booster bonus.
	Racecar::Racecar(std::istream& in) : Car(in) {

		std::string temp;
		getline(in, temp);
		if (!temp.empty()) {
			m_booster = stod(temp);
		}
		else m_booster = 0.0;
	}

	// adds * at the end.
	void Racecar::display(std::ostream& out) const {

		Car::display(out);
		out << '*';

	}

	//  returns the top speed of the car, including any booster effects
	double Racecar::topSpeed()const {

		return Car::topSpeed()*(1 + m_booster);

	}

}