//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__

#include <iostream>
#include <string>
namespace sdds {

	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};

	public:
		Movie() {}
		Movie(const std::string& strMovie);
		void eraseSpace(std::string& str);

		//a query that returns the title of the movie
		const std::string& title() const noexcept;

		// this function should call the overloaded operator() on instance spellChecker, passing to it the movie title and description.
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		friend std::ostream& operator<< (std::ostream& os, const Movie& movie);
	};

}

#endif