#include <iostream>
#include <vector>
template <typename T>
class Vector {
public:
	Vector() :capacity_(2), vec(new T[capacity_]) {}
	Vector(size_t arr_size) :capacity_(arr_size),size_(arr_size) vec(new T[capacity_]) {}
	Vector(size_t arr_size, T elem) :capacity_(arr_size), vec(new T[capacity_]) {
		for (size_t i = 0; i < capacity_; ++i) {
			vec[i] = elem;
			++size_;
		}
	}

	Vector(const Vector<T>& other) :capacity_(other.capacity_), size_(other.size_), vec(new T[capacity_]) {
		for (size_t i = 0; i < size_; ++i) {
			vec[i] = other.vec[i];
		}
	}

	Vector(Vector<T>&& other) :capacity_(other.capacity_), size_(other.size_), vec(nullptr) {
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
				tmp[i] = vec[i];
			}
			delete[] vec;
			vec = tmp;
		}
		vec[size_] = std::move(x);
		++size_;
	}

	void push_back(T&& x) {
		if (size_ == capacity_) {
			capacity_ *= 2;
			T* tmp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				tmp[i] = vec[i];
			}
			delete[] vec;
			vec = tmp;
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



Vector<int> mul(const Vector<int>& nums) {
	Vector<int> result(nums.size(), 1);
	int left = 1;
	for (size_t i = 0; i < nums.size(); ++i) {
		result[i] = left;
		left *= nums[i];
	}
	int right = 1;
	for (int i = nums.size() - 1; i >= 0; --i) {
		result[i] *= right;
		right *= nums[i];
	}
	return result;
}

Vector<int> luckynums(const  Vector<Vector<int>>& vec) {
	Vector<int> min_row;
	Vector<int> max_column;
	Vector<int> res;
	int min;
	int max;

	if (vec.empty()) {
		throw std::invalid_argument("The Vector is empty!!!");
	}

	for (size_t i = 0; i < vec.capacity(); ++i) {
		min = vec[i][0];
		for (size_t j = 1; j < vec[i].size(); ++j) {
			if (vec[i][j] < min) {
				min = vec[i][j];
			}
		}
		min_row.push_back(min);
	}

	for (size_t j = 0; j < vec.capacity(); ++j) {
		max = vec[0][j];
		for (size_t i = 1; i <= vec.capacity() - 1; ++i) {
			if (vec[i][j] > max) {
				max = vec[i][j];
			}
		}
		max_column.push_back(max);
	}

	for (size_t i = 0; i < min_row.size(); ++i) {
		for (size_t j = 0; j < min_row.size(); ++j) {
			if (min_row[i] == max_column[j]) {
				res.push_back(min_row[i]);
			}
		}
	}
	return res;
}

int main()
{
	Vector<Vector<int>> a(3);
	Vector<int> v(3);
	Vector<int> c(3);
	Vector<int> d(3);
	v.push_back(8);
	v.push_back(2);
	v.push_back(5);
	c.push_back(9);
	c.push_back(1);
	c.push_back(2);
	d.push_back(10);
	d.push_back(0);
	d.push_back(56);
	a.push_back(v);
	a.push_back(c);
	a.push_back(d);
	std::cout << luckynums(a)[0];
}


