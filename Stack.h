#pragma once
#include <iostream>

/**
* @brief Stack of elements of <T> type.
*/
template<typename T>
class Stack
{
public:
	Stack() : length(0), stack (nullptr), topPointer(nullptr) {};

	Stack(T* array, size_t arrayLength) :	stack(array), 
											length(arrayLength), 
											topPointer(array + arrayLength - 1) 
	{
		std::cout << "Stack of type <" << typeid(T).name() << "> is created.\n";
	};
	size_t getLength() const;
	void pop();
	void push(T element);
	T* top();
	void print();

private:
	T* stack{ nullptr };
	size_t length{ 0 };
	T* topPointer{ nullptr };
};

/**
*@brief Get the length of the stack.
*@return length of the stack 
*/
template<typename T>
inline size_t Stack<T>::getLength() const
{
	return length;
}

/**
*@brief Pop (delete) the element from the top of the stack.
*/
template<typename T>
inline void Stack<T>::pop()
{
	if (length == 0 || topPointer == nullptr)
	{
		std::cerr << "No elements in stack.\n";
	}
	else if (length == 1)
	{
		std::cout << "\t - Deleting the element " << *topPointer << "\n";
		delete[] stack;
		stack = nullptr;
		topPointer = nullptr;
		length = 0;
	}
	else
	{
		std::cout << "\t - Deleting the element " << *topPointer << "\n";
		--length;
		T* resizedStack = new T[length];
		for (size_t i = 0; i < length; ++i)
		{
			*(resizedStack + i) = *(stack + i);
		}
		delete[] stack;
		stack = resizedStack;
		topPointer = stack + length - 1;
	}
}

/**
*@brief Push the element to stack.
*@param [in] element - element to be pushed
*/
template<typename T>
inline void Stack<T>::push(T element)
{
	std::cout << "\t - Adding the element " << element << "\n";
	T* resizedStack = new T[length + 1];
	for (size_t i = 0; i < length; ++i)
	{
		*(resizedStack + i) = *(stack + i);
	}
	delete[] stack;
	stack = resizedStack;
	*(stack + length) = element;
	topPointer = stack + length;
	++length;
}

/**
*@brief Get the pointer to the top of the stack.
*@return T* top
*/
template<typename T>
inline T* Stack<T>::top()
{
	return topPointer;
}

/**
*@brief Print the stack elements in console.
*/
template<typename T>
void Stack<T>::print()
{
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << "\'" << * (stack + i) << "\'" << " ";
	}
	std::cout << "\n";
}