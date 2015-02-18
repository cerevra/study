#ifndef ARRAY_H
#define ARRAY_H

#include <QString>
#include <QVector>

class Array
{
public:
    Array() = delete;
    ~Array();

    static Array* fromArray (const QString& arr);
    static Array* fromString(const QString& str);

    QString       printArray () const;
    QString       printString() const;

private:
    typedef QVector<int> VectorOfInt;

    Array(const VectorOfInt& vec);

    static bool addNumber(VectorOfInt& vec, const QStringRef& str);
    static bool addRange (VectorOfInt& vec, const QStringRef& str);

    VectorOfInt m_vec; // plain array is inside of it
};

#endif // ARRAY_H
