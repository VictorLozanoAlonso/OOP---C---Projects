// Project: MS3
// Victor Lozano - 2021/11/27
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "LineManager.h"
#include <algorithm>

namespace sdds{
    LineManager::LineManager(const std::string &file, const std::vector<Workstation*> &stations) {
        std::ifstream f(file);
        if (!f){
            throw std::string("***Failed to open file ");
        }
        Utilities aux;
        std::string buffer, name_station;
        size_t n_pos {0};
        Workstation* left_station;
        Workstation* right_station;
        bool more{true};
        while(std::getline(f, buffer)){
            name_station = aux.extractToken(buffer,n_pos,more);
            auto filter = [&](Workstation* station){return station->getItemName() == name_station;};
            left_station = *std::find_if(stations.begin(), stations.end(), filter);
            activeLine.push_back(left_station);
            if(more){
                name_station = aux.extractToken(buffer,n_pos,more);
                right_station = *std::find_if(stations.begin(), stations.end(), filter);
                left_station->setNextStation(right_station);
            }
            n_pos = 0;
        }
        f.close();
        auto f_station = [&](Workstation* station){
            std::for_each(stations.begin(), stations.end(), [&](Workstation* st){
               m_firstStation = *std::find_if_not(stations.begin(), stations.end(), [&](Workstation* st){
                  return station == st->getNextStation();
               });
            });
        };
        std::for_each(stations.begin(), stations.end(), f_station);
        m_cntCustomerOrder = sdds::pending.size();
    }
    void LineManager::linkStations() {
        std::vector<Workstation*> temp;
        Workstation* aux{nullptr};
        size_t i{0};
        temp.push_back(m_firstStation);
        do {
            aux = *std::find_if(activeLine.begin(), activeLine.end(), [&](Workstation *station) {
                return temp[i]->getNextStation()->getItemName() == station->getItemName();
            });
            temp.push_back(aux);
            i++;
        } while(temp[i]->getNextStation() != nullptr);
        activeLine = temp;
    }
    bool LineManager::run(std::ostream& os){
        static size_t iterations = 0;
        os << "Line Manager Iteration: " << ++iterations << std::endl;

        if (pending.size() != 0) {
            *m_firstStation += std::move(pending.front());
            pending.pop_front();
        }
        std::for_each(activeLine.begin(),activeLine.end(), [&os](Workstation* station){
            station->fill(os);
        });
        std::for_each(activeLine.begin(),activeLine.end(), [](Workstation* station){
            station->attemptToMoveOrder();
        });
        return m_cntCustomerOrder == (completed.size() + incomplete.size() + pending.size());
    }

    void LineManager::display(std::ostream& os) const
    {
        for(size_t i = 0; i < activeLine.size(); i++){
            activeLine[i]->display(os);
        }
    }
}