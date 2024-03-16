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

#include "Child.h"
#include <iostream>

namespace seneca {
    Child::Child(std::string name, int age, const Toy* toysArr[], size_t count) : m_childName(name), m_age(age), m_childToyCount(count) {
        if (count > 0) {
            toys = new const Toy * [m_childToyCount];
            for (size_t i = 0; i < m_childToyCount; i++) {
                toys[i] = new Toy(*(toysArr[i]));
            }
        }
        else {
            toys = nullptr;
        }
    }

  
    Child::Child(const Child& other) {
        *this = other;
    }

    Child& Child::operator=(const Child& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_childToyCount; i++) {
                delete toys[i];
            }
            delete[] toys;
            toys = nullptr;

            if (other.toys) {
                toys = new const Toy * [other.m_childToyCount];
                for (size_t i = 0; i < other.m_childToyCount; i++) {
                    toys[i] = new Toy(*(other.toys[i]));
                }
            }
            m_childName = other.m_childName;
            m_age = other.m_age;
            m_childToyCount = other.m_childToyCount;
        }

        return *this;
    }

    Child::Child(Child&& other) noexcept {
        *this = std::move(other);
    }

    Child& Child::operator=(Child&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_childToyCount; i++) {
                delete toys[i];
            }
            delete[] toys;
            toys = nullptr;
            toys = other.toys;
            other.toys = nullptr;
            m_childName = other.m_childName;
            other.m_childName = "";
            m_age = other.m_age;
            other.m_age = 0;
            m_childToyCount = other.m_childToyCount;
            other.m_childToyCount = 0;
        }

        return *this;
    }

    Child::~Child() {
        for (size_t i = 0; i < m_childToyCount; i++) {
            delete toys[i];
        }
        delete[] toys;
    }

    size_t Child::size() const {
        return m_childToyCount;
    }

    std::ostream& operator<<(std::ostream& ostr, const Child& other) {
        static int count{ 1 };
        ostr << "--------------------------" << std::endl;
        ostr << "Child " << count<< ": " << other.m_childName << " " << other.m_age << " years old:" << std::endl;
        ostr << "--------------------------" << std::endl;
        if (other.size() > 0) {
            for (size_t i = 0; i < other.size(); i++) {
                ostr << *other.toys[i];
            }
        }
        else {
            ostr << "This child has no toys!" << std::endl;
        }
        ostr << "--------------------------" << std::endl;

        count++;
        return ostr;
    }
}