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


#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <iostream>

namespace seneca {
    class Toy {
    private:
        int m_orderID = 0;
        std::string m_name {};
        size_t m_numberOfItems = 0;
        double m_price = 0.0;
        double m_HSTPercentage = 13;
    public:
        //default constructor
        Toy() = default;
        //extracts info from the token using string
        Toy(const std::string& );
        void update(size_t numItems);
        friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
    };
}

#endif 