//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#include "Utilities.h"


	char Utilities::m_delimiter{ ',' };
	
	// Sets the field width of the current object to the value of the parameter
	void Utilities::setFieldWidth(size_t newWidth) {

		m_widthField = newWidth;
	}

	// Returns the field width of the current object
	size_t Utilities::getFieldWidth() const {

		return m_widthField;
	}

	// Extracts tokens from the first parameter 
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

		// Uses the delimiter to extract the next token from str starting at next_pos
		size_t position = str.find(m_delimiter, next_pos);

		/*// Returns the extracted token found and sets more.
		std::string token = str.substr(next_pos, position - next_pos);*/

		if (position == next_pos)
		{
			more = false;
			throw "No token between them";

		}
		else
		{
			more = (position != std::string::npos) ? true : false;
			std::string token = str.substr(next_pos, position - next_pos);
			next_pos = position + 1;
			if (token.size() > m_widthField)
				m_widthField = token.length();

			return token;
		}

	}

	// Sets the delimiter for this class to the character received
	void Utilities::setDelimiter(const char newDelimiter) {

		m_delimiter = newDelimiter;
	}

	// Returns the delimiter character
	const char Utilities::getDelimiter() const {

		return m_delimiter;
	}
