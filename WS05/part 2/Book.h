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
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>

namespace  seneca{
    class Book {
    private:
        std::string m_author{};
        std::string m_title {};
        std::string m_country{};
        size_t m_year{ 0 };
        double m_price{ 0 };
        std::string m_desc {};
    public:
        Book() = default;
        Book(const Book& book) = default;
        Book& operator=(const Book& book) = default;
        Book(const std::string& strBook);
        virtual ~Book() = default;
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_desc);
        }
    };
}

#endif 