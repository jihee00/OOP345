//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/05/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds
{
	class Reservation {
		// an array of characters
		char m_reservationId[8];
		string m_reservationName;
		// that can be used to send the confirmation that the reservation can be honored or not
		string m_email;
		// PARTY_SIZE
		int m_numPeople;
		// an integer between 1 and 31
		int m_day;
		// an integer between 1 and 24
		int m_hour;

	public:
		// a default constructor
		Reservation();
		// receives the reservation as a string 
		// this constructor is responsible to extract the information about the reservation from the parameter and store it in the attributes of the instance.
		Reservation(const string& res);
		// overload the insertion operator to insert the content of a reservation object into an ostream object
		friend ostream& operator<<(ostream& os, const Reservation& res);
    };
}
#endif