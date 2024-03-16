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
#include "SpellChecker.h"
#include <iostream>
#include <iomanip>
#include <fstream>

namespace seneca {

    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            throw "Bad file name!";
        }

        std::string badWord;
        std::string goodWord;
        int count = 0;
        while (file >> badWord >> goodWord) {
            m_badWords[count] = badWord;
            m_goodWords[count] = goodWord;
            count++;
        }

        file.close();
    }


    void SpellChecker::operator()(std::string& text) {
        size_t start{};
        for (size_t i = 0; i < SIZE; i++){
            start = 0;
            while ((start = text.find(m_badWords[i], start)) != std::string::npos){
                text.replace(start, m_badWords[i].length(), m_goodWords[i]);
                start += m_goodWords[i].length();
                m_correctionCounts[i]++;
            }

        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        size_t index = 0;
        out << "Spellchecker Statistics" << "\n";
        for (auto& badWord : m_badWords) {
            out << std::right << std::setw(15) << badWord << ": " << m_correctionCounts[index] << " replacements" << "\n";
            index++;
        }
    }
}