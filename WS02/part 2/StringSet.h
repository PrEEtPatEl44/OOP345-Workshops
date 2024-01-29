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
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include<string>
namespace seneca {
	class StringSet {
		std::string* m_string{};
		size_t m_numOfStrings=0;
	public:
		StringSet() ;
		StringSet(char *cstr);
		StringSet(const StringSet& other);//---------------------------------|
		StringSet(StringSet&& other)noexcept;                              //|
		StringSet& operator=(const StringSet& other);					   //|-----------------RULE OF 5	
		StringSet& operator=(StringSet&& other)noexcept;				   //|
		~StringSet();//------------------------------------------------------|
		size_t size();
		std::string operator[](size_t);
	};
}
#endif // !SENECA_STRINGSET_H
