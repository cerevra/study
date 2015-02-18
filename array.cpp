#include "array.h"

#include "QStringList"

Array::Array(const VectorOfInt& vec)
    : m_vec(vec)
{
    qSort(m_vec.begin(), m_vec.end());

    for (int i = 1; i < m_vec.size(); ++i)
        if (m_vec[i-1] == m_vec[i])
            m_vec.remove(i);
}

Array::~Array() {
}

Array* Array::fromArray(const QString& arr) {
    if (!(arr.startsWith('[') && arr.endsWith(']')))
        return nullptr;

    VectorOfInt vec;

    QVector<QStringRef> nums = arr.midRef(1, arr.size() - 2)
                                  .split (','              );

    vec.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        if (!addNumber(vec, nums[i]))
            return nullptr;
    }

    return new Array(vec);
}

Array* Array::fromString(const QString& str) {
    QVector<QStringRef> nums = str.leftRef(str.size()).split(',');
    VectorOfInt vec;

    vec.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        switch (nums[i].count('-')) {
        case 0:
            if (!addNumber(vec, nums[i]))
                return nullptr;
            break;

        case 1:
            if (!addRange(vec, nums[i]))
                return nullptr;
            break;

        default:
            return nullptr;
        }
    }

    return new Array(vec);
}

QString Array::printArray() const {
    QString str;

    str.append('[');
    str.append(QString::number(m_vec[0]));

    for(int i = 1; i < m_vec.size(); ++i)
        str.append(QString(",%1").arg(m_vec[i]));

    str.append(']');

    return str;
}

QString Array::printString() const {
    QString str = QString::number(m_vec[0]);

    auto addDelimiter = [&str](char c) {
        if (!str.endsWith('-'))
             str.append  (c  );
    };

    for (int i = 1; i < m_vec.size() - 1; ++i) {
        if(m_vec[i] == m_vec[i-1] + 1 &&
           m_vec[i] == m_vec[i+1] - 1)
        {
            addDelimiter('-');
        }
        else
        {
            addDelimiter(',');
            str.append(QString::number(m_vec[i]));
        }
    }

    if (m_vec.size() > 1){
        addDelimiter(',');
        str.append(QString::number(m_vec.last()));
    }

    return str;
}

bool Array::addNumber(VectorOfInt& vec, const QStringRef& str)
{
    int num = str.toInt();

    if (num < 1)
        return false;

    vec.append(num);
    return true;
}

bool Array::addRange(VectorOfInt& vec, const QStringRef& str)
{
    QVector<QStringRef> nums = str.split('-');

    int from = nums[0].toInt();
    int to   = nums[1].toInt();

    if (from < 1 || to < 1)
        return false;

    for (int i = from; i <= to; ++i)
        vec.append(i);

    return true;
}
