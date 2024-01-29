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
#include "TimedEvents.h"
#include<iostream>
#include<iomanip>
using namespace std;
namespace seneca {

	void TimedEvents::startClock() {
		m_startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name) {

		if (m_records < MAX_EVENTS) {
			this->events[m_records].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
			this->events[m_records].e_unitOfTime = "nanoseconds";
			this->events[m_records].e_name = name;
			m_records++;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const TimedEvents& other){
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;
		for (int i = 0; i < other.m_records; i++) {
			ostr << setw(21) << left
				<< other.events[i].e_name << " " << setw(13) << right
				<< other.events[i].m_duration.count() << " "
				<< other.events[i].e_unitOfTime << " " << endl;
		}
		ostr << "--------------------------" << endl;

		return ostr;
	}
}