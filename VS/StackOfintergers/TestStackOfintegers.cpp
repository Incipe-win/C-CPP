#include<iostream>
#include<cassert>
#include"StackOfintegers.h"

int main() {
	StackOfintegers s1{};
	for (int i = 0; i < 5; i++) {
		s1.push(i + 1);
	}
	std::cout << "Stack size is:" << s1.getsize() << std::endl;
	std::cout << "Top elements is:" << s1.peek() << std::endl;
	const int size = s1.getsize();
	for (int i = 0; i < size; i++) {
		std::cout << s1.pop() << " ";
	}
	std::cout << std::endl;
	std::cout << "Stack now is empty: " << s1.empty() << std::endl;
	std::cin.get();
	return 0;
}