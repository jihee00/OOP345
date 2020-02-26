//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Book.h"

using namespace std;
namespace sdds {

	Book::Book(const string& str) {
		char garbage{};
		stringstream save(str);

		if (save) {
			getline(save, m_author, ',');
			eraseSpace(m_author);
			getline(save, m_title, ',');
			eraseSpace(m_title);
			getline(save, m_country, ',');
			eraseSpace(m_country);
			save >> m_price >> garbage
				>> m_year >> garbage;
			getline(save, m_desc, '\n');
			eraseSpace(m_desc);
		}

	}

	void Book::eraseSpace(string& str) {
		if (!str.empty()) {
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1);
		}
	}

	const string& Book::title() const {
		return m_title;
	}

	const string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}

	ostream& operator<<(ostream& os, const Book& book) {

		os << setw(20) << right << book.m_author << " | "
			<< setw(22) << right << book.m_title << " | "
			<< setw(5) << right << book.m_country << " | "
			<< setw(4) << book.m_year << " | "
			<< setw(6) << fixed << setprecision(2) << book.m_price << " | "
			<< book.m_desc << endl;

		return os;
	}

}