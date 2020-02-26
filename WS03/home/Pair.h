//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__
#include <iostream>

using namespace std;
namespace sdds
{
	template <typename K, typename V>
	class Pair {
		K m_key;
		V m_value;

	public:
		Pair() : m_key{}, m_value{} {
		}

		Pair(const K& key, const V& value) : m_key(key), m_value(value) {
		}

		const K& getKey() const { return m_key;}

		const V& getValue() const { return m_value;}

		virtual void display(ostream& os) const {
			os << m_key << " : " << m_value << endl;
		}
	};

	template <typename K, typename V>
	ostream& operator<<(ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif