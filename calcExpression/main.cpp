#include <iostream>
#include <stack>
#include <map>
#include <cstdlib>
#include <cctype>
#include <math.h>

using namespace std;

class ExprParser {
public:
    ExprParser()
        : m_expr(nullptr)
    {}

    double calcExpression(const string& expr){
        m_expr = &expr;

        if (expr.size() == 0) throw 0;

        m_function.push('(');

        char prev;
        for (unsigned int pos = 0; pos < expr.size(); ++pos){
            char c = expr.at(pos);

            if (c == ' ')
                continue;
            else if (c == ')'){
                closeBrackets();
            }
            else if (priorityFunc(c) >= -1){
                if (prev == '(' || pos == 0)
                    m_operand.push(0);

                while (canPop(c))
                    popFunc();

                m_function.push(c);
            }
            else if (isdigit(c)){
                m_operand.push(readDouble(pos));
            }
            else
                throw c;

            prev = c;
        }

        closeBrackets();

        int funSize = m_function.size();
        int oprSize = m_operand .size();
        if (funSize > 0 && oprSize > 1)
            throw funSize + oprSize;

        return m_operand.top();
    }

private:
    bool canPop(char func){
        if (!m_function.size())
            return false;

        int pr1 = priorityFunc(func            );
        int pr2 = priorityFunc(m_function.top());

        return pr1 >= 0 && pr2 >= 0 && pr1 >= pr2;
    }

    void popFunc(){
        double b = m_operand.top(); m_operand.pop();
        double a = m_operand.top(); m_operand.pop();

        double result = 0;

        switch (m_function.top()){
        case '-': result = a - b; break;
        case '+': result = a + b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
        case '^': result = pow(a, b); break;
        default : throw;
        }
        m_function.pop();
        m_operand.push(result);
    }

    void closeBrackets(){
        while (m_function.size() > 0 && m_function.top() != '(')
            popFunc();
        m_function.pop();
    }

    int priorityFunc(const char c){
        int result;

        switch (c){
        case '-':
        case '+': result =  3;   break;
        case '*':
        case '/': result =  2;   break;
        case '^': result =  1;   break;
        case '(': result = -1;   break;
        default : result = -100; break;
        }

        return result;
    }

    double readDouble(unsigned int& pos){
        double result = atof(m_expr->c_str() + pos);

        int i = 1;
        for (; pos + i < m_expr->size(); ++i){
            char c = m_expr->at(pos + i);
            if (!isdigit(c) && c != '.')
                break;
        }

        pos += i - 1;

        return result;
    }

    stack<double> m_operand;
    stack<char  > m_function;

    const string* m_expr;
};

int main()
{
    while (true){
        ExprParser parser;
        string     expr;

        cout << "Enter expression: ";
        cin >> expr;

        double result = 0;

        try {
            result = parser.calcExpression(expr);
        }
        catch (char c){
            cout << "Unsupported symbol: " << c << endl;
            continue;
        }
        catch (int i){
            if (i == 0)
                cout << "Empty expression" << endl;
            else
                cout << "Uncorrect expression" << endl;
            continue;
        }
        catch (...){
            cout << "Enexpected error" << endl;
            continue;
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}
