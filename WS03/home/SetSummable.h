//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
#include <iostream>
#include "Set.h"
#include "PairSummable.h"

using namespace std;
namespace sdds
{
	template <typename T, size_t N, typename K, typename V>
	class SetSummable : public Set<T, N>
	{
	public:
		V accumulate(const K& key) const {
			PairSummable<K, V> temp;
			V accum = temp.getInitialValue();
			for (size_t i = 0; i < this->size(); i++) {
				accum = (this->operator[](i)).sum(key, accum);
			}
			return accum;
		}
	};
}
#endif