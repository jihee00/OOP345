//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 04/03/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#include "LineManager.h"
#include "Utilities.h"
#include <fstream>

size_t LineManager::COUNT{1};

LineManager::LineManager(const std::string& str, std::vector<Workstation*>& station, std::vector<CustomerOrder>& order) {

	std::ifstream file(str);
	std::string record;
	std::string item;
	std::string nextItem;
	Utilities utility;
	size_t next_pos{ 0 };

	while (file) {

		bool more{ true };

		while (std::getline(file, record)) {
		
			item = utility.extractToken(record, next_pos, more);

			for (auto i : station) {

				if (item == i->getItemName()) {
					if (more) {

						nextItem = utility.extractToken(record, next_pos, more);
						for (auto j : station) {
							if (nextItem == j->getItemName())
								i->setNextStation(*j);
						}
					}
					AssemblySorted.push_back(i);
				}
			}
		}
	}

	AssemblyLine = station;
	m_cntCustomerOrder = order.size();
	ToBeFilled = std::deque<CustomerOrder>(m_cntCustomerOrder);

	for (auto i = 0u; i < m_cntCustomerOrder; i++) {

		ToBeFilled[i] = std::move(order[i]);
	}
}

// this function performs one cycle of operations on the assembly line
bool LineManager::run(std::ostream& os) {

	CustomerOrder order;

	os << "Line Manager Iteration: " << COUNT << std::endl;

	if (ToBeFilled.size() > 0) {

		*AssemblySorted.at(0) += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (auto& i : AssemblyLine) i->runProcess(os);

	for (auto& i : AssemblyLine) {

		i->moveOrder();

		if (i->getIfCompleted(order)) {

			Completed.push_back(std::move(order));

		}
	} 

	COUNT++;
	return Completed.size() == m_cntCustomerOrder;
}

// displays all the orders that were completed
void LineManager::displayCompletedOrders(std::ostream& os) const {

	for (auto i = Completed.begin(); i != Completed.end(); i++) (*i).display(std::cout);
}

// display all stations on the assembly line in the order they were received from the client
void LineManager::displayStations() const {

	for (auto i : AssemblyLine) i->display(std::cout);
}

// display all stations on the assembly line in the order they are linked
void LineManager::displayStationsSorted() const {

	for (auto i : AssemblySorted) i->display(std::cout);
}