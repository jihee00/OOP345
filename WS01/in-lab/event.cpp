//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/15/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
unsigned int g_sysClock = 0;

namespace sdds
{
	int COUNTER = 1;

	Event::Event() :m_Edesc(""), m_Etime(g_sysClock) {}
	
	// a modifier that receives as a parameter an array of characters.
	int Event::setDescription(char desc[]) {
		if (desc != nullptr && desc[0] != '\0') {
			strncpy(m_Edesc, desc, 127);
		}
		else strcpy(m_Edesc, "[ No Event ]");
		m_Etime = g_sysClock;
		return 1;
	}

	// a query function that displays to the screen the content of an instance.
	void Event::display() const {
		cout << setw(3) << setfill(' ') << COUNTER++ << ". ";
		if (strcmp(m_Edesc, "[ No Event ]")) {
			cout << setfill('0') << setw(2) << m_Etime / 3600 << ":"
				<< setw(2) << m_Etime % 3600 / 60 << ":" << setw(2) << m_Etime % 60 << " -> ";
		}
		cout << m_Edesc << std::endl;
	}

}