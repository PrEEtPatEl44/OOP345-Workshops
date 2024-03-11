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

#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

using namespace std;

namespace seneca{

    Employee::Employee(std::istream& in) {
        string str{}, str2{};
        getline(in, str, ',');
        m_name = trim(str, " ");
        getline(in, str, ',');
        m_age = trim(str, " ");
        char ch{};
        in.get(ch);
        do {
            str2 += ch;
            in.get(ch);
        } while (ch != '\n' && ch != ',');
        m_id = trim(str2, " ");
        if (m_id[0] != 'E')
            throw(m_name + "++Invalid record!");
    }

    std::string Employee::status() const {
        return std::string("Employee");
    }
    std::string Employee::name() const {
        return m_name;
    }
    std::string Employee::id() const {
        return m_id;
    }
    std::string Employee::age() const {
        return m_age;
    }


    void Employee::display(std::ostream& os) const{
        os << "| " << left << setw(10) << "Employee" << "| " 
            << setw(10) << m_id << "| " << setw(20) << m_name 
            << " | " << setw(3) << m_age << " |";
    }
}