//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/17/2020
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
	static int COUNTER = 1;

	Event::Event() : m_desc(nullptr), m_time(0) {}

	Event::Event(const Event& copy){
		if(copy.m_desc != nullptr){ 
			m_desc = new char[strlen(copy.m_desc) + 1];
			strcpy(m_desc, copy.m_desc);
			m_time = copy.m_time;
		}
		else setEmpty();
	}

	Event::~Event() {delete[] m_desc;}

	Event& Event::operator=(const Event& copy) {
		if (this != &copy) {
			delete[] m_desc;
			m_time = copy.m_time;
			if (copy.m_desc != nullptr) {
				m_desc = new char[strlen(copy.m_desc) + 1];
				strcpy(m_desc, copy.m_desc);
			}
			else setEmpty();
		}
		return *this;
	}

	void Event::setEmpty() {
		m_desc = nullptr;
		m_time = 0;
	}
	
	// a modifier that receives as a parameter an array of characters.
	void Event::setDescription(const char desc[]) {
		if (desc != nullptr && desc[0] != '\0') {
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
		}
		else {
			m_desc = new char[strlen("[ No Event ]") + 1];
			strcpy(m_desc, "[ No Event ]");
		}
		m_time = g_sysClock;
	}

	// a query function that displays to the screen the content of an instance.
	void Event::display() const {
		cout << setfill(' ') << setw(3) << COUNTER++ << ". ";
		if (strcmp(m_desc, "[ No Event ]")) {
			cout << setfill('0') << setw(2) << m_time / 3600 << ":"
				<< setw(2) << m_time % 3600 / 60 << ":" << setw(2) << m_time % 60 << " -> ";
		}
		cout << m_desc << std::endl;
	}

}