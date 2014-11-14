#include <iostream>
#include <fstream>

#include "interpreter.h"

using namespace std;

int main()
{
    Interpreter interpreter;
    while (true){
        long long number;
        cout << "Enter number: ";
        cin >> number;

        ofstream file;
        file.open ("result.txt");
        file << number << " : " << interpreter.text(number) << endl;
        file.close();
    }

    return 0;
}
