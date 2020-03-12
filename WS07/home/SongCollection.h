//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__
#include <iostream>
#include <string>
#include <vector>
#include <list>

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

		// = operator copies the contents of the reference to a string object to the album member
		std::string operator=(const std::string&);
	};

	class SongCollection
	{
		std::vector<Song> v_songs;

	public: 
		SongCollection(const std::string& file);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& name) const;
		std::list<Song> getSongsForArtist(const std::string& name) const;
	};

	// helper function
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	unsigned long operator+(unsigned long num, const Song& song);
	void trim(std::string& str);
}	
#endif