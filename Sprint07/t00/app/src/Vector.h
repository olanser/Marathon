#pragma once

#include <iostream>

namespace CBL {
    
template <class T>
class Vector {
public:
    using iterator = T*;

    Vector(): Vector(0) {};
    explicit Vector(size_t size) : m_size(size), m_capacity(size)  {
        m_buffer = new T[m_capacity];
    };
    Vector(size_t size, const T& value) : Vector(size) {
        for (int i = 0; i < size; i++)
            m_buffer[i] = value;
    };
    Vector(iterator first, iterator last) : Vector(std::distance(first, last)) {
        for (int i = 0; first != last; first++, i++)
            m_buffer[i] = *first;
        
    };
    Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
        int i = 0;
        for (auto temp = lst.begin(); temp != lst.end(); i++, temp++)
            m_buffer[i] = *temp;
    };

    Vector(const Vector<T>& other): Vector(other.size()) {
        int i = 0;
        for (auto tem = other.begin(); i < m_size; ++i, ++tem) {
            m_buffer[i] = *tem;
        }
    };
    ~Vector() {
        if (m_capacity > 0)
            delete [] m_buffer;
    };

    Vector<T>& operator=(const Vector<T>& other) {
        if (m_capacity > 0)
            delete [] m_buffer;
        m_size = other.size();
        m_capacity = other.capacity();
        m_buffer = new T[m_capacity];
        auto temp = other.begin();
        for (int i = 0;  temp != other.end(); temp++, i++)
            m_buffer[i] = *temp;
        return *this;
    };
    bool operator==(const Vector<T>& other) const {
        if (m_size != other.size())
            return false;
        auto i = 0;
        for (auto check = other.begin(); i < m_size; ++i, ++check)
            if (*check != m_buffer[i])
                return false;
        return true;
    }
    bool operator!=(const Vector<T>& other) const {
        return !(*this == other);
    };
    bool operator<(const Vector<T>& other) const {
        auto i = 0;
        auto temp = other.begin();
        for (; temp != other.end() && i < m_size; i++, temp++) {
            if (m_buffer[i] < *temp)
                return true;
            else if (m_buffer[i] > *temp)
                return false;
        }
        if (i != m_size || (i == m_size && temp == other.end()))
            return false;

        return true;
    };
    bool operator>(const Vector<T>& other) const {
        return !(*this < other) && (*this != other);
    };
    bool operator<=(const Vector<T>& other) const {
        return (operator<(other) || operator==(other)); 
    };
    bool operator>=(const Vector<T>& other) const {
        return (operator>(other) || operator==(other)); 
    };
    
    // iterators
    iterator begin() const {
        return &m_buffer[0];
    };
    iterator end() const {
        return &m_buffer[m_size];
    };
    
    // capacity
    size_t size() const {return m_size;};
    size_t capacity() const {return m_capacity;};
    bool isEmpty() const { return m_size == 0 ? true : false;};
    void resize(size_t size, const T& value = T()) {
        if (size > m_capacity || size < m_capacity) {
            auto temp = new T[size];
            for (int i = 0; i < size; ++i) {
                if (i < m_size)
                    temp[i] = m_buffer[i];
                else
                    temp[i] = value;
            }
            if (m_capacity > 0)
                delete [] m_buffer;
            m_buffer = temp;
            m_size = size;
            m_capacity = size;
        } 
    }
    void reserve(size_t size) {
        if (size > m_capacity) {
            auto temp = new T[size];
            for (int i = 0; i < m_size; i++)
                temp[i] = m_buffer[i];
            if (m_capacity > 0)
                delete [] m_buffer;
            m_buffer = temp;
            m_capacity = size;
        }
    };
    
    // element access
    T& operator[](size_t index) const {
        return m_buffer[index];
    }
    T& at(size_t index) const {
        if (index >= m_size)
            throw std::out_of_range("");
    }
    T* data() const {
        return &m_buffer[0];
    }
    
    // modifiers
    void push_back(const T& value) {
        if (m_capacity == m_size) {
            if (m_capacity == 0)
                m_capacity = 1;
            m_capacity *= 2;
            auto temp = new T[m_capacity];
            for (int i = 0; i < m_size; i++)
            temp[i] = m_buffer[i];
            if (m_capacity > 0)
                delete [] m_buffer;
            m_buffer = temp;
        }
        m_buffer[m_size] = value;
        ++m_size;
    };

    void pop_back() {
        if (m_size > 0) {
            --m_size;
        }
    };
    iterator insert(iterator pos, const T& value) {
        auto iter = pos - begin();
        if (m_capacity == m_size) {
            if (m_capacity == 0)
                m_capacity = 1;
            m_capacity *= 2;
            auto temp = new T[m_capacity];
            for (int i = 0; i < m_size; i++)
            temp[i] = m_buffer[i];
            if (m_capacity > 0)
                delete [] m_buffer;
            m_buffer = temp;
        }
        ++m_size;
        for (auto i = m_size - 1; i > iter; --i) {
            m_buffer[i] = m_buffer[i - 1];
        }
        m_buffer[iter] = value;
        return &m_buffer[iter];
    };
    iterator erase(iterator pos) {
        auto iter = pos - begin();
        for (; pos + 1 != end(); ++pos)
            *pos = *(pos + 1);
        --m_size;
        if (m_size == 0)
            return nullptr;
        return &m_buffer[iter];
    };
    iterator erase(iterator first, iterator last) {
        auto iter = first - begin();
        for (; last != end(); ++first, ++last) {
            *first = *last;
        }
        m_size -= last - first;
        if (m_size == 0)
            return nullptr;
        return &m_buffer[iter];
    };
    void clear() {
        m_size = 0;
    };

private:
    size_t m_size{0};
    size_t m_capacity{0};
    T* m_buffer{nullptr};
};

} // end namespace CBL
