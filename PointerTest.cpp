#include <iostream>

int main(){
    char myChar = 'A';
    char* myPointer = &myChar;
    std::cout << sizeof(myChar) << std::endl;
    std::cout << sizeof(myPointer) << std::endl;
    return 0;
}