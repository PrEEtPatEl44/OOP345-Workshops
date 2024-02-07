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
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>

namespace seneca {
    class Pair
    {
        std::string m_key{};
        std::string m_value{};
    public:
        Pair();
        const std::string& getKey() { return m_key; }
        const std::string& getValue() { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

        std::ostream& display(std::ostream& ostr) const;
        bool operator==(const Pair& pair) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Pair& pair);
}

#endif 