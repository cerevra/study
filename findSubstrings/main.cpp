#include <iostream>
#include <vector>

using namespace std;

typedef vector<unsigned int> VecInt;

VecInt findKMP(VecInt& prefix_func, const string& str, unsigned int subLen){
    int len = str.size();

    prefix_func.clear();
    prefix_func.resize(len);
    prefix_func[0] = 0;

    for (int i = 1; i < len; ++i){
        int maybeIdx = i - 1;
        int maybe    = prefix_func[maybeIdx];

        while (maybe && str[i] != str[maybe]){
            maybeIdx = prefix_func[maybeIdx] - 1;
            maybe    = prefix_func[maybeIdx];
        }

        if (maybe)
            prefix_func[i] = maybe + 1;
        else {
            prefix_func[i] = str[i] == str[maybe] ? 1 : 0;
        }
    }

    VecInt result;
    for (int i = subLen; i < len; ++i){
        if (prefix_func[i] == subLen)
            result.push_back(i - 2*subLen); // 2: 1) искусственно увеличенная строка (+$) 2) число указывает на конец (поэтому не надо вычитать 1 ($))
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

        unsigned int subLen = sub.size();

        if (subLen > str.size()){
            cout << "Sub if bigger then string" << endl;
            return 0;
        }

        string prepairedString;
        prepairedString.append   (sub);
        prepairedString.push_back('$');
        prepairedString.append   (str);

        VecInt prefixes;

        const VecInt& result = findKMP(prefixes, prepairedString, subLen);
        cout << "Results:" << endl;
        for (auto i = begin(result); i < end(result); ++i)
            cout << *i << endl;
        cout << "-------" << endl << endl;
    }

    return 0;
}
