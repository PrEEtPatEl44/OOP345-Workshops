#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>

namespace seneca {
    class Pair
    {
        std::string m_key{};
        std::string m_value{};
    public:
        Pair();
        const std::string& getKey() { return m_key; }
        const std::string& getValue() { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

        // Display Function
        std::ostream& display(std::ostream& os) const;
    };

    // Insertion operator overload
    std::ostream& operator<<(std::ostream& os, const Pair& pair);
}

#endif 