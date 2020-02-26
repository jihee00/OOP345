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

#include <iostream>
#include <string>
namespace sdds {

	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_desc{};

	public:
		// a default constructor
		Book() {}
		Book(const std::string& str);
		void eraseSpace(std::string& str);

		// a query that returns the title of the book
		const std::string& title() const noexcept;
		// a query that returns the publication country
		const std::string& country() const noexcept;
		// a query that returns the publication year
		const size_t& year() const noexcept;
		// allowing you to update the price
		double& price() noexcept;

		// this function should call the overloaded operator() on instance spellChecker, passing to it the book description.
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};

}

#endif