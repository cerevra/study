#include "cli.h"

#include "array.h"

const QString CLI::m_illformedInput = "Wrong format of input data";

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
            printMsg(parseArray ()      );
            break;

        case 2:
            printMsg(parseString()      );
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

QString CLI::parseString() {
    return "";
}

QString CLI::parseArray() {
    return "";
}

void CLI::printMsg(const QString& msg) {
    m_qout << msg << endl;
}
