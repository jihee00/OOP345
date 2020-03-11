//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/04/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <sstream>
#include "Car.h"
#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		std::string tempCar;
		Vehicle* temp = nullptr;

		getline(in, tempCar);

		if (!tempCar.empty()) {
			trim(tempCar);

			if (tempCar.at(0) == 'c' || tempCar.at(0) == 'C') {
				std::stringstream save(tempCar);
				temp = new Car(save);
			}
		}
		return temp;
	}
}