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
    void balance(unsigned int idx);

    Weights m_buf;
    Weights m_data;
    Weights m_solution;
    unsigned int m_allWeight;

    bool m_balance;
    bool m_canGet100;
    unsigned int m_sum;
};

#endif // BALANCER_H
