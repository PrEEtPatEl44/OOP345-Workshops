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

#include "Movie.h"
#include <iostream>
#include <iomanip>
#include<string>
namespace seneca {

    Movie::Movie(const std::string& strMovie) {

        size_t indexStart{ 0 };
        size_t indexEnd = strMovie.find(',');

        m_title = strMovie.substr(indexStart, (indexEnd - indexStart));
        indexStart = indexEnd + 1;
        indexEnd = strMovie.find(',', indexStart);

        m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
        m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);

        m_movieYear = std::stoi(strMovie.substr(indexStart, (indexEnd - indexStart)));
        indexStart = indexEnd + 1;
        indexEnd = strMovie.find('\n', indexStart);

        m_description = strMovie.substr(indexStart, indexEnd);

        m_description.erase(0, m_description.find_first_not_of(" \t\r\n"));
        m_description.erase(m_description.find_last_not_of(" \t\r\n") + 1);
    }

    const std::string& Movie::title() const { return m_title; }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::right << std::setw(40) << movie.m_title << " | ";
        os << std::setw(4) << movie.m_movieYear << " | ";
        os << std::left << std::setw(40) << movie.m_description << "\n";
        return os;
    }
}