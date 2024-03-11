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
#include <iomanip>
#include "College.h"
#include "Employee.h"
#include "Person.h"

using namespace std;

namespace seneca {


    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& out) const {
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        out << "|                                        Test #1 Persons in the college!                                               |\n";
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            (*it)->display(out);
            cout << endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        out << "|                                        Test #2 Persons in the college!                                               |\n";
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
            out << "| " << setw(10) << (*it)->status() << "| " << setw(10) << (*it)->id() << "| " << setw(20) << (*it)->name()
            << " | " << setw(3) << (*it)->age() << " |\n";
        out << "------------------------------------------------------------------------------------------------------------------------\n";
    }

    College::~College() {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            delete *it;
        }
    }
}