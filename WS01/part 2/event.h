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

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H


namespace seneca
{
extern unsigned g_sysClock; 
	class Event
	{
		char* m_desc = nullptr;
		unsigned int m_startTime = 0;
		void alocpy(char*& destination, const char* source);//From Final prj of OOP244
	public:
		Event() {};
		Event(const Event&src); //copy constructor			   -|
		Event& operator=(const Event&); //copy assignment		|---Rule of three
		~Event();//destructor								   -|
		void display() const;
		void set(const char* desc = nullptr);
	};
}

#endif 