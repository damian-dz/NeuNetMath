#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include "Array.h"

namespace nnm {

template<typename T>
class Vector : public Array<T>
{
    static_assert(std::is_floating_point<T>::value, "Incorrect data type.");

    using base = Array<T>;

public:
    Vector()
    {

    }

    Vector(int numElements) : base(numElements)
    {

    }

    Vector(std::initializer_list<T> list) : base(list.size())
    {
        if (base::m_numElements > 0) {
            int i = 0;
            for (const T& val : list) {
                base::m_pData[i] = val;
                ++i;
            }
        }
    }

    std::string toString(int padding = 12) const
    {
        std::stringstream ss;
        for (int i = 0; i < base::m_numElements; ++i) {
            ss << std::setw(padding) << base::m_pData[i];
        }
        ss << "\n";
        return ss.str();
    }

    void operator=(const Vector& other)
    {
        if (other.m_numElements != base::m_numElements) {
            base::m_numElements = other.m_numElements;
            if (!base::isNull() && !other.isNull()) {
                T* tempPtr = reinterpret_cast<T*>(std::realloc(base::m_pData, base::getSizeInBytes()));
                if (tempPtr != nullptr)
                    base::m_pData = tempPtr;
            } else if (base::isNull() && !other.isNull()) {
                base::m_pData = reinterpret_cast<T*>(std::malloc(base::getSizeInBytes()));
            } else {
                base::m_pData = nullptr;
            }
            if (!base::isNull() && base::m_numElements > 0) {
                std::memcpy(base::m_pData, other.m_pData, base::getSizeInBytes());
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec)
    {
        os << vec.toString();
        return os;
    }
};

}

#endif // VECTOR_H
