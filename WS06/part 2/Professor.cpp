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
#include "Professor.h"
#include "Employee.h"

using namespace std;

namespace seneca {

    
    Professor::Professor(std::istream& in) : Employee(in){
        string dept{};
        getline(in, dept, '\n');
        m_department = trim(dept, " ");
    }

    void Professor::display(std::ostream& out) const {
        Employee::display(out); 
        out << m_department << "| Professor";
    }

    std::string Professor::status() const {
        return "Professor";
    }
    std::string Professor::department() const {
        return m_department;
    }
}
