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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include <iostream>
#include "Toy.h"

namespace seneca {
    class ConfirmOrder {
    private:
        const seneca::Toy** toys{ nullptr };
        size_t m_orderToyCount{ 0 };
    public:
        ConfirmOrder() = default;
        //rule of 5
        ConfirmOrder(const ConfirmOrder& other);
        ConfirmOrder& operator=(const ConfirmOrder& other);
        ConfirmOrder(ConfirmOrder&& other) noexcept;
        ConfirmOrder& operator=(ConfirmOrder&& other) noexcept;
        ~ConfirmOrder();
        ConfirmOrder& operator+=(const Toy& other);
        ConfirmOrder& operator-=(const Toy& other);
        friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& other);
    };
}

#endif 