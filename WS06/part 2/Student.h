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
#ifndef SENECA_STUDENT_H_
#define SENECA_STUDENT_H_

#include <iostream>
#include <string>
#include "Person.h"

namespace seneca {
    class Student : public Person {
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
        std::string* m_courses{};
        int m_count{};
        static std::string trim(const std::string& str,
            const std::string& whitespace) {
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return ""; 
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        }
    public:
        Student(const Student& other) = delete;
        Student& operator=(const Student& other) = delete;
        Student(Student&& other) = delete;
        Student& operator=(Student&& other) = delete;

        Student(std::istream& in = std::cin);
        std::string status() const;
        std::string name() const;
        std::string age() const;
        std::string id() const;
        void display(std::ostream& out) const;
        ~Student();
    };
}

#endif 
