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
    inline void         processArray ();
    inline void         processString();

    inline QTextStream& printMsg(const QString& msg);
    inline void         print   (const Array*   arr);

    QTextStream m_qin ;
    QTextStream m_qout;
};

#endif // CLI_H
