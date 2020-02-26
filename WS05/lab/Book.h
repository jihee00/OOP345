//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

using namespace std;
namespace sdds {

	class Book {
		string m_author{};
		string m_title{};
		string m_country{};
		size_t m_year{};
		double m_price{};
		string m_desc{};

	public:
		Book() {}
		Book(const string& str);
		void eraseSpace(string& str);
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		friend ostream& operator<<(ostream& os, const Book&);
	};

}

#endif