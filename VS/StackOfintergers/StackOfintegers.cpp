#include"StackOfintegers.h"

StackOfintegers::StackOfintegers() {
	size = 0;
	for (auto i : elements) {
		i = 0;
	}
}

bool StackOfintegers::empty() {
	return (size == 0 ? true : false);
}

int StackOfintegers::getsize() {
	return size;
}

int StackOfintegers::peek() {
	return elements[size - 1];
}

int StackOfintegers::pop() {
	int temp = elements[size - 1];
	elements[size - 1] = 0;
	size--;
	return temp;
}

int StackOfintegers::push(int value) {
	elements[size] = value;
	size++;
	return value;
}
