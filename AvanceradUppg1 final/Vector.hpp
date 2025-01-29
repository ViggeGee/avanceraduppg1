#pragma once
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector() noexcept : size_(0), capacity_(0), data(nullptr) {}

    ~Vector() noexcept {
        delete[] data;
    }

    Vector(const char* other) {
        size_ = 0;
        while (other[size_] != '\0') {
            ++size_;
        }

        capacity_ = size_;
        data = new T[capacity_];

        for (size_t i = 0; i < size_; i++) {
            data[i] = other[i];
        }
    }

    Vector(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data = new T[capacity_];

        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    Vector(Vector&& other) noexcept : data(other.data), size_(other.size_), capacity_(other.capacity_) {
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    friend bool operator==(const Vector<T>& lhs, const Vector<T>& other) {
        if (lhs.size() != other.size()) {
            return false;
        }
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs.data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    Vector& operator=(const Vector& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;

        size_ = other.size_;
        capacity_ = other.capacity_;
        data = new T[capacity_];

        for (size_t i = 0; i < size_; ++i)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    //Move assigner
    Vector& operator=(Vector&& other) noexcept
    {

        data = other.data;
        size_ = other.size_;
        capacity_ = other.capacity_;


        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;

        return *this;
    }

    friend bool operator!=(const Vector<T>& lhs, const Vector<T>& other) {
        if (lhs.size() != other.size()) {
            return true;
        }
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs.data[i] != other.data[i]) {
                return true;
            }
        }
        return false;
    }

    friend bool operator>(const Vector<T>& lhs, const Vector<T>& other) {
        if (lhs.size() > other.size()) {
            return true;
        }
        if (lhs.size() < other.size()) {
            return false;
        }

        for (size_t i = 0; i > lhs.size(); ++i) {
            if (lhs.data[i] > other.data[i]) {
                return true;
            }
            if (lhs.data[i] < other.data[i]) {
                return false;
            }
        }
        return false;
    }
    friend bool operator<(const Vector<T>& lhs, const Vector<T>& other) {
        if (lhs.size() < other.size()) {
            return true;
        }
        if (lhs.size() > other.size()) {
            return false;
        }

        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs.data[i] < other.data[i]) {
                return true;
            }
            if (lhs.data[i] > other.data[i]) {
                return false;
            }
        }
        return false;
    }
    friend bool operator<=(const Vector<T>& lhs, const Vector<T>& other) {
        if (lhs.size() < other.size()) {
            return true;
        }
        if (lhs.size() > other.size()) {
            return false;
        }

        for (size_t i = 0; i > lhs.size(); ++i) {
            if (lhs.data[i] < other.data[i]) {
                return true;
            }
            if (lhs.data[i] > other.data[i]) {
                return false;
            }
        }

        return true;
    }
    friend bool operator>=(const Vector<T>& lhs, const Vector<T>& other) {
        if (lhs.size() > other.size()) {
            return true;
        }
        if (lhs.size() < other.size()) {
            return false;
        }

        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs.data[i] > other.data[i]) {
                return true;
            }
            if (lhs.data[i] < other.data[i]) {
                return false;
            }
        }

        return true;
    }

    T& operator[](size_t i) {
        return data[i];
    }
    const T& operator[](size_t i) const {
        return data[i];
    }

    void push_back(const T& c) {
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

    void pop_back() noexcept {
        if (size_ > 0) {
            --size_;
        }
    }

    const T& at(size_t i) const {
        if (i >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

   

    

    size_t size() const noexcept {
        return size_;
    }

    size_t capacity() const noexcept {
        return capacity_;
    }

    void reserve(size_t n) {
        if (n <= capacity_) return;
        T* new_data = new T[n];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = n;
    }

    void shrink_to_fit() {
        if (capacity_ > size_) {
            T* new_data = new T[size_];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity_ = size_;
        }
    }

    void resize(size_t n)
    {
        if (n > size_)
        {
            if (capacity_ < n)
            {
                capacity_ = n * 2;
            }
            for (size_t i = size_; i < n; ++i)
            {
                size_++;
                data[i] = T();
            }
        }
        else if (n < size_)
        {
            for (size_t i = size_; i > n; --i)
            {
                size_--;

            }
        }
    }

    bool Invariant() const {
        return size_ <= capacity_;
    }

    const T* Data() const noexcept {
        return data;
    }

    class iterator {
    private:
        T* ptr_;
    public:



        iterator(T* ptr) : ptr_(ptr) {}
        iterator() : ptr_(nullptr) {}

        T* get_ptr() const { return ptr_; }
        T& operator*() { return *ptr_; }
        T* operator->() { return ptr_; }

        iterator& operator++() {
            ++ptr_;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++ptr_;
            return tmp;
        }
        iterator& operator--() {
            --ptr_;
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            --ptr_;
            return tmp;
        }

        iterator& operator+=(ptrdiff_t n) {
            
            ptr_ += n;
            return *this;
        }

        iterator operator+(ptrdiff_t i) const {
            iterator tmp = *this;
            tmp.ptr_ = tmp.ptr_ + i;
            return tmp;
        }

        iterator operator-(ptrdiff_t i) const {
            iterator tmp = *this;
            tmp.ptr_ = tmp.ptr_ - i;
            return tmp;
        }
        ptrdiff_t operator-(const iterator& other) const {
            return ptr_ - other.ptr_; 
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return lhs.ptr_ == rhs.ptr_;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return lhs.ptr_ != rhs.ptr_;
        }
    };

    class reverse_iterator {
        T* ptr_;
    public:
      

        reverse_iterator(const reverse_iterator& other) { ptr_ = other.ptr_; }
        reverse_iterator(T* ptr) : ptr_(ptr) {}
        reverse_iterator() : ptr_(nullptr) {}
        reverse_iterator(const iterator& it) : ptr_(it.get_ptr() - 1) {}

        reverse_iterator& operator=(const reverse_iterator& other) {
            if (this != &other) {
                ptr_ = other.ptr_;
            }
            return *this;
        }
    };


  

    iterator begin() noexcept {
        return iterator(data);
    }

    iterator end() noexcept {
        return iterator(data + size_);
    }

    iterator rbegin() noexcept {
        return iterator(data + size_ - 1);
    }

    iterator rend() noexcept {
        return iterator(data - 1);
    }

    T* data;
    size_t size_;
    size_t capacity_;
private:
};

// Explicit template instantiations
template class Vector<char>;
template class Vector<int>;
template class Vector<double>;
