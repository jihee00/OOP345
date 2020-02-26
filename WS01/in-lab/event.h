//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/15/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__
#include <iostream>

// a global variable, represents the time of day as the number of seconds since midnight (an integer between 0 and 86400)
extern unsigned int g_sysClock;

namespace sdds
{
	// create a class called Event. 
	class Event
	{
	private:
		char m_edesc[128];
		//the time when the event starts, expressed in number of seconds that passed from midnight.
		unsigned int m_etime;
	public:
		// default constructor
		Event();
		// a query function that displays to the screen the content of an instance.
		void display() const;
		// a modifier that receives as a parameter an array of characters.
		int setDescription(char desc[]); 
	};

}
#endif 
