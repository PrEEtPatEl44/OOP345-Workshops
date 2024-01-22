/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #1 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 21 January 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "event.h"
namespace seneca {
	unsigned int g_sysClock = 0;
	void Event::alocpy(char*& destination, const char* source) {
		if (destination != nullptr) {
			delete[] destination;
			destination = nullptr;

		}


		if (source != nullptr) {
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}
		else {
			destination = nullptr;
		}
	}
	Event& Event::operator=(const Event& src) {
		if (this != &src && src.m_desc != nullptr) {
			if (this->m_desc != nullptr) {
				delete[] this->m_desc;
			}
			alocpy(this->m_desc, src.m_desc);
			this->m_startTime = src.m_startTime;
		}
		return *this;
	}
	Event::Event(const Event& src) {
		if (src.m_desc != nullptr) {
			*this = src;//calls copy assignment opoerator
		}
	}
	Event::~Event() {
		if (this->m_desc != nullptr) {
			delete[] this->m_desc;
			this->m_desc = nullptr;
		}
	}
	void Event::display()const {
		static int count = 0;
		count++;
		std::cout << std::setw(2) << std::setfill(' ') << count << ". ";//count printing 
		int hours = this->m_startTime / 3600;
		int minutes = (this->m_startTime % 3600) / 60;
		int seconds = this->m_startTime % 60;
		if (m_desc) {
			std::cout << std::setw(2) << std::setfill('0')
				<< hours << ":"
				<< std::setw(2) << std::setfill('0')
				<<  minutes << ":"
				<< std::setw(2) << std::setfill('0')
				<<  seconds << " => ";
			std::cout << m_desc << std::endl;
		}
		else {
			std::cout << "| No Event |" << std::endl;
		}


	}
	void Event::set(const char* desc) {
		m_startTime = g_sysClock;
		if (desc) {
			alocpy(this->m_desc, desc);
		}
		else {
			if (this->m_desc != nullptr) {
				delete[] this->m_desc;
				this->m_desc = nullptr;
			}
		}
	}
}
