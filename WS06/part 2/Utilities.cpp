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

#include "Employee.h"
#include "Student.h"
#include "Professor.h"
#include "Utilities.h"
#include "Person.h"

namespace seneca {
    
    Person* buildInstance(std::istream& in) {
        char c{};
        Person* p{};
        in >> c;
        in.ignore(); 
        if (c == 'e' || c == 'E')
            p = new Employee(in);
        else if (c == 's' || c == 'S')
            p = new Student(in);
        else if (c == 'p' || c == 'P')
            p = new Professor(in);        
        return p;
    }
}