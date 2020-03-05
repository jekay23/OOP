#include <iostream>

using namespace std;

template <typename T> class Container {
public:
    void push_back(T pushed) {
        m_size++;
        if (m_size > m_capacity) {
            m_capacity *= 2;
            T* newHead = new T[m_capacity];
            T* newCurrent = newHead;
            for (T* oldCurrent = m_data; oldCurrent != m_memoryBack; oldCurrent++) {
                *newCurrent = *oldCurrent;
                newCurrent++;
            }
            delete[] m_data;
            m_data = newHead;
            m_dataBack = newCurrent;
            m_memoryBack = m_data + m_capacity;
        }
        m_data[m_size - 1] = pushed;
        m_dataBack++;
    }

    void pop_back() {
        m_size--;
    }

    T operator[] (size_t index) const {
        return m_data[index];
    }

    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return (bool) m_size;
    }

    void clear() {
        delete[] m_data;
        m_size = 0;
        m_dataBack = m_data;
    }

    Container(): m_size(0), m_capacity(4) {
        m_data = m_dataBack = new T[4];
        m_memoryBack = m_data + 4;
    }
    
    ~Container() {
        if (m_size) {
            delete[] m_data;
        }
    }
private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;
    T* m_dataBack;          //pointer set after the last unit with user data
    T* m_memoryBack;        //pointer set after the last allocated memory unit
};

template <typename T> ostream& operator<< (ostream& s, const Container<T>& container) {
    for (int i = 0; i < container.size(); i++) {
        s << container[i] << ' ';
    }
    return s;
}

int main() {
    Container<int> container;
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);
    container.push_back(6);
    container.pop_back();
    cout << container.size() << ' ' << (container.empty() ? "empty" : "filled") << ' ' << container << endl;
    container.clear();
    return 0;
}
