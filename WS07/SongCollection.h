// Workshop 7: STL Algorithms
// Victor Lozano - 2021/11/10
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS07_SONGCOLLECTION_H
#define WS07_SONGCOLLECTION_H

#include <iostream>
#include <vector>
#include <list>

namespace sdds {
    struct Song {
        std::string m_artist{};
        std::string m_title{};
        std::string m_album{};
        double m_price{0.0};
        int m_year{0};
        int m_length{0};

        std::string operator=(const std::string &album);
    };

    class SongCollection {
        std::vector<Song> m_collection;
    public:
        SongCollection(const char *filename);
        void display(std::ostream &out) const;
        void trim(std::string &str) const;
        void sort(const std::string &filter);
        void cleanAlbum();
        bool inCollection(const std::string &filter) const;
        std::list<Song> getSongsForArtist(const std::string &filter) const;
    };
    std::ostream &operator<<(std::ostream &out, const Song &theSong);
}
#endif //WS07_SONGCOLLECTION_H
