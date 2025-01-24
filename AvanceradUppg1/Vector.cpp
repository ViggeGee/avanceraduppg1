#include "Vector.h"


template <typename T>
Vector<T>::Vector() noexcept : size_(0), capacity_(0), data(nullptr) 
{

}

template <typename T>
Vector<T>::Vector(const char* other) {
    size_ = 0;
    while (other[size_] != '\0') {
        ++size_;
    }

    capacity_ = size_;

    data = new T[capacity_];

    for (size_t i = 0; i < size_; i++)
    {
        data[i] = other[i];
    }

    
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data = new T[capacity_]; 

    
    for (size_t i = 0; i < size_; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
void Vector<T>::push_back(const T& c)
{
    if (size_ == capacity_) {
        capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2; 
        T* newData = new T[capacity_];

        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data[i]; 
        }

        delete[] data; 
        data = newData;
    }

    data[size_++] = c; 
}

template<typename T>
void Vector<T>::pop_back() noexcept
{
    if (size_ > 0) {
        --size_;
    }
}

template<typename T>
const T& Vector<T>::at(size_t i) const
{

    return data[i];
}

//Move constructor
template<typename T>
Vector<T>::Vector(Vector&& other) noexcept : data(other.data), size_(other.size_), capacity_(other.capacity_) 
{

        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
}

template <typename T>
Vector<T>::~Vector() noexcept {
    delete[] data; 
}



template <typename T>
size_t Vector<T>::size() const noexcept {
    return size_;
}

template <typename T>
size_t Vector<T>::capacity() const noexcept {
    return capacity_;
}

template <typename T>
bool Vector<T>::Invariant() const {
    return size_ <= capacity_;
}

template class Vector<char>;  
template class Vector<int>;   
template class Vector<double>; 
