// Workshop 5 - Functions and Error Handling
// Victor Lozano - 2021/10/16
// Email  : vlozano-alonso@myseneca.ca
// ID     : 130720204
// Observations: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef WS05_COLLECTION_H
#define WS05_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds {
    template<class T>
    class Collection {
        std::string m_name;
        T *m_items;
        size_t m_size;
        void (*obsFunc)(const Collection<T> &, const T &);

    public:
        Collection() : m_name{""}, m_items{nullptr}, m_size{0u}, obsFunc{nullptr} {}
        Collection(std::string name) : m_name{""} {
            m_name = name;
            m_size = 0u;
            m_items = nullptr;
            obsFunc = nullptr;
        }
        ~Collection() { delete[] m_items; }
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection(Collection&&) = delete;
        Collection& operator=(Collection&&) = delete;

        const std::string &name() const { return m_name; }
        size_t size() const { return m_size; }

        void setObserver(void (*observer)(const Collection<T> &col, const T &item)) {
            obsFunc = observer;
        }

        Collection<T> &operator+=(const T &item) {
            bool exist = false;
            for (size_t i = 0; i < m_size; i++) {
                if (m_items[i].title() == item.title()) {
                    exist = true;
                }
            }
            if(!exist) {
                if (m_items != nullptr) {
                    T *temp = new T[m_size + 1];
                    for (size_t i = 0u; i < m_size; i++) {
                        temp[i] = T(m_items[i]);
                    }
                    delete[] m_items;
                    m_items = temp;
                    temp = nullptr;
                    m_items[m_size] = item;
                    m_size++;
                } else {
                    m_items = new T[m_size + 1];
                    m_items[m_size] = item;
                    m_size++;
                }
                if(obsFunc != nullptr)
                    obsFunc(*this,item);
            }
            return *this;
        }
        T& operator[](size_t idx) const{
            if(idx > m_size - 1) {
                std::string message =
                        "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) +
                        "] items.";
                throw std::out_of_range (message);
            }
            return m_items[idx];
        }
        T* operator[](const std::string& title) const{
            auto i = 0u;
            for(i = 0u; i < m_size && m_items[i].title().compare(title) != 0; i++) {}
            if(i == m_size)
                return nullptr;
            return &m_items[i];
        }
    };
    template<class T>
    std::ostream &operator<<(std::ostream &out, const Collection<T> &collection) {
        for(auto i = 0u; i < collection.size(); i++){
            out << collection[i];
        }
        return out;
    }
}

#endif //WS05_COLLECTION_H
