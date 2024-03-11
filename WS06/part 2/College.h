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
#ifndef SENECA_COLLEGE_H_
#define SENECA_COLLEGE_H_

#include <iostream>
#include <vector>
#include <list>
#include "Person.h"

namespace seneca {

    class College {
        std::vector<Person*> m_persons{};
    public:
        College() = default;
        College(const College&) = delete;
        College& operator=(const College&) = delete;
        College(College&&) = delete;
        College& operator=(College&&) = delete;
        College& operator+=(Person* thePerson);
        void display(std::ostream& out) const;
        virtual ~College();
        
        template <typename T>
        void select(const T& test, std::list<const Person*>& persons);
    };
    template<typename T>
    void College::select(const T& test, std::list<const Person*>& persons) {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) 
            if (test(*it))
                persons.push_back(*it);
    }
}


#endif 

