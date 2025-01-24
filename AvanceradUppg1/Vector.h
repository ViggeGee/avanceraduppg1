#pragma once

template <typename T>
class Vector {
public:
	Vector() noexcept;
	~Vector() noexcept;
	Vector(const char* other);
	Vector(const Vector& other);
	void push_back(const T& c);
	void pop_back() noexcept;
	const T& at(size_t i) const;
	Vector(Vector&& other) noexcept;


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
		capacity_ =other.capacity_;


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


	void reserve(size_t n);
	void shrink_to_fit();
	void resize(size_t n);

		
	

	size_t size() const noexcept;
	size_t capacity() const noexcept;
	bool Invariant() const;

	//Litet d i testkod? fel??
	const T* Data() const noexcept;

	T* data;
	size_t size_;
	size_t capacity_;
private:
};
