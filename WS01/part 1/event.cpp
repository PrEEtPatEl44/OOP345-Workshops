#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iomanip>
#include <iostream>
#include <cstring>



namespace seneca {
	unsigned int g_sysClock = 0;
	Event::Event() :m_startTime(0) {
		m_desc[0] = '\0';
	}

	void Event::display() {
		static int counter = 0;
		counter++;
		int hours = m_startTime / 3600;
		int minutes = (m_startTime % 3600) / 60;
		int seconds = m_startTime % 60;
		if (m_desc[0] != '\0') {
			std::cout << std::setw(2) << std::setfill(' ') << counter << ". " << std::setfill('0') << std::setw(2) << hours << ":"
				<< std::setw(2) << minutes << ":"
				<< std::setw(2) << seconds << " => "
				<< m_desc << std::endl;
		}
		else {
			std::cout << std::setw(2) << std::setfill(' ') << counter << ". " << "| No Event |" << std::endl;
		}
	}
	void Event::set(char* desc) {
		if (desc != nullptr && desc[0] != '\0') {
			int len = strlen(desc);
			len = (len > 128) ? 128 : len;
			strncpy(this->m_desc, desc, len);
			this->m_desc[len] = '\0';
			m_startTime = seneca::g_sysClock;

		}
		else {

			this->m_desc[0] = '\0';
			this->m_startTime = 0;
		}
	}

}
