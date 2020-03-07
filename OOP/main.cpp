#include <iostream>

using namespace std;

template < typename T > class Container {
public:
    void push_back( T pushed ) {
        m_size++;
        if ( m_size > m_capacity ) {
            m_capacity *= 2;
            T * newHead = new T[ m_capacity ];
            T * newCurrent = newHead;
            for ( size_t i = 0; i < m_size; i++ ) {
                *newCurrent = m_data[ i ];
                newCurrent++;
            }
            delete[] m_data;
            m_data = newHead;
        }
        m_data[ m_size - 1 ] = pushed;
    }

    void pop_back() {
        m_size--;
    }

    T operator [] ( size_t index ) const {
        return m_data[index];
    }

    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return !m_size;
    }

    void clear() {
        m_size = 0;
    }

    Container(): m_size( 0 ), m_capacity( 4 ) {
        m_data = new T[ 4 ];
    }
    
    ~Container() {
        delete[] m_data;
    }
private:
    size_t m_size;
    size_t m_capacity;
    T * m_data;
};

template < typename T > ostream & operator << ( ostream & s, const Container< T > & container ) {
    for ( size_t i = 0; i < container.size(); i++ ) {
        s << container[ i ] << ' ';
    }
    return s;
}

void testContainer() {
    
    Container<int> container;
    container.push_back( 2 );
    container.push_back( 3 );
    container.push_back( 4 );
    cout << container << "- " << container.size() << " is the size" << endl;
    container.push_back( 5 );
    container.push_back( 6 );
    cout << container << "- " << container.size() << " is the size" << endl;
    container.pop_back();
    cout << container << "- " << container.size() << " is the size" << endl;
    cout << ( container.empty() ? "empty" : "filled" ) << endl;
    container.clear();
    cout << container << "- " << container.size() << " is the size" << endl;
    container.push_back( 7 );
    container.push_back( 8 );
    container.push_back( 9 );
    cout << container << "- " << container.size() << " is the size" << endl;
}

int main() {
    testContainer();
    return 0;
}
