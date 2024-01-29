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
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H


#include<chrono>
#include<string>

namespace seneca {
	const int MAX_EVENTS = 10;
	class TimedEvents {

		int m_records{0};
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		struct Event {
			std::string e_name;
			std::string e_unitOfTime;
			std::chrono::steady_clock::duration m_duration;
		};
		struct Event events[MAX_EVENTS];

	public:
		TimedEvents() {};
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedEvents& other);
	
	};

}
#endif // !SENECA_TIMEDEVENTS_H

