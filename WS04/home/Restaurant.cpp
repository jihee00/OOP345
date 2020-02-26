//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "Restaurant.h"

using namespace std;
namespace sdds {
	// no-argument default constructor
	Restaurant::Restaurant() : m_Reservation{ nullptr }, m_numReservation{ 0 } {
	}

	// argument constructor 
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		m_numReservation = cnt;
		m_Reservation = new Reservation[cnt];
		for (size_t i = 0; i < cnt; ++i)
		{
			if (reservations[i] != nullptr)
			{
				m_Reservation[i] = *reservations[i];
			}
		}
	}

	// copy constructor 
	Restaurant::Restaurant(Restaurant& rest) : m_Reservation{ nullptr }, m_numReservation{ 0 } {
		*this = rest;
	}

	// move constructor
	Restaurant::Restaurant(Restaurant&& rest) noexcept : m_Reservation{ nullptr }, m_numReservation{ 0 }{
		*this = move(rest);
	}

	Restaurant& Restaurant::operator=(const Restaurant& rest){
		if (this != &rest)
		{
			delete[] m_Reservation;
			if (rest.m_Reservation != nullptr)
			{
				m_numReservation = rest.m_numReservation;
				m_Reservation = new Reservation[m_numReservation];
				for (size_t i = 0; i < m_numReservation; ++i)
				{
					m_Reservation[i] = rest.m_Reservation[i];
				}
			}
			else
				m_Reservation = nullptr;
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& rest) noexcept {
		if (this != &rest){
			delete[] m_Reservation;
			m_Reservation = rest.m_Reservation;
			m_numReservation = rest.m_numReservation;
			rest.m_Reservation = nullptr;
			rest.m_numReservation = 0;
		}
		return *this;
	}

	// return how many reservations are in the system
	size_t Restaurant::size() const {
		return m_numReservation;
	}
	// destructor
	Restaurant::~Restaurant() {
		delete[] m_Reservation;
		m_Reservation = nullptr;
	}

	// overload the insertion operator to insert the content of a Restaurant object into an ostream object
	ostream& operator<<(ostream& os, const Restaurant& rest) {
		os << "--------------------------\n"
			<< "Fancy Restaurant\n"
			<< "--------------------------\n";
		if (rest.m_numReservation == 0) {
			os << "The object is empty!\n";
		}
		else {
			for (size_t i = 0; i < rest.m_numReservation; i++) {
				os << rest.m_Reservation[i];
			}
		} 
		os << "--------------------------\n";
		return os; 
	}
}