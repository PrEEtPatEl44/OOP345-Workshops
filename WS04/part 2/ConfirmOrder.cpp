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
#include "ConfirmOrder.h"
#include <iostream>

namespace seneca{
   
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& other) {
        *this = other;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
        if (this != &other) { 
            delete[] toys;
            toys = new const Toy * [other.m_orderToyCount];
            for (size_t i = 0; i < other.m_orderToyCount; i++) {
                toys[i] = other.toys[i];
            }
            m_orderToyCount = other.m_orderToyCount;
        }
        return *this;
    }


    ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) noexcept {
        *this = std::move(other);
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept {
        if (this != &other) {
            delete[] toys;
            toys = other.toys;
            other.toys = nullptr;
            m_orderToyCount = other.m_orderToyCount;
            other.m_orderToyCount = 0;
        }
        return *this;
    }


    ConfirmOrder::~ConfirmOrder() {
        delete[] toys;
    }


    ConfirmOrder& ConfirmOrder::operator+=(const Toy& other) {
        bool flag = false;
        for (size_t i = 0; i < m_orderToyCount; i++) {
            if (toys[i] == &other) {
                flag = true;
                //do nothing if toy is in the array 
            }
        }
        if (!flag) {
             
            const Toy** tempArray = new const Toy * [m_orderToyCount + 1];
            for (size_t i = 0; i < m_orderToyCount; i++) {
                tempArray[i] = toys[i];
            }
            tempArray[m_orderToyCount] = &other;
            m_orderToyCount++;
            delete[] toys;
            toys = tempArray;
        }

        return *this;
    }


    ConfirmOrder& ConfirmOrder::operator-=(const Toy& other) {
        bool flag = false;
        size_t indexOfToy = -1;
        for (size_t i = 0; i < m_orderToyCount; i++) {
            if (toys[i] == &other) {
                //check if toy is in array or not
                flag = true;
                indexOfToy = i;
               
            }
        }

    
        if (flag) {
            const Toy** tempArray = new const Toy * [m_orderToyCount - 1];
            size_t realIndexOfToy = 0 ;
            for (size_t i = 0; i < m_orderToyCount; i++) {
                if (i != indexOfToy) {
                    tempArray[realIndexOfToy] = toys[i];
                    realIndexOfToy++;
                }
            }
            m_orderToyCount--;
            delete[] toys;
            toys = tempArray;
        }

        return *this;
    }


    std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& other) {
        ostr << "--------------------------" << std::endl;
        ostr << "Confirmations to Send" << std::endl;
        ostr << "--------------------------" << std::endl;
        if (other.m_orderToyCount == 0) {
            ostr << "There are no confirmations to send!" << std::endl;
        }
        else {
            for (size_t i = 0; i < other.m_orderToyCount; i++) {
                ostr << *other.toys[i];
            }
        }
        ostr << "--------------------------\n";
        return ostr;
    }
}