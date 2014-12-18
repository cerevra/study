
#include <algorithm>
#include "balancer.h"

Balancer::Balancer()
    : m_allWeight(0    )
    , m_balance  (false)
    , m_canGet100(false)
    , m_sum      (0    )
{
}

void Balancer::push_back(unsigned short x){
    m_data.push_back(x);
    m_allWeight += x;
}

std::string Balancer::calc()
{
    std::string result;

    balance(0);

    if (m_balance){
        for (unsigned int i = 0; i < m_solution.size(); ++i){
            result.append(std::to_string(m_solution[i]));
            result.append(" ");
        }
        result.append("- ");

        for (unsigned int i = 0; i < m_data.size(); ++i){
            if (find(m_solution.begin(), m_solution.end(), m_data[i]) == m_solution.end()){
                result.append(std::to_string(m_data[i]));
                result.append(" ");
            }
        }
    }
    else
        result = "No solution";

    result.append("\n");

    if (m_canGet100)
        result.append("yes");
    else
        result.append("no");

    return result;
}

bool Balancer::check(){
    unsigned int sum = 0;
    for(auto x: m_buf){
        sum += x;
    }

    return sum*2 == m_allWeight;
}

void Balancer::balance(unsigned int idx){
    for (unsigned int i = idx; i < m_data.size(); ++i){
        m_buf.push_back(m_data[i]);

        if (!m_balance && check()){
            m_balance  = true;
            m_solution = m_buf;
        }

        m_sum += m_data[i];
        if (m_sum == 100)
            m_canGet100 = true;

        balance(i+1);

        m_buf.pop_back();
        m_sum -= m_data[i];
    }
}
