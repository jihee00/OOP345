//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 04/03/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#include "Workstation.h"

Workstation::Workstation(const std::string& str) : Station(str) {

	m_pNextStation = nullptr;
}

// runs a single cycle of the assembly line for the current station
void Workstation::runProcess(std::ostream& os) {

	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}

// if the order at the front of the queue doesn't require service at the current station, move it to the next station
bool Workstation::moveOrder() {

	bool check = true;

	if (m_orders.empty()) {
		check = false;
	}
	else {
		if (m_pNextStation && m_orders.front().isItemFilled(getItemName())) {

			*m_pNextStation += std::move(m_orders.front());
			m_orders.pop_front();
		}
	}
	return check;
}

// stores the provided Station object's reference into the m_pNextStation pointer
void Workstation::setNextStation(Station& station) {

	m_pNextStation = (Workstation*)&station;
}

// return the next station on the assembly line
const Workstation* Workstation::getNextStation() const {

	return m_pNextStation;
}

// if the order at the front of the queue is completed, this function removes from the queue, places it in the parameter and returns true
bool Workstation::getIfCompleted(CustomerOrder& order) {

	bool check = false;

	if (!m_orders.empty() && m_orders.front().isOrderFilled()) {

		check = true;
		order = std::move(m_orders.front());
		m_orders.pop_front();
	}
	return check;
}

void Workstation::display(std::ostream& os) {

	if (getNextStation()) {

		os << getItemName() << " --> " << getNextStation()->getItemName() << std::endl;
	}
	else {

		os << getItemName() << " --> " << "END OF LINE" << std::endl;
	}
}

// moves the parameter onto the back of the CustomerOrder queue
Workstation& Workstation::operator+=(CustomerOrder&& order) {

	m_orders.push_back(std::move(order));
	return *this;
}