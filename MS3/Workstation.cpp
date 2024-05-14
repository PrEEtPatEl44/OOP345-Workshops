// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:5th April 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <algorithm>
#include <iostream>
#include "Workstation.h"
using namespace std;
namespace seneca {
    void Workstation::fill(std::ostream& os)
    {
        if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
    }

    bool Workstation::attemptToMoveOrder()
    {
        bool moved = false;
        if (!m_orders.empty()) {
            if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() <= 0) {
                if (m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                }
                else {
                    if (!m_orders.front().isOrderFilled()) {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                    else { g_completed.push_back(std::move(m_orders.front())); }
                    m_orders.pop_front();
                }
                moved = true;
            }
        }
        return moved;
    }

    void Workstation::setNextStation(Workstation* station = nullptr)
    {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
        os << getItemName() << " --> ";
        os << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line");
        os << endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
    {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}