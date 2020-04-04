//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//----------------------------------------------
#ifndef UTILITIES_H__
#define UTILITIES_H__
#include <string>

	class Utilities {

		// Specifying the length of the token extracted
		size_t m_widthField{ 1 };

		// All Utilities objects share the same delimiter
		static char m_delimiter;

	public: 
		// Sets the field width of the current object to the value of the parameter
		void setFieldWidth(size_t newWidth);

		// Returns the field width of the current object
		size_t getFieldWidth() const;

		// Extracts tokens from the first parameter 
		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		// Sets the delimiter for this class to the character received
		static void setDelimiter(const char newDelimiter);

		// Returns the delimiter character
		const char getDelimiter() const;
	};

#endif
