//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#include <iomanip>
#include <fstream>
#include <numeric>
#include <iterator>
#include <algorithm>
#include "SongCollection.h"

namespace sdds
{
	SongCollection::SongCollection(const std::string& file)
	{
		std::fstream fout(file, std::ios::in | std::ios::binary);
		if (!fout){
			throw "File failed to open";
		} 
		else { 
			
			while (!fout.eof()) {

				Song temp{};
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
		unsigned long totalTime {};

		std::copy(v_songs.cbegin(), v_songs.cend(), std::ostream_iterator<const Song&>(out, "\n"));
		totalTime = std::accumulate(v_songs.cbegin(), v_songs.cend(), 0ul);

		out << "----------------------------------------------------------------------------------------" << std::endl;
		out << "|";
		out << "                                                        Total Listening Time:";
		out << std::setw(2)
			<< (totalTime / 3600) << ":" << std::setw(2)
			<< (totalTime / 60 % 60) << ":" << std::setw(2)
			<< (totalTime % 60) << std::right << " |" << std::endl;
	}

	void SongCollection::sort(const std::string& field)
	{	
			if (field == "title") {
				std::sort(v_songs.begin(), v_songs.end(),[=](const Song& a, const Song& b) {
						return a.m_title < b.m_title;
					});
			}

			else if (field == "album") {
				std::sort(v_songs.begin(), v_songs.end(), [=](const Song& a, const Song& b) {
					return a.m_album < b.m_album;
					});
			}
			else if (field == "length") {
				std::sort(v_songs.begin(), v_songs.end(), [=](const Song& a, const Song& b) {
					return a.m_length < b.m_length;
					});
			}
	}
	//  this function was required to be able to use the replace_if 
	std::string Song::operator=(const std::string& a)
	{
		return m_album = a;
	}

	void SongCollection::cleanAlbum()
	{
		std::replace_if(v_songs.begin(), v_songs.end(), [](const Song& s) {return s.m_album == "[None]";}, "");
	}

	bool SongCollection::inCollection(const std::string& name) const{
		return std::any_of(v_songs.cbegin(), v_songs.cend(), [&name](const Song& s) {return name == s.m_artist;});
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& name) const{
		std::list<Song> s_collection{};
		std::copy_if(v_songs.cbegin(), v_songs.cend(), back_inserter(s_collection),[&name](const Song& s) {return name == s.m_artist;});
		return s_collection;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << std::left << theSong.m_artist
			<< " | " << std::setw(20) << std::left << theSong.m_album
			<< " | " << std::setw(6) << std::right;
		if (theSong.m_year != 0) out << theSong.m_year;
		else out << "";
		out << " | " << (theSong.m_length / 60) << ":" << std::setw(2) << std::setfill('0') << (theSong.m_length % 60) << std::setfill(' ') << std::fixed
			<< " | " << std::setprecision(2) << std::fixed << theSong.m_price << " |";

		out.unsetf(std::ios::fixed);
		return out;
	}
    
	//  this function was required to be able to use the accumlute algorithm to sum
	unsigned long operator+(unsigned long num, const Song& song)
	{
		return num + song.m_length;
	}

	void trim(std::string& str)
	{
		size_t i = str.find_first_not_of(' ');
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}
}