//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__

#include <iostream>
#include <string>
#include <stdexcept>

namespace sdds {

	template <typename T>
	class Collection {
		// the name of the collection
		std::string m_name{};
		// a dynamically allocated array of items T
		T* arr{ nullptr };
		// the size of the array
		size_t m_arrSize{0u};
		// the observer function
		void (*func)(const Collection<T>&, const T&) { nullptr };

	public:
		Collection() {}

		// sets the name of the collection to the parameter
		Collection(std::string name){
			this->m_name = name;
		}
		// this class doesn't support copy operations; delete them.
		Collection(const Collection<T>&) = delete;
		Collection& operator=(const Collection<T>&) = delete;
		Collection(Collection<T>&&) = delete;
		Collection& operator=(Collection<T>&&) = delete;

		// a destructor
		~Collection() {
			delete[] arr;
		}

		// a query that returns the name of the collection.
		const std::string& name() const {
			return m_name;
		}
		// a query that returns how many items are in the collection.
		size_t size() const {
			return m_arrSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) noexcept {
			func = observer;
		}

		// resize the array to accomodate the new item
		// if there is an observer registered, call the observer function passing* this and the new item as parameters.
		Collection<T>& operator+=(const T& item) {
			bool check = false;
			for (size_t i = 0; i < m_arrSize && !check; i++){
				if (item.title() == arr[i].title()) {
					check = true;
				}
			}
			if (!check) {
				T* tmp = new T[m_arrSize + 1];
				for (size_t i = 0; i < m_arrSize; i++) {
					tmp[i] = arr[i];
				}
				tmp[m_arrSize++] = item;
				delete[] arr;
				arr = tmp;
				if (func != nullptr) {
					func(*this, item);
				}
				tmp = nullptr;
			}
			return *this;
		}

		// returns the item at index 
		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= m_arrSize) {
				throw std::out_of_range("Bad index ["+ std::to_string(idx) + "]. "
					+ "Collection has ["+ std::to_string(m_arrSize) + "] items.");
			}
			return arr[idx];
		}

		// returns the address of the item with title 
		T* operator[](std::string title) const {
			T* tmp = nullptr;
			for (size_t i = 0; i < m_arrSize && tmp == nullptr; i++) {
				if (arr[i].title() == title) {
					tmp = arr + i;
				}
			}
			return tmp;
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& obj) {
		for (size_t i = 0; i < obj.size(); i++) {
			os << obj[i];
		}
		return os;
	}
}

#endif
