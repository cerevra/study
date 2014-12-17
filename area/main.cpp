#include <iostream>

#include "areamanager.h"

using namespace std;

int main()
{
    AreaManager aman;

    while (true) {
        cout << "Enter coords of rect: ";
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        aman.addRect(new Rect(Point(x1, y1), Point(x2, y2)));

        cout << "Result: " << aman.result() << endl;
    }

    return 0;
}

