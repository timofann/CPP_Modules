#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
	T               *content_;
	unsigned int    size_;
public:
	Array() : content_(new T[0]), size_(0) {};
	Array(unsigned int n) : content_(new T[n]), size_(n) {};
	Array(const Array<T> &copy) : size_(copy.size_) {
		content_ = new T[size_];
		std::memcpy(content_, copy.content_, sizeof(T)*size_);
	};
	~Array() { delete[] content_; };
	Array   &operator=(const Array<T> &other) {
		if (this == &other)
			return *this;
		delete[] content_;
		size_ = other.size_;
		content_ = new T[size_];
		std::memcpy(content_, other.content_, sizeof(T)*size_);
		return *this;
	};
	T       &operator[](unsigned int i) {
		if (i >= size_)
			throw std::exception();
		return content_[i];
	}
	const T &operator[](unsigned int i) const {
		if (i >= size_)
			throw std::exception();
		return content_[i];
	}
	unsigned int    size() const { return size_; };
};

template <typename T>
std::ostream&   operator<<(std::ostream &os, const Array<T> &output) {
	unsigned int size = output.size();
	for (unsigned int i = 0; i < size; ++i) {
		os << output[i];
		if (i < size - 1)
			os << " ";
	}
	return os;
};

#endif
