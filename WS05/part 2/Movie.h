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

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <iostream>

namespace seneca {
    class Movie {
    private:
        std::string m_title{};
        size_t m_movieYear{};
        std::string m_description {};
    public:
        Movie() = default;

        Movie(const std::string& strMovie);

        const std::string& title() const;

        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

        template<typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }
    };
}

#endif 