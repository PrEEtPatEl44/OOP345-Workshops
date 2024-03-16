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
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace seneca {
    Book::Book(const std::string& strBook) {
        size_t indexStart{ 0 };
        size_t indexEnd = strBook.find(',');
        m_author = strBook.substr(indexStart, (indexEnd - indexStart));
        indexStart = indexEnd + 1;
        indexEnd = strBook.find(',', indexStart);
        m_author.erase(0, m_author.find_first_not_of(" \t\r\n"));
        m_author.erase(m_author.find_last_not_of(" \t\r\n") + 1);

        m_title = strBook.substr(indexStart, (indexEnd - indexStart));
        indexStart = indexEnd + 1;
        indexEnd = strBook.find(',', indexStart);
        m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
        m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);

        m_country = strBook.substr(indexStart, (indexEnd - indexStart));
        indexStart = indexEnd + 1;
        indexEnd = strBook.find(',', indexStart);

        m_country.erase(0, m_country.find_first_not_of(" \t\r\n"));
        m_country.erase(m_country.find_last_not_of(" \t\r\n") + 1);

        m_price = std::stod(strBook.substr(indexStart, (indexEnd - indexStart)));
        indexStart = indexEnd + 1;
        indexEnd = strBook.find(',', indexStart);


        m_year = std::stoi(strBook.substr(indexStart, (indexEnd - indexStart)));
        indexStart = indexEnd + 1;
        indexEnd = strBook.find('\n', indexStart);

        m_desc = strBook.substr(indexStart, indexEnd);

        m_desc.erase(0, m_desc.find_first_not_of(" \t\r\n"));
        m_desc.erase(m_desc.find_last_not_of(" \t\r\n") + 1);
    }

    const std::string& Book::title() const { return m_title; }
    const std::string& Book::country() const { return m_country; }
    const size_t& Book::year() const { return m_year; }
    double& Book::price() { return m_price; }
    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::right << std::setw(20) << book.m_author << " | ";
        os << std::right << std::setw(22) << book.m_title << " | ";
        os << std::right << std::setw(5) << book.m_country << " | ";
        os << std::right << std::setw(4) << book.m_year << " | ";
        os << std::right << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
        os << std::left << book.m_desc << "\n";
        return os;
    }
}