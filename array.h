#ifndef ARRAY_H
#define ARRAY_H

#include <QString>
#include <QVector>

class Array
{
public:
    ~Array();

    static Array fromString(const QString& str);
    static Array fromArray (const QString& arr);

    bool isValid() const;

    QString printString() const;
    QString printArray () const;

private:
    Array();

    bool m_isValid = false;
};

#endif // ARRAY_H
