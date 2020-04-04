//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 04/03/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#ifndef WORKSTATION_H__
#define WORKSTATION_H__
#include <deque>
#include "CustomerOrder.h"


	class Workstation : public Station {

		// It is a double ended queue with new CustomerOrders coming in one side and exiting out the other once filled
		std::deque<CustomerOrder> m_orders;

		// a pointer to the next station on the assembly line
		Workstation* m_pNextStation;

	public: 

		// a custom constructor
		Workstation(const std::string&);

		// Workstation object cannot be copied or moved
		Workstation(Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

		// runs a single cycle of the assembly line for the current station
		void runProcess(std::ostream&);

		// if the order at the front of the queue doesn't require service at the current station, move it to the next station
		bool moveOrder();

		// stores the provided Station object's reference into the m_pNextStation pointer
		void setNextStation(Station& station);
		
		// return the next station on the assembly line
		const Workstation* getNextStation() const;

		// if the order at the front of the queue is completed, this function removes from the queue, places it in the parameter and returns true
		bool getIfCompleted(CustomerOrder& order);

		void display(std::ostream&);

		// moves the parameter onto the back of the CustomerOrder queue
		Workstation& operator+=(CustomerOrder&&);

	};

#endif
