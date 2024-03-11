/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 10th March 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_

#include <iostream>
#include "Person.h"

namespace seneca {

    
    class Employee : public Person {
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
        // removing whitespace from cstr
        static std::string trim(const std::string& cstr,
                const std::string& whitespace) {
            const auto strBegin = cstr.find_first_not_of(whitespace);
            if (strBegin == std::string::npos) {
                return "";
            }
            const auto strEnd = cstr.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return cstr.substr(strBegin, strRange);
        }
    public:
        Employee(std::istream& in = std::cin);
        std::string status() const;
        std::string name() const;
        std::string id() const;
        std::string age() const;
        void display(std::ostream& os) const;
    };
}

#endif 
