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
#include "Toy.h"
#include <iostream>
#include <string>
#include <iomanip>

namespace seneca {
    Toy::Toy(const std::string& toy) {
        size_t s_index{ 0 };
        size_t e_index = toy.find(':');
        //storing Id
        m_orderID = std::stoi(toy.substr(s_index, (e_index - s_index)));
        s_index = e_index + 1;
        e_index = toy.find(':', s_index);
        //sotring Name
        m_name = toy.substr(s_index, (e_index - s_index));
        //removing whitespaces
        m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
        m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);
        s_index = e_index + 1;
        e_index = toy.find(':', s_index);
        //storing num of items
        m_numberOfItems = std::stoi(toy.substr(s_index, (e_index - s_index)));
        s_index = e_index + 1;
        e_index = toy.find(':', s_index);
       //storing price
        m_price = std::stod(toy.substr(s_index, (e_index - s_index)));
    }

    void Toy::update(size_t numItems) {
        m_numberOfItems = numItems;
    }

    std::ostream& operator<<(std::ostream& os, const Toy& toy) {
        double subTotal = toy.m_price * toy.m_numberOfItems;
        double taxes = subTotal * (toy.m_HSTPercentage / 100);
        double total= subTotal + taxes;

        os << "Toy" << std::right << std::setw(8) << toy.m_orderID << ":";
        os << std::right << std::setw(18) << toy.m_name;
        os << std::right << std::setw(3) << toy.m_numberOfItems << " items";
        os << std::setw(8) << toy.m_price << "/item";
        os << "  subtotal:";
        os << std::right << std::setw(7) << std::fixed << std::setprecision(2) << subTotal;
        os << std::right << " tax:" << std::setw(6) << taxes;
        os << std::right << " total:" << std::setw(7) << total << std::endl;
        return os;
    }
}