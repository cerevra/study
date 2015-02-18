#ifndef CLI_H
#define CLI_H

#include <QTextStream>

class CLI
{
public:
    CLI();
    ~CLI();

    void run();

private:
    QString parseArray ();
    QString parseString();
    void    printMsg   (const QString& msg);

    static const QString m_illformedInput;

    QTextStream m_qin ;
    QTextStream m_qout;
};

#endif // CLI_H
