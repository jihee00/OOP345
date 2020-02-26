//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 1/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__
#include <iomanip>
#include <string>
#include "Pair.h"

using namespace std;
namespace sdds 
{
	template <typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V m_initSum;
		static size_t m_minFieldWidth;

	public: 
		PairSummable() :Pair<K, V>() {}

		PairSummable(const K& key, const V& value) : Pair<K, V>(key, value) {
			if (m_minFieldWidth < key.size())
				m_minFieldWidth = key.size();
		}

		static const V& getInitialValue() {
			return m_initSum;
		}

		V sum(const K& key, const V& val) const {
			return (Pair<K, V>::getKey() == key) ? (Pair<K, V>::getValue() + val) : val;
		}

		void display(ostream& os) const{
			os << left << setw(m_minFieldWidth);
			Pair<K, V>::display(os);
			os << right;
		}
	};

	//template declaration
	template<typename K, typename V>
	V PairSummable<K, V>::m_initSum = 0;

	template<typename K, typename V>
	size_t PairSummable<K, V>::m_minFieldWidth = 0;

	// template specializations
	template<>
	string PairSummable<string, string>::m_initSum = "";

	template<>
	int PairSummable<string, int>::m_initSum = 0;

	template<>
	string PairSummable<string, string>::sum(const string& key, const string& val) const {
		return (this->getKey() == key) ? (val == "" ? this->getValue() : val + ", " + this->getValue()) : val;
	}
}

#endif