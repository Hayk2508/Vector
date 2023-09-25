#include <iostream>

template <typename T>
class Vector {
public:
	Vector() :capacity_(2), vec(new T[capacity_]) {}
	Vector(size_t arr_size) :capacity_(arr_size),vec(new T[capacity_]) {}
	Vector(size_t arr_size, T elem) :capacity_(arr_size), vec(new T[capacity_]) {
		for (size_t i = 0; i < capacity_; ++i) {
			vec[i] = elem;
			++size_;
			}
	}

	Vector(const Vector<T>& other) :capacity_(other.capacity_), size_(other.size_),vec(new T[capacity_]) {
		for (size_t i = 0; i < size_; ++i) {
			vec[i] = other.vec[i];
		}
	}
	Vector(Vector<T>&& other):capacity_(other.capacity_),size_(other.size_) {
		if (other.vec != nullptr) {
			vec = other.vec;
		}
		other.vec = nullptr;
	}

	~Vector() {
		delete[]vec;
	}


	Vector<T>& operator=(const Vector<T>& other) {
		if (this == &other) {
			return *this;
		}
		delete[]vec;
		capacity_ = other.capacity_;
		size_ = other.size_;
		vec = new T[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			vec[i] = other.vec[i];
		}
		return *this;
	}

	Vector<T>& operator=(Vector<T>&& other) {
		if (this == &other) {
			return *this;
		}
		delete[]vec;
		capacity_ = other.capacity_;
		size_ = other.size_;
		vec = other.vec;
		other.vec = nullptr;
		return *this;
	}

	size_t size() const {
		return size_;
	}
	size_t capacity() const {
		return capacity_;
	}

	bool empty() const {
		return capacity_ == 0;
	}

	const T& operator[](size_t index) const {
		return vec[index];
	}
	T& operator[](size_t index) {
		return vec[index];
	}

	const T& at(size_t index) const {
		if (index < 0 || index >= capacity_) {
			throw std::out_of_range("Out of Range!");
		}
		else {
			return vec[index];
		}
		
	}
	T& at(size_t index) {
		if (index < 0 || index >= capacity_) {
			throw std::out_of_range("Out of Range!");
		}
		else {
			return vec[index];
		}
	}

	void push_back(const T& x) {
		if (size_ == capacity_) {
			capacity_ *= 2;
			T* tmp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				tmp[i] = std::move(vec[i]);
			}			
			delete[]vec;
			vec = tmp;
			tmp = nullptr;
		}
		vec[size_] = std::move(x);
		++size_;
	}
	void push_back(T&& x) {
		if (size_ == capacity_) {
			capacity_ *= 2;
			T* tmp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				tmp[i] = std::move(vec[i]);
			}
			delete[]vec;
			vec = tmp;
			tmp = nullptr;
		}
		vec[size_] = x;
		++size_;
	}
	

	void pop_back() {
		--size_;
	}

	void clear() {		
		size_ = 0;
	}
private:
	size_t capacity_;
	size_t size_ = 0;
	T* vec;
};


int main()
{
		
	
}


