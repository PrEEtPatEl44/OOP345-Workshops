/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 11th february 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include <iostream>
#include "Toy.h"

namespace seneca {
    class Child {
    private:
        std::string m_childName{};
        int m_age{ 0 };
        const seneca::Toy** toys { nullptr };
        size_t m_childToyCount = 0;
    public:
        
        Child() = default;
        Child(std::string name, int age, const Toy* toys[], size_t count);
        //Rule of 5
        Child(const Child& other);
        Child& operator=(const Child& other);
        Child(Child&& other) noexcept;
        Child& operator=(Child&& other) noexcept;
        ~Child();

        size_t size() const;
        friend std::ostream& operator<<(std::ostream& ostr, const Child& other);
    };
}

#endif 