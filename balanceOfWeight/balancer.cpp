
#include <algorithm>
#include "balancer.h"

Balancer::Balancer()
    : m_allWeight(0)
{
}

void Balancer::push_back(unsigned short x){
    m_data.push_back(x);
    m_allWeight += x;
}

std::string Balancer::calc()
{
    std::string result;

    if (balance(0)){
        for (unsigned int i = 0; i < m_buf.size(); ++i){
            result.append(std::to_string(m_buf[i]));
            result.append(" ");
        }
        result.append("- ");

        for (unsigned int i = 0; i < m_data.size(); ++i){
            if (find(m_buf.begin(), m_buf.end(), m_data[i]) == m_buf.end()){
                result.append(std::to_string(m_data[i]));
                result.append(" ");
            }
        }
    }
    else
        result = "No solution";

    return result;
}

bool Balancer::check(){
    unsigned int sum = 0;
    for(auto x: m_buf){
        sum += x;
    }

    return sum*2 == m_allWeight;
}

bool Balancer::balance(unsigned int idx){
    for (unsigned int i = idx; i < m_data.size(); ++i){
        m_buf.push_back(m_data[i]);

        if (check() || balance(i+1))
            return true;

        m_buf.pop_back();
    }

    return false;
}
