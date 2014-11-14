#include <iostream>

using namespace std;

template<class T>
class FastStack {
    struct Node {
        Node(T& val)
            : m_prev (nullptr)
            , m_value(val    )
        {}

        Node* m_prev;
        T     m_value;
        T*    m_max;
        T*    m_min;
    };

public:
    FastStack()
        : m_top (nullptr)
        , m_size(0      )
        , m_max (nullptr)
        , m_min (nullptr)
    {}

    unsigned int size() const;
    void         push(T& val);
    void         pop ();
    T*           top ();
    T            max () const;
    T            min () const;

private:
    Node*        m_top;
    unsigned int m_size;
    T*           m_max;
    T*           m_min;
};

template<class T>
unsigned int FastStack<T>::size() const
{
    return m_size;
}

template<class T>
void FastStack<T>::push(T& val)
{
    Node* node = new Node(val);
    if (m_top){
        node->m_prev = m_top;
        node->m_max  = (*m_top->m_max > node->m_value ? m_top->m_max : &node->m_value);
        node->m_min  = (*m_top->m_min < node->m_value ? m_top->m_min : &node->m_value);
        m_top        = node;
    }
    else
    {
        m_top = node;
        m_top->m_max = &m_top->m_value;
        m_top->m_min = &m_top->m_value;
    }

    ++m_size;
}

template<class T>
void FastStack<T>::pop()
{
    if (!m_top)
        return;

    --m_size;

    Node* toDelete = m_top;
    m_top          = m_top->m_prev;

    if (m_top){
        m_top->m_max  = (*m_top->m_max > *toDelete->m_value ? m_top->m_max : toDelete->m_value);
        m_top->m_min  = (*m_top->m_min < *toDelete->m_value ? m_top->m_min : toDelete->m_value);
    }

    delete toDelete;
}

template<class T>
T* FastStack<T>::top()
{
    return m_top;
}

template<class T>
T FastStack<T>::max() const
{
    if (m_top)
        return *m_top->m_max;
    else
        return T();
}

template<class T>
T FastStack<T>::min() const
{
    if (m_top)
        return *m_top->m_min;
    else
        return T();
}

int main()
{
    FastStack<int> stack;

    cout << "Size: " << stack.size() << endl;
    cout << "Max: "  << stack.max () << endl;
    cout << "Min: "  << stack.min () << endl;

    int vals[] = {1, 100, 11, -1, 1115};

    for (int i = 0; i < sizeof(vals)/sizeof(int); ++i)
    {
        stack.push(*(vals + i));
        cout << "Size: " << stack.size() << endl;
        cout << "Max: "  << stack.max () << endl;
        cout << "Min: "  << stack.min () << endl;
    }

    return 0;
}
