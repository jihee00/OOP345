//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__
#include <iostream>
#include <string>
#include <vector>

namespace sdds
{
	struct Song
	{
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		size_t m_year{};
		size_t m_length{};
	};

	class SongCollection
	{
		std::vector<Song> v_songs;

	public: 
		SongCollection(const std::string& file);
		void display(std::ostream& out) const;

	};

	// helper function
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	void trim(std::string& str);
}	
#endif