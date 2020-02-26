//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_CONFIRMATION_H__
#define SDDS_CONFIRMATION_H__
#include <iostream>
#include "Reservation.h"

using namespace std;
namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_reserPtr;
		size_t m_numRes;

	public:
		// no-argument default constructor
		ConfirmationSender();
		// copy constructor 
		ConfirmationSender(const ConfirmationSender& conf);
		// move constructor
		ConfirmationSender(ConfirmationSender&& conf) noexcept;
		// add the parameter to the array
		ConfirmationSender& operator+=(const Reservation& res);
		// remove the parameter from the array
		ConfirmationSender& operator-=(const Reservation& res);
		// destructor
		~ConfirmationSender();
		// overload the insertion operator to insert the content of a ConfirmationSender object into an ostream object
		friend ostream& operator<<(ostream& os, const ConfirmationSender& conf);
	};
}
#endif