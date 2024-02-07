#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
namespace seneca {
	template<typename T, size_t CAPACITY>
	class Collection {
		T m_dummyObj{};
		static  size_t m_currentElements;
		T m_collection[CAPACITY];
	public:
		size_t size() { return m_currentElements; }
		T& operator[](size_t index) {
			if (index >= 0 && index < m_currentElements) return m_collection[index];
			return m_dummyObj;
		}
		std::ostream& display(std::ostream& ostr = std::cout) const {
			ostr << "----------------------" << std::endl;
			ostr << "| Collection Content |" << std::endl;
			ostr << "----------------------" << std::endl;

			// Inserting all the elements size_to the stream
			for (size_t i = 0; i < m_currentElements; i++) {
				ostr << m_collection[i] << std::endl;
			}

			ostr << "----------------------" << std::endl;

			return ostr;
		}
		bool add(const T& item) {
			if (m_currentElements < CAPACITY) {
				m_collection[m_currentElements] = item;
				m_currentElements++;
				return true;
			}
			else return false;
		}
		
	};
	template <typename T, size_t CAPACITY>
	size_t Collection<T, CAPACITY>::m_currentElements = 0;

}
#endif // !SENECA_COLLECTION_H

