// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:5th April 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include "Utilities.h"
#include "CustomerOrder.h"
#include <deque>
namespace seneca
{
    extern std::deque<CustomerOrder> g_pending, g_completed, g_incomplete;
    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation{};
    public:
        Workstation(const std::string& str) :Station(str) {};
        ~Workstation() {};
        //workstation represents a single location on the assembly line  so it cannot be moved or copied
        Workstation(const Workstation& src) = delete;
        Workstation& operator=(const Workstation& src) = delete;
        Workstation(Workstation&& src) = delete;
        Workstation& operator=(Workstation&& src) = delete;
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}
#endif
