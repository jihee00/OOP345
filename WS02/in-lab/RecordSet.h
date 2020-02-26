//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__
#include <iostream>
#include <string>

using namespace std;
namespace sdds
{
	class RecordSet
	{
		string* m_file;
		size_t m_recordNum;
	public:
		// no-argument default constructor
		RecordSet();
		// 1-argument constructor 
		RecordSet(const char*);
		// copy constructor
		RecordSet(const RecordSet&);
		// copy assignment operator
		RecordSet& operator=(const RecordSet&);
		// destructor
		~RecordSet();
		// a query that returns the number of records stored in the current object
		size_t size() const;
		// a query that returns the record at the index received as parameter. 
		// If the index is invalid, this function should return the empty string.
		string getRecord(size_t) const;
	};
}
#endif