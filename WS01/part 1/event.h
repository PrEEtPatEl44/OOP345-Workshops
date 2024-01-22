#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {
	class Event
	{
		char m_desc[129];
		int m_startTime;
	public:
		Event();
		void display();
		void set(char* desc = nullptr);


	};
	extern unsigned int g_sysClock;
}
#endif 
