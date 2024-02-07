/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 3rd february 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "Pair.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace seneca {
    Pair::Pair() {};
    std::ostream& Pair::display(std::ostream& ostr) const {
        ostr << setw(20) << right << m_key << ": " << left << m_value;
        return ostr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Pair& pair) {
        return pair.display(ostr);
    }
    bool Pair::operator==(const Pair& pair) const {
        bool result = false;
        if (m_key == pair.m_key) {
            result = true;
        }
        return result;
    }

 }