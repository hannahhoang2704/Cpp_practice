//
// Created by Hanh Hoang on 16.1.2024.
//
//Ex.1 std::vector
//Write a program that defines an empty vector of integers.
//Then program asks user how many numbers he/she wants to enter. Then program asks user to enter the numbers one at a time and adds them to the vector. When all number have been entered the program prints the numbers in the vector.

#include <iostream>
#include <vector>

int main() {
    int size;
    std::cout << "How many numbers do you want enter? ";
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i=0; i < size; i++){
        std::cout << "Enter nr [" << i << "]: ";
        std::cin >> vec[i];
    }
    std::cout << "You entered: ";
    for(int i = 0; i < size; i++){
        std::cout << vec[i];
        if(i < size-1){
            std::cout << ", ";
        }
    }
    return 0;
}
