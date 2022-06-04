#pragma once
#include <iterator>
template<class T> struct it;

template<class T, typename F>
struct bufer {
public:
	F size;
	T* array;
	F first = 0;
	F tail = 0;
	F counter = 0;
	F iter_index = first;

	bufer(F buf_size);
	~bufer() = default;
	void push_back(T elem);
	void push_front(T elem);
	void add_iterator(T elementh);
	void pop_iterator();
	void print_buffer();
	void capacity(unsigned new_size);
	T pop_front();
	T access_front();
	T pop_back();
	T access_back();
	T& operator[](F index);
	it<T> front();
	it<T> back();
};

template<class T>
struct it : public std::iterator<std::random_access_iterator_tag, T> {
public:
	T* index_position;
	T* array;
	T* start;
	T* end;
	T size;
	it(T* pos, T* arr, T arr_size, T* begin, T* finish) {
		index_position = pos;
		array = arr;
		start = begin;
		end = finish;
		size = arr_size;
	};
	explicit it(T* pos);
	~it() = default;
	T& operator*() {
		return *index_position;
	};
	T* operator->() {
		return index_position;
	}
	it& operator++() {
		++index_position;
		return *this;
	}
	it operator++(int) {
		it tmp(*this);
		operator++();
		return tmp;
	}
	it& operator--() {
		index_position--;
		return *this;
	}
	it operator--(int) {
		it tmp(*this);
		operator--();
		return *this;
	}

	bool operator==(const it& next) const {
		return index_position == next.index_position;
	}
	bool operator!=(const it& next) const {
		return index_position != next.index_position;
	}
	typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator-(const it<T>& it) {
		return index_position - it.index_position;
	}
	typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator+(it& it) {
		return index_position + it.index_position;
	}
	it operator+(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
		auto tmp(*this);
		tmp.index_position += it;
		return tmp;
	}
	bool operator<(const it& next) {
		return index_position < next.index_position;
	}
	bool operator<(T* p) {
		return index_position < p;
	}
	bool operator>(T* p) {
		return index_position > p;
	}
	bool operator<=(T* p) {
		return index_position <= p;
	}
	bool operator>=(T* p) {
		return index_position >= p;
	}
	bool operator<=(const it& next) {
		return index_position <= next.index_position;
	}
	bool operator>(const it& next) {
		return index_position > next.index_position;
	}
	bool operator>=(const it& next) {
		return index_position >= next.index_position;
	}
	it& operator+=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
		index_position += it;
		return *this;
	}
	it& operator-=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
		index_position -= it;
		return *this;
	}
	it& operator=(const it& it) {
		index_position = it.index_position;
		return *this;
	}
	it& operator=(T* it) {
		index_position = it;
		return *this;
	}
};