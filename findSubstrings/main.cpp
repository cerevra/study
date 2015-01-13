#include <iostream>
#include <vector>

using namespace std;

typedef vector<unsigned int> VecInt;

VecInt findKMP(VecInt& prefix_func, const string& str, const string& sub){
    string prepairedString;
    prepairedString.append   (sub);
    prepairedString.push_back(',');
    prepairedString.append   (str);

    int len = prepairedString.size();

    prefix_func.clear();
    prefix_func.resize(len);
    prefix_func[0] = 0;

    for (int idx = 1; idx < len; ++idx){
        int maybe = prefix_func[idx - 1];

        while (maybe && prepairedString[idx] != prepairedString[maybe])
            maybe = prefix_func[maybe - 1];

        if (maybe)
            prefix_func[idx] = maybe + 1;
        else
            prefix_func[idx] = prepairedString[idx] == prepairedString[maybe] ? 1 : 0;
    }

    VecInt result;
    for (int i = sub.size(); i < len; ++i){
        if (prefix_func[i] == sub.size())
            result.push_back(i - 2*sub.size()); // 2: 1) искусственно увеличенная строка (+$) 2) число указывает на конец (поэтому не надо вычитать 1 ($))
    }

    return result;
}

int main()
{
    while (true){
        string str, sub;
        cout << "Enter String" << endl;
        cin  >> str;

        cout << "Enter Substring" << endl;
        cin  >> sub;

        if (sub.size() > str.size()){
            cout << "Sub if bigger then string" << endl;
            continue;
        }

        VecInt prefixes;

        const VecInt& result = findKMP(prefixes, str, sub);
        cout << "Results:" << endl;
        for (auto i = begin(result); i < end(result); ++i)
            cout << *i << endl;
        cout << "-------" << endl << endl;
    }

    return 0;
}
