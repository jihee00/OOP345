//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "SongCollection.h"

namespace sdds
{
	SongCollection::SongCollection(const std::string& file)
	{
		// a temporary string to hold the numeric data to be converted to a number
		//std::string tempstr{};
		std::fstream fout(file, std::ios::in | std::ios::binary);
		if (!fout){
			throw "File failed to open";
		} 
		else { 
			
			while (!fout.eof()) {

				Song temp{};
				// allocate memory to strings...
				temp.m_artist.resize(25);
				temp.m_title.resize(25);
				temp.m_album.resize(25);

				fout.read(&temp.m_title[0], 25);
				trim(temp.m_title);

				fout.read(&temp.m_artist[0], 25);
				trim(temp.m_artist);

				fout.read(&temp.m_album[0], 25);
				trim(temp.m_album);

				std::string tempstr{};
				tempstr.resize(5);
				fout.read(&tempstr[0], 5);

				if (tempstr.find_first_not_of(' ') != std::string::npos)
					temp.m_year = stoi(tempstr);

				fout.read(&tempstr[0], 5);
				if (tempstr.find_first_not_of(' ') != std::string::npos)
					temp.m_length = stoi(tempstr);

				fout.read(&tempstr[0], 5);
				if (tempstr.find_first_not_of(' ') != std::string::npos)
					temp.m_price = stod(tempstr);

				// ignore any characters left on the line
				fout.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				v_songs.push_back(std::move(temp));
				}
		}
	}

	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(v_songs.begin(), v_songs.end(), [&](const Song songs) {out << songs; });
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << std::left << theSong.m_artist
			<< " | " << std::setw(20) << std::left << theSong.m_album
			<< " | " << std::setw(6) << std::right;
		if (theSong.m_year != 0) out << theSong.m_year;
		else out << "";
		out << " | " << (theSong.m_length / 60) << ":" << (theSong.m_length % 60)
			<< " | " << std::setprecision(2) << std::fixed << theSong.m_price << " |" << std::endl;

		out.unsetf(std::ios::fixed);
		return out;
	}

	void trim(std::string& str)
	{
		size_t i = str.find_first_not_of(' ');
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}
}