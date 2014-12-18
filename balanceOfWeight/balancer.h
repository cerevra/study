#ifndef BALANCER_H
#define BALANCER_H

#include <vector>
#include <string>

typedef std::vector<unsigned short> Weights;

class Balancer {
public:
    Balancer();
    void push_back(unsigned short x);

    std::string calc();

private:
    bool check  ();
    bool balance(unsigned int idx);

    Weights m_data;
    unsigned int m_allWeight;

    Weights m_buf;

};

#endif // BALANCER_H
