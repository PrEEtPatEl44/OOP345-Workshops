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


#ifndef SENECA_SET_H
#define SENECA_SET_H
#include "Collection.h"
#include <iostream>
#include <cmath>

namespace seneca{
    //derived template
    template<typename T>
    class Set : public Collection<T, 100> {
    public:
        virtual bool add(const T& item) {
            int duplicateCount{ 0 };
            bool result{ false };
            for (int i = 0; i < Collection<T, 100>::size(); i++) {
                if (item == Collection<T, 100>::operator[](i)) {
                    duplicateCount++;
                }
            }
            if (duplicateCount == 0) {
                this->Collection<T, 100>::add(item);
            }
            return result;
        }
    };
    //specilisation for double 
    template<>
    bool Set<double>::add(const double& item) {
        int duplicateCount{ 0 };
        bool result{ false };
        for (int i = 0; i < Collection<double, 100>::size(); i++) {
            if (std::fabs(item - Collection<double, 100>::operator[](i)) <= 0.01) {
                duplicateCount++;
            }
        }
        if (duplicateCount == 0) {
            this->Collection<double, 100>::add(item);
        }

        return result;
    }
	};

#endif // SENECA_SET_H

