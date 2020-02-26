//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <fstream>
#include "RecordSet.h"

namespace sdds
{
	// no-argument default constructor
	RecordSet::RecordSet() :m_file(nullptr), m_recordNum(0){}

	// 1-argument constructor, reads the file to count the number of records present
	// allocates memory for that number records in the array
	// re-reads the file and loads the records into the array.
	RecordSet::RecordSet(const char* name) {
		string buffer;
		m_recordNum = 0;
		ifstream f(name);
		if (!f.is_open()) {
			std::cout << "The file will not open" << name << '\n';
		}
		else {
			// count lines in file
			while (getline(f, buffer, ' ')) {
				m_recordNum++;
			}
			// allocate memory
			m_file = new string[m_recordNum];
			f.clear();
			// rewind input
			f.seekg(0);
			unsigned int i = 0;
			while (getline(f, buffer, ' ')) {
				m_file[i] = buffer;
				i++;
			}
		}
	}

	// copy constructor
	RecordSet::RecordSet(const RecordSet& copy){
		if (copy.m_file != nullptr) {
			m_recordNum = copy.m_recordNum;
			m_file = new string[m_recordNum];
			for (size_t i = 0; i < m_recordNum; i++) {
				m_file[i] = copy.m_file[i];
			}
		}
		else {
			m_file = nullptr;
			m_recordNum = 0;
		}
	}

	// copy assignment operator
	RecordSet& RecordSet::operator=(const RecordSet& copy){
		if (this != &copy) {
			m_recordNum = copy.m_recordNum;
			delete[] m_file;
			if (copy.m_file != nullptr) {
				m_file = new string[m_recordNum];
				for (size_t i = 0; i < m_recordNum; i++) {
					m_file[i] = copy.m_file[i];
				}
			}
			else {
				m_file = nullptr;
				m_recordNum = 0;
			}
		}
		return *this;
	}

	// destructor
	RecordSet::~RecordSet() {
		delete[] m_file;
	}

	// move constructor
	RecordSet::RecordSet(RecordSet&& move) :m_file(move.m_file), m_recordNum(move.m_recordNum){
		move.m_file = nullptr;
		move.m_recordNum = 0;
	}

	// move assignment operator
	RecordSet& RecordSet::operator=(RecordSet&& move) {
		if (this != &move) {
			    delete[] m_file;
				m_file = move.m_file;
				m_recordNum = move.m_recordNum;
				move.m_file = nullptr;
				move.m_recordNum = 0;
		}
		return *this;
	}

	// a query that returns the number of records stored in the current object
	size_t RecordSet::size() const{
		return m_recordNum;
	}

	// a query that returns the record at the index received as parameter. 
	// If the index is invalid, this function should return the empty string.
	string RecordSet::getRecord(size_t index) const{
		string record;
		if (m_file != nullptr) {
			record = m_file[index];
		}
		else {
			record = "";
		}
	  return record;
	}
}