#include "Pair.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace seneca {
    Pair::Pair() {};

        
        std::ostream& Pair::display(std::ostream& os) const {
            os << setw(20) << right << m_key << ": " << left << m_value;
            return os;
        }
    
       
        std::ostream& operator<<(std::ostream& os, const Pair& pair) {
            return pair.display(os);
        }
    
}