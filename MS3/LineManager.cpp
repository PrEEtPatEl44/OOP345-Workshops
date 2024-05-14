// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:5th April 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"
#include "Utilities.h"
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
namespace seneca {
    std::deque<CustomerOrder> g_pending, g_completed, g_incomplete;
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        ifstream fin(file);
        string line, firstStation, secondStation;
        Utilities util;
        Utilities::setDelimiter('|');
        if (!fin) {
            throw string("ERROR: Unable to open [") + file + "] file";
        }
        while (getline(fin, line)) {
            bool more = true;
            size_t next_pos = 0u;
            firstStation = util.extractToken(line, next_pos, more);
            secondStation = util.extractToken(line, next_pos, more);
            auto firstIterator = find_if(stations.begin(), stations.end(), [&](const Workstation* workstation) {return workstation->getItemName() == firstStation; });
            auto secondIterator = find_if(stations.begin(), stations.end(), [&](const Workstation* workstation) {return workstation->getItemName() == secondStation; });
            if (firstIterator != stations.end() && secondIterator != stations.end()) {
                (*firstIterator)->setNextStation(*secondIterator);
            }
            if (firstIterator != stations.end()) m_activeLine.push_back(*firstIterator);
        }
        auto firstIt = std::find_if(stations.begin(), stations.end(), [&](const Workstation* lhs) {
            return std::none_of(m_activeLine.begin(), m_activeLine.end(),
            [&](const Workstation* rhs) { return lhs == rhs->getNextStation(); });
            });
        int occurence = std::count_if(stations.begin(), stations.end(), [&](const Workstation* lhs) {
            return std::none_of(m_activeLine.begin(), m_activeLine.end(),
            [&](const Workstation* rhs) { return lhs == rhs->getNextStation(); });
            });
        if (occurence > 1) throw string("ERROR: More than 1 start station.");

        if (firstIt != stations.end()) {
            m_firstStation = *firstIt;
        }
        else {
            throw string("ERROR: No end station found.");
        }
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        vector<Workstation*> sort_activeLine;
        Workstation* currentWorkstation;
        currentWorkstation = m_firstStation;
        sort_activeLine.push_back(currentWorkstation);
        while (sort_activeLine.size() != m_activeLine.size()) {
            currentWorkstation = currentWorkstation->getNextStation();
            sort_activeLine.push_back(currentWorkstation);
        }
        m_activeLine = std::move(sort_activeLine);
    }

    bool LineManager::run(std::ostream& os) {
        static size_t count = 0;
        os << "Line Manager Iteration: " << ++count << std::endl;
        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }
        for (auto& workstation : m_activeLine) {
            workstation->fill(os);
        }
        for (auto& workstation : m_activeLine) {
            workstation->attemptToMoveOrder();
        }
        return (g_completed.size() + g_incomplete.size()) == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        for (auto& workstation : m_activeLine) {
            workstation->display(os);
        }
    }
}