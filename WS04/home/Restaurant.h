//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__
#include "Reservation.h"

using namespace std;
namespace sdds
{
	class Restaurant
	{
		Reservation* m_Reservation;
		size_t m_numReservation;

	public:
		// no-argument default constructor
		Restaurant(); 
		// argument constructor 
		Restaurant(Reservation* reservations[], size_t cnt);
		// copy constructor 
		Restaurant(Restaurant& rest);
		// move constructor
		Restaurant(Restaurant&& rest) noexcept;
		Restaurant& operator=(const Restaurant& rest);
		Restaurant& operator=(Restaurant&& rest) noexcept;
		// return how many reservations are in the system
		size_t size() const;
		// destructor
		~Restaurant();
		// overload the insertion operator to insert the content of a Restaurant object into an ostream object
		friend ostream& operator<<(ostream& os, const Restaurant& rest);
	};
}
#endif