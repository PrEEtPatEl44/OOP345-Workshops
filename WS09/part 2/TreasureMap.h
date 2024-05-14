/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #9 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 31st March 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_TREASUREMAP_H
#define SENECA_TREASUREMAP_H

#include <cstddef>
#include <iostream>
#include <string>

namespace seneca{

    size_t digForTreasure(const std::string& str, char mark);

    class TreasureMap{
        size_t rows = 0;
        size_t colSize = 0;
        std::string* map = nullptr;
    public:
        TreasureMap(const char* filename);
        ~TreasureMap();

        std::string operator[](int i) const{
            return map[i % rows];
        }

        size_t size() const{
            return rows;
        }

        std::ostream& display(std::ostream& os) const;
        void enscribe(const char* filename); 
        void recall(const char* filename);
        void clear();

        size_t findTreasure(char mark);
    };

}

#endif