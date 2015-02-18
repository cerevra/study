#ifndef CLI_H
#define CLI_H

#include <QTextStream>

#include "array.h"

class CLI
{
public:
    CLI();
    ~CLI();

    void run();

private:
    void         processArray ();
    void         processString();

    QTextStream& printMsg(const QString& msg);
    void         print   (const Array*   arr);

    static const QString m_illformedInput;

    QTextStream m_qin ;
    QTextStream m_qout;
};

#endif // CLI_H
