//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Movie.h"

using namespace std;
namespace sdds {

	Movie::Movie(const std::string& strMovie){
		char garbage{};
		stringstream save(strMovie);

		if (save) {
			getline(save, m_title, ',');
			eraseSpace(m_title);
			save >> m_year >> garbage;
			getline(save, m_desc, '\n');
			eraseSpace(m_desc);
		}
	}

	void Movie::eraseSpace(std::string& str){
		if (!str.empty()) {
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1);
		}
	}

	//a query that returns the title of the movie
	const string& Movie::title() const noexcept {
		return m_title;
	}

	ostream& operator<< (ostream& os, const Movie& movie){
		os << setw(40) << movie.m_title << " | "
			<< setw(4) << movie.m_year << " | "
			<< movie.m_desc << endl;
		return os;
	}
}
