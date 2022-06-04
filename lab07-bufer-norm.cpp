#include <iostream>
#include "lab07-bufer-norm.h"

template<class F, typename T>
bufer<F, T>::bufer(T buf_size) {
	size = buf_size;
	array = new T[size];
}

template<class T, typename F>
void bufer<T, F>::push_back(T elem) {
	if (counter == size) {
		tail = ++tail % size;
	}
	else {
		counter++;
	}
	array[head] = elem;
	head = ++head % size;
}

template<class T, typename F>
void bufer<T, F>::push_front(T elem) {
	if (tail == 0) {
		tail = size - 1;
	}
	else {
		tail--;
	}
	array[tail] = elem;
	if (counter != size) {
		counter++;
	}
	else {
		head = tail;
	}
}

template<class T, typename F>
T bufer<T, F>::pop_front() {
	tail = ++tail % size;
	counter--;
	return array[temp];
}

template<class T, typename F>
T bufer<T, F>::access_front() {
	return array[tail];
}

template<class T, typename F>
T bufer<T, F>::pop_back() {
	if (head == 0) {
		head = size - 1;
	}
	else {
		head--;
	}
	counter--;
	return array[head];
}

template<class T, typename F>
T bufer<T, F>::access_back() {
	if (head == 0) {
		return array[size - 1];
	}
	return array[head - 1];
}



template<class F, typename T>
F& bufer<F, T>::operator[] (T index) {
	if (index <= counter) {
		return array[(head + index) % size];
	}
	else
		return NULL;
}

template<class T, typename F>
void bufer<T, F>::add_iterator(T elementh) {
	if (iter_index <= counter) {
		iter_index++;
		array[iter_index] = elementh;
	}
	else {
		std::cout << "Несуществующий индекс" << std::endl;
	}
	if (iter_index > counter) {
		iter_index = head;
	}
}

template<class F, typename T>
void bufer<F, T>::pop_iterator() {
	if (iter_index <= counter) {
		array[iter_index] = 0;
		if (iter_index > 0) {
			iter_index--;
		}
		else {
			iter_index = tail;
		}
	}
	else {
		std::cout << "Несуществующий индекс" << std::endl;
	}
}

template<class F, typename T>
void bufer<F, T>::print_buffer() {
	if (counter == 0) {
		std::cout << "Буффер пуст!" << std::endl;
	}
	else {
		std::cout << array[tail] << " ";
		unsigned int tmp = (tail + 1) % size;
		while (tmp != head) {
			std::cout << array[tmp] << " ";
			tmp = ++tmp % size;
		}
		std::cout << std::endl;
	}
}

template<class T, typename F>
void bufer<T, F>::capacity(unsigned new_size)
{
	T* new_buffer = new T[new_size];
	for (int i = 0; i < size or i < new_size; i++) {
		new_buffer[i] = array[i];
	}
	counter = std::min(counter, new_size);
	size = new_size;
	array = new_buffer;
	tail %= size;
	head %= size;
}

template<class T, typename F>
it<T> bufer<T, F>::front()
{
	return it<T>(array + tail, array, size, array + tail, array + head - 1);

}

template<class T, typename F>
it<T> bufer<T, F>::back()
{
	return it<T>(array + head, array, size, array + tail, array + head - 1);
}

template<typename T> it<T>::it(T* pos) { //NOLINT
	index_position = pos;
}