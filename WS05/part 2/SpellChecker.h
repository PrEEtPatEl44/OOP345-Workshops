/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 18th february 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>

namespace seneca {
    const unsigned int SIZE = 6;
    class SpellChecker {
    private:
        std::string m_badWords[SIZE]{};
        std::string m_goodWords[SIZE]{};
        size_t m_correctionCounts[SIZE]{ 0 };
    public:
        SpellChecker() = default;
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif 