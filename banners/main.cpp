#include <iostream>
#include <set>

using namespace std;

typedef std::set<int> Result;

double u01(){
    static unsigned int seed = 6789;

    seed *= 69069;
    ++seed;

    return seed/4294967296.0;
}

Result toShow(int size, int countToShow, int bans[])
{
    Result res;

    long long total = 0;
    for (int i = 0; i < size; ++i)
        total += bans[i];

    for (int i = 0; i < countToShow; ++i){
        long long rand = u01()*total;

        long long sum = 0;
        for (int k = 0; k < size; ++k){
            if (res.find(bans[k]) != res.end())
                continue;

            sum += bans[k];
            if (rand <= sum){
                res.insert(k);
                total -= bans[k];
                break;
            }
        }
    }

    return res;
}

int main()
{
    int bans[] = {15, 7, 18, 19, 100, 180, 155, 78};

    const Result& res = toShow(sizeof(bans)/sizeof(int), 2, bans);

    for(Result::const_iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << ' ';
    }

    return 0;
}
