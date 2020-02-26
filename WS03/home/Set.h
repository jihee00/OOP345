//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_SET_H__
#define SDDS_SET_H__
#include <iostream>

using namespace std;
namespace sdds
{
	template <class T, size_t N>
	class Set {
		T m_array[N];
		size_t m_numEle = 0;

	public:
		// returns the number of elements in the set
		size_t size() const {
			return m_numEle;
		}

		// returns the element at index i (assume the parameter is valid).
		const T& operator[](size_t idx) const {
			return m_array[idx];
		}

		// if the set didn't reach the capacity, add a copy of the parameter to the array. Otherwise, do nothing.
		void operator+=(const T& item) {
			if (m_numEle < N) {
				m_array[m_numEle] = item;
				m_numEle++;
			}
		}

	};
}
#endif