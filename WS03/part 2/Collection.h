/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 3rd february 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Pair.h"
namespace seneca {
	template<typename T, int CAPACITY>
	class Collection {
		//static obj initialised outside class
		static  T m_dummyObj;
		int m_currentElements=0;
		T m_collection[CAPACITY];
	public:
		//destructor for inclusion polymorphism
		virtual ~Collection() {}
		int size() { return m_currentElements; }

		T& operator[](int index) {
			if (index >= 0 && index < m_currentElements) return m_collection[index];
			return m_dummyObj;
		}
		std::ostream& display(std::ostream& ostr = std::cout) const {
			ostr << "----------------------" << std::endl;
			ostr << "| Collection Content |" << std::endl;
			ostr << "----------------------" << std::endl;
			for (int i = 0; i < m_currentElements; i++) {
				ostr << m_collection[i] << std::endl;
			}

			ostr << "----------------------" << std::endl;

			return ostr;
		}
		virtual bool add(const T& item) {
			bool result{ false };
			if (m_currentElements < CAPACITY) {
				m_collection[m_currentElements] = item;
				m_currentElements++;
				result = true;
			}
			return result;
		}
	};
	template<typename T, int CAPACITY>
	T Collection<T, CAPACITY>::m_dummyObj {};
	//specilisation for pair obj
	template<>
	Pair Collection<Pair, 100>::m_dummyObj{Pair("No Key", "No Value")};

}
#endif // !SENECA_COLLECTION_H	

