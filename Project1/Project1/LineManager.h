//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 04/03/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#ifndef LINEMANAGER_H__
#define LINEMANAGER_H__
#include "Workstation.h"
#include <vector>

	// A LineManager object manages the entire assembly line
	class LineManager {

		//  A container containing all the references of the Workstation objects on the assembly line
		std::vector<Workstation*> AssemblyLine;
		std::vector<Workstation*> AssemblySorted;

		// A queue of customer orders to be filled
		std::deque<CustomerOrder> ToBeFilled;

		// A queue of customer orders completed
		std::deque<CustomerOrder> Completed;

		// The number of CustomerOrder objects the assembly line started with
		size_t m_cntCustomerOrder;
		static size_t COUNT;

	public:

		LineManager() :m_cntCustomerOrder{ 0 } {}

		LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);

		// this function performs one cycle of operations on the assembly line
		bool run(std::ostream& os);

		// displays all the orders that were completed
		void displayCompletedOrders(std::ostream& os) const;

		// display all stations on the assembly line in the order they were received from the client
		void displayStations() const;

		// display all stations on the assembly line in the order they are linked
		void displayStationsSorted() const;
	};

#endif 

