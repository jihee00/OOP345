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
#include <string>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {
	// no-argument default constructor
	ConfirmationSender::ConfirmationSender() : m_reserPtr{}, m_numRes{} {
	}

	// copy constructor 
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& conf) {
		m_reserPtr = new const Reservation * [conf.m_numRes];
		for (size_t i = 0; i < conf.m_numRes; i++) {
			m_reserPtr[i] = conf.m_reserPtr[i];
		}
		m_numRes = conf.m_numRes;
	}

	// move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& conf) noexcept {
		m_reserPtr = conf.m_reserPtr;
		m_numRes = conf.m_numRes;
		conf.m_reserPtr = nullptr;
		conf.m_numRes = 0;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		if (m_numRes != 0)
		{
			for (size_t i = 0; i < m_numRes; ++i)
			{
				if (m_reserPtr[i] == &res)
					return *this;
			}
			const Reservation** temp = new const Reservation * [m_numRes + 1];
			for (size_t i = 0; i < m_numRes; ++i)
			{
				temp[i] = m_reserPtr[i];
			}
			temp[m_numRes] = &res;
			m_numRes++;
			delete[] m_reserPtr;
			m_reserPtr = new const Reservation * [m_numRes];
			for (size_t i = 0; i < m_numRes; ++i)
			{
				m_reserPtr[i] = temp[i];
			}
			delete[] temp;
		}
		else 
		{
			m_reserPtr = new const Reservation * [m_numRes + 1];
			m_reserPtr[m_numRes] = &res;
			m_numRes++;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		const Reservation** temp = new const Reservation * [m_numRes];
		size_t count = m_numRes;
		for (size_t i = 0; i < m_numRes; ++i)
		{
			if (m_reserPtr[i] == &res)
			{
				m_reserPtr[i] = nullptr;
				m_numRes--;
			}
		}
		size_t valid = 0;
		for (size_t i = 0; i < count; ++i)
		{
			if (m_reserPtr[i] != nullptr)
			{
				temp[valid] = m_reserPtr[i];
				valid++;
			}
		}

		delete[] m_reserPtr;
		m_reserPtr = new const Reservation * [valid];
		for (size_t i = 0; i < valid; ++i)
		{
			m_reserPtr[i] = temp[i];
		}
		delete[] temp;
		return *this;
	}

	// destructor
	ConfirmationSender::~ConfirmationSender() {
		delete[] m_reserPtr;
		m_reserPtr = nullptr;
	}

	// overload the insertion operator to insert the content of a ConfirmationSender object into an ostream object
	ostream& operator<<(ostream& os, const ConfirmationSender& conf) {
		os << "--------------------------\n"
		    <<"Confirmations to Send\n"
		    << "--------------------------\n";
		if (conf.m_numRes == 0) {
			os << "The object is empty!\n";
		}
		else {
			for (size_t i = 0; i < conf.m_numRes; i++) {
				os << *conf.m_reserPtr[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}