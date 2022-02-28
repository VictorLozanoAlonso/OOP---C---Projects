// Workshop 7: STL Algorithms
// Victor Lozano - 2021/11/10
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "SongCollection.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <iomanip>

namespace sdds {
    void SongCollection::trim(std::string &str) const {
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; ++i);
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
        str = str.substr(0, i);
    }

    SongCollection::SongCollection(const char *filename) {
        Song temp;
        if (filename) {
            std::ifstream file(filename);
            if (!file) {
                throw "ERROR: Cannot open file";
            }
            do {
                std::string buffer;
                temp.m_artist.resize(25);
                temp.m_title.resize(25);
                temp.m_album.resize(25);
                buffer.resize(5);
                file.read(&temp.m_title[0], 25);
                trim(temp.m_title);
                file.read(&temp.m_artist[0], 25);
                trim(temp.m_artist);
                file.read(&temp.m_album[0], 25);
                trim(temp.m_album);
                file.read(&buffer[0], 5);
                trim(buffer);
                if (buffer.length() > 0) {
                    temp.m_year = std::stoi(buffer);
                } else
                    temp.m_year = 0;
                file >> temp.m_length;
                file >> temp.m_price;

                file.ignore(10, '\n');

                m_collection.push_back(temp);
            } while (!file.eof());
            file.close();
        } else
            throw "Filename is incorrect!";
    }

    void SongCollection::display(std::ostream &out) const {
        size_t sum{0u};
        auto print = [&](const Song &song) {
            sum += song.m_length;
            out << song << std::endl;
        };
        std::for_each(m_collection.cbegin(), m_collection.cend(), print);
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        out << "| " << std::setw(77) << std::right << "Total Listening Time: "
            << sum / 60 / 60 << ":" << sum / 60 % 60 << ":" << sum % 60
            << " |" << std::endl;
    }

    void SongCollection::sort(const std::string &filter) {
        if (filter == "title") {
            auto sortBy = [](const Song &a, const Song &b) {
                return a.m_title < b.m_title;
            };
            std::sort(m_collection.begin(), m_collection.end(), sortBy);
        }
        if (filter == "album") {
            auto sortBy = [](const Song &a, const Song &b) {
                return a.m_album < b.m_album;
            };
            std::sort(m_collection.begin(), m_collection.end(), sortBy);
        }
        if (filter == "length") {
            auto sortBy = [](const Song &a, const Song &b) {
                return a.m_length < b.m_length;
            };
            std::sort(m_collection.begin(), m_collection.end(), sortBy);
        }
    }

    std::string Song::operator=(const std::string &album) {
        return m_album = album;
    }

    void SongCollection::cleanAlbum() {
        auto clean = [](const Song &s) {
            return s.m_album == "[None]";
        };
        std::replace_if(m_collection.begin(), m_collection.end(), clean, "");
    }

    bool SongCollection::inCollection(const std::string &filter) const {
        return std::any_of(m_collection.begin(), m_collection.end(),
                           [=](const Song &s) { return s.m_artist == filter; });
    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string &filter) const {
        std::list<Song> filterByArtist{};
        auto fArtist = [=](const Song &s) {
            return s.m_artist == filter;
        };
        std::copy_if(m_collection.begin(), m_collection.end(), back_inserter(filterByArtist), fArtist);
        return filterByArtist;
    }

    std::ostream &operator<<(std::ostream &os, const Song &s) {
        os << "| " << std::setw(20) << std::left << s.m_title
           << " | " << std::setw(15) << s.m_artist
           << " | " << std::setw(20) << s.m_album
           << " | " << std::setw(6) << std::right;
        (s.m_year == 0) ? os << "" : os << s.m_year;
        os << " | " << s.m_length / 60 << ":";
        ((s.m_length % 60) < 10) ? os << "0" : os << "";
        os << s.m_length % 60
           << " | " << s.m_price
           << " |";
        return os;
    }
}