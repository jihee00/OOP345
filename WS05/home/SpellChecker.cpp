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
#include <fstream>
#include <sstream>
#include "SpellChecker.h"

using namespace std;
namespace sdds {

	// a constructor that receives as a parameter the name of the file that contains the misspelled words.
	SpellChecker::SpellChecker(const char* filename) {
		std::fstream f(filename, std::ios::in);
		if (!f) {
			throw "Bad file name!";
		}

		for (size_t i = 0; !f.eof() && i < strSize; i++) {
			f >> m_badWords[i];
			if (!f.eof()) {
				f >> m_goodWords[i];
			}
		}
	}

	// this operator should search in text if any of the misspelled words appear and replace them with the correct version.
	void SpellChecker::operator()(std::string& text) const {
		for (size_t i = 0; i < strSize; i++) {
			size_t indexing = 0;
			
			while ((indexing = text.find(m_badWords[i], indexing)) != std::string::npos) {
				text.replace(indexing, m_badWords[i].size(), m_goodWords[i]);
				indexing += m_goodWords[i].size();
			}
		}
	}
}