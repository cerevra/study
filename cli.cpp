#include "cli.h"

#include <QScopedPointer>

CLI::CLI()
    : m_qin (stdin )
    , m_qout(stdout)
{
}

CLI::~CLI() {
}

void CLI::run() {
    bool   worktime = true;

    while (worktime) {
        m_qout << "----------------" << endl
               << "1 - Enter array"  << endl
               << "2 - Enter string" << endl
               << "3 - Quit"         << endl
               << "Enter command: "  << flush;

        switch (m_qin.readLine().toInt()) {
        case 1:
            processArray();
            break;

        case 2:
            processString();
            break;

        case 3:
            worktime = false;
            printMsg("See you later..." );
            break;

        default:
            printMsg("Undefined command");
        }

        m_qout << endl << flush;
    }
}

void CLI::processArray()
{
    printMsg("Enter array like this: [1,3,4,5,7,9]").flush();

    QScopedPointer<Array> array (Array::fromArray (m_qin.readLine()));

    print(array.data());
}

void CLI::processString()
{
    printMsg("Enter string like this: 1,3-5,7,9"   ).flush();

    QScopedPointer<Array> array (Array::fromString(m_qin.readLine()));

    print(array.data());
}

QTextStream& CLI::printMsg(const QString& msg) {
    return m_qout << msg << endl;
}

void CLI::print(const Array* arr)
{
    if (arr)
        m_qout << "Array  format: " << arr->printArray () << endl
               << "String format: " << arr->printString() << endl;
    else
        printMsg("Wrong format of input data");
}
