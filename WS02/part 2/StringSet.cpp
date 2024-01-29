/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 28 January 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "StringSet.h"
namespace seneca {
	StringSet::StringSet() {
		m_string = nullptr;
		m_numOfStrings = 0;
	}

	seneca::StringSet::StringSet(char* cstr) {
		char ch;
		this->m_numOfStrings = 1;
		std::ifstream inputFile(cstr);
		while (inputFile.get(ch)) {
			if (ch == ' ') {
				m_numOfStrings++;//counting the number of strings
			}
		}
		inputFile.clear();
		inputFile.seekg(std::ios::beg);
		m_string = new std::string[m_numOfStrings];
		for (unsigned int i = 0; i < m_numOfStrings; i++) {
			std::getline(inputFile, m_string[i], ' ');//pushing the words to the m_string array
		}

	}
	StringSet::StringSet(const StringSet& other) {//copy constructor
		*this = other;
	}

	StringSet::StringSet(StringSet&& other)noexcept {//move constructor
		*this = std::move(other);
	}

	StringSet& StringSet::operator=(const StringSet& other) {//copy assignment operator
		if (this != &other) {
			this->m_numOfStrings = other.m_numOfStrings;
			delete[] m_string;
			m_string = nullptr;
			if (m_numOfStrings != 0) {
				this->m_string = new std::string[m_numOfStrings];
				for (size_t i = 0; i < m_numOfStrings; i++) {
					m_string[i] = other.m_string[i];
				}
			}
		}
		return *this;
	}

	StringSet& StringSet::operator=(StringSet&& other)noexcept {//move assignment operator
		if (this != &other) {
			delete[] this->m_string;
			this->m_string = other.m_string;

			other.m_string = nullptr;

			this->m_numOfStrings = other.m_numOfStrings;
			other.m_numOfStrings = 0;
		}
		return *this;
	}

	size_t StringSet::size() {
		return m_numOfStrings;
	}
	std::string StringSet::operator[](size_t i) {
		if (i < this->m_numOfStrings) {
			return this->m_string[i];
		}
		else {
			return std::string();
		}


	}
	StringSet::~StringSet(){//destructor
		if (m_string)
		{
			delete[] m_string;
		}
	}

}
