
#include <stdint.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<uint16_t          > VecNum;
typedef map   <uint16_t, uint16_t> MapNum;

uint16_t getRandNumericDigit(){
    return rand()%9 + 1;
}

void fillConts(VecNum& vec, MapNum& map, uint16_t maxCount){
    vec.reserve(maxCount);

    cout << "Enter seed for random: ";
    uint16_t seed;
    cin >> seed;

    //srand (time(NULL));
    srand(seed);

    uint16_t count = rand()*1.0*maxCount/RAND_MAX;
    for (uint16_t i = 0; i < count; ++i){
        vec.push_back(getRandNumericDigit());
        map.emplace(i, getRandNumericDigit());
    }
	cout << "Containers are filled: " << count << endl;
}

void deleteSome(VecNum& vec, MapNum& map){
    uint16_t toDeleteNum = rand() % 16;

    uint16_t size = vec.size();
    auto randIdx = [&size](){
        return rand() % size;
    };

    for (uint16_t i = 0; i < toDeleteNum && vec.size(); ++i, --size) {
        vec.erase(vec.begin() + randIdx());

        auto it = map.find(randIdx());
        if (it == map.end  ())
            it =  map.begin();

        map.erase(it);
    }

    cout << "Some numberes are deleted: " << toDeleteNum << endl;
}

void sortMap(MapNum& map){
    //selective sorting
    for (auto i = begin(map); i != end (map); ++i){
        uint16_t& iVal = i->second;
        for (auto k = i; k != end(map); ++k){
            if (i == k)
                continue;

            uint16_t& kVal = k->second;
            if (iVal > kVal)
                std::swap(iVal, kVal);
        }
    }
}

void sync(VecNum& vec, MapNum& map){
    uint16_t iVec = 0;
    auto     iMap = map.begin();

    uint16_t prevEqual = 0;

    while(iVec < vec.size() && iMap != end(map)){
        uint16_t vecVal = vec[iVec];
        uint16_t mapVal = iMap->second;

        if (vecVal < mapVal){
            vec.erase(vec.begin() + iVec);
        }
        else if (vecVal > mapVal){
            uint16_t key = iMap->first;
            map.erase(iMap);
            do {
                iMap = map.find(++key);
            } while (iMap == map.end() && map.size());
        }
        else {
            prevEqual = vecVal;

			do{ ++iVec; } while (iVec < vec.size() && vec[iVec]    == prevEqual);
			do{ ++iMap; } while (iMap != end(map)  && iMap->second == prevEqual);
        }
    }

    if (iVec < vec.size())
        vec.erase(vec.begin() + iVec, vec.end());
    map.erase(iMap, map.end());

    cout << "Sync finished" << endl;
}

template <class T>
void printCont(const string& str, const T& cont, function<void()> print){
    cout << str.c_str() << " (" << cont.size() << "): ";
    print();
    cout << endl;
}

int main(int, char**)
{
    cout << "Enter max count of numbers: ";
    uint16_t maxCount;
    cin >> maxCount;

    VecNum vec;
    MapNum map;

    // 1)
    fillConts (vec, map, maxCount);
    // 2)
    deleteSome(vec, map);

    sort      (vec.begin(), vec.end());
    sortMap   (map);
    // 3)
    sync      (vec, map);

    printCont("Vector", vec, [&vec](){for (auto a : vec){cout << a        << " "; } });
    printCont("Map"   , map, [&map](){for (auto a : map){cout << a.second << " "; } });

    cout << "Finish!" <<endl;

	system("pause");
    return 0;
}
