#include <iostream>
#include "Stack.h"

int main()
{
    //Test with int:
    std::cout << "----- TESTING WITH INT -----\n";
    int* intArr = new int[3];
    *intArr = 1;
    *(intArr + 1) = 2;
    *(intArr + 2) = 3;
    Stack<int>* intStack = new Stack<int>(intArr, 3);
    intStack->print();
    intStack->push(7);
    std::cout << "Top element is: " << *(intStack->top()) << "\n";
    std::cout << "\t - Changing top element to 8...\n";
    *(intStack->top()) = 8;
    std::cout << "Top element is: " << *(intStack->top()) << "\n";
    intStack->push(2);
    intStack->push(3);
    intStack->print();
    std::cout << "The length is " << intStack->getLength() << "\n";
    std::cout << "Top element is: " << *(intStack->top()) << "\n";
    intStack->pop();
    intStack->pop();
    intStack->pop();
    intStack->print();
    std::cout << "The length is " << intStack->getLength() << "\n";
    std::cout << "Top element is: " << *(intStack->top()) << "\n";

    //Test with string:
    std::cout << "\n----- TESTING WITH STRING -----\n";
    std::string* stringArr = new std::string[3];
    *stringArr = "Stas Talanov";
    *(stringArr + 1) = "Ilya Ivanov";
    *(stringArr + 2) = "Sergey Blinov";
    Stack<std::string>* stringStack = new Stack<std::string>(stringArr, 3);
    stringStack->print();
    stringStack->push("Dmitry Lebedev");
    std::cout << "Top element is: " << *(stringStack->top()) << "\n";
    std::cout << "\t - Changing top element to Vladimir Mikhailov...\n";
    *(stringStack->top()) = "Vladimir Mikhailov";
    std::cout << "Top element is: " << *(stringStack->top()) << "\n";
    stringStack->push("Alex Orlov");
    stringStack->push("Konstantin Vladimirov");
    stringStack->print();
    std::cout << "The length is " << stringStack->getLength() << "\n";
    std::cout << "Top element is: " << *(stringStack->top()) << "\n";
    stringStack->pop();
    stringStack->pop();
    stringStack->pop();
    stringStack->print();
    std::cout << "The length is " << stringStack->getLength() << "\n";
    std::cout << "Top element is: " << *(stringStack->top()) << "\n";
    
    return 0;
}