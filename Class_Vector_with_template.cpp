#include <iostream>
#include <vector>
template <typename T>
class Vector {
public:
	Vector() :capacity_(2), vec(new T[capacity_]) {}
	Vector(size_t arr_size) :capacity_(arr_size), vec(new T[capacity_]) {}
	Vector(size_t arr_size, T elem) :capacity_(arr_size), vec(new T[capacity_]) {
		for (size_t i = 0; i < capacity_; ++i) {
			vec[i] = elem;
			++size_;
		}
	}
	std::istream& operator>>(std::istream& is) {
		is >> this->at();
	}
	Vector(const Vector<T>& other) :capacity_(other.capacity_), size_(other.size_), vec(new T[capacity_]) {
		for (size_t i = 0; i < size_; ++i) {
			vec[i] = other.vec[i];
		}
	}
	Vector(Vector<T>&& other) :capacity_(other.capacity_), size_(other.size_) {
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
	//1 2 3 4

	//1 1*1 1*2 1*2*3
	int left = 1;
	for (int i = 0; i < nums.size(); ++i) {
		result[i] = left;
		left *= nums[i];//
	}
	//1 1*1 1*2* 1*2*3
	int right = 1;
	for (int i = nums.size() - 1; i >= 0; --i) {
		result[i] *= right;
		right *= nums[i];
	}
	return result;
}

void luckynums(Vector<Vector<int>> vec) {

	//2 1 7
	Vector<int> min_index;
	Vector<int> max_index;
	Vector<int> res;
	std::cout << vec[0][2];
	//min = 2 min = 1 
	/*
	int min;
	int max;
	int k;//min index
	bool ismax = true;
	if (vec.empty()) {
		throw std::invalid_argument("The Vector is empty!!!");
	}
	for (int i = 0; i < vec.capacity(); ++i) {
		min = vec[i][0];
		k = 0;
		for (int j = 1; j < vec[i].size(); ++j) {
			if (vec[i][j] < min) {
				k = j;
				min = vec[i][j];
			}
			else {
				continue;
			}
		}
		min_index.push_back(k);
	}
	for (int j = 0; j < vec.capacity(); ++j) {
		max = vec[0][j];
		k = 0;
		for (int i = 1; i <= vec.capacity() - 1; ++i) {
			if (vec[i][j] > max) {
				max = vec[i][j];
				k = i;
			}
		}
		max_index.push_back(k);
	}
	for (int i = 0; i < min_index.size(); ++i) {
		if (min_index[i] == max_index[i]) {
			res.push_back(vec[min_index[i]][max_index[i]]);
		}
	}


		// min_index = 0 0 0   1 1 1
		// max_index = 2 2 2   2 1 2

		//1 4 7      8 2 5
		//8 9 10	 9 1 2
		//14 15 16   10 0 56




	return res;
	*/
}

int main()
{
	Vector<Vector<int>> a(3);
	a[0].push_back(8);   //1 4 7
	a[0].push_back(2);	// 8 9 10
	a[0].push_back(5);	//14 15 16
	a[1].push_back(9);	//
	a[1].push_back(1);
	a[1].push_back(2);
	a[2].push_back(10);
	a[2].push_back(0);
	a[2].push_back(56);
	std::cout << a[2][2] << " ";
	//   luckynums(a);
	Vector<Vector<int>> b;
	b = a;
	std::cout << b[2][2];



}


