#pragma once

#ifndef ARRAY_H
#define ARRAY_H

namespace nnm {

template<typename T>
class Array
{
    static_assert(std::is_floating_point<T>::value, "Incorrect data type.");

public:
    Array() : m_numElements(0), m_pData(nullptr)
    {

    }

    Array(int numElements) : m_numElements(numElements)
    {
        if (numElements > 0)
            m_pData = reinterpret_cast<T*>(std::malloc(getSizeInBytes()));
        else
            m_pData = nullptr;
    }

    Array(const Array& other) : m_numElements(other.m_numElements)
    {
        if (other.m_pData != nullptr) {
            size_t sizeInBytes = getSizeInBytes();
            m_pData = reinterpret_cast<T*>(std::malloc(sizeInBytes));
            std::memcpy(m_pData, other.m_pData, sizeInBytes);
        } else {
            m_pData = nullptr;
        }
    }


    virtual ~Array()
    {
        if (m_pData != nullptr) {
            std::free(m_pData);
            m_pData = nullptr;
        }
    }

    const T* constData() const
    {
        return m_pData;
    }

    T* data() const
    {
        return m_pData;
    }

    bool isNull() const
    {
        return m_pData == nullptr;
    }

    void fillWithRandom(T min, T max)
    {
        std::random_device rnd;
        std::mt19937 gen(rnd());
        std::uniform_real_distribution<T> dis(min, max);
        for (int i = 0; i < m_numElements; ++i)
            m_pData[i] = dis(gen);
    }

    size_t getSizeInBytes() const
    {
        return m_numElements * sizeof(T);
    }

protected:
    int m_numElements;
    T* m_pData;
};

}

#endif // ARRAY_H
