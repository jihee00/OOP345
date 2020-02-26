//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__
#include <string>

namespace sdds {

	const size_t strSize{ 5 };

	class SpellChecker {
		std::string m_badWords[strSize]{};
		std::string m_goodWords[strSize]{};

	public:
		// a constructor that receives as a parameter the name of the file that contains the misspelled words.
		SpellChecker(const char* filename);

		// this operator should search in text if any of the misspelled words appear and replace them with the correct version.
		void operator()(std::string& text) const;
	};
}
#endif
