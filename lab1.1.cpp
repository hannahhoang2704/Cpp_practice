//
// Created by Hanh Hoang on 16.1.2024.
//ex1.1 reference function
//Write a function that takes a reference to string and a character (by value) as parameters.
//The function replaces all occurrences of the character with underscores.
//Write a program that ask user to enter a string. Then program asks user to enter character to replace or “stop” to stop the program.
//Note that program must read a string after the second question to be able to test for “stop”. If answer is not “stop” then program passes the first character of second question’s answer as the character to replace.
// Then program prints the string and continues. If answer is “stop” the program ends.
#include <iostream>
#include <string>

void replace_character(std::string &input_str, char chr);
int main() {
    std::string str, input_char;
    std::cout << "Enter a string: "; std::getline(std::cin, str);
    std::cout << "Enter character to replace or “stop”: "; std::getline(std::cin, input_char);
    while(input_char != "stop"){
        replace_character(str, input_char[0]);
        std::cout << "Result: " << str <<std::endl;
        std::cout << "Enter a string: "; std::getline(std::cin, str);
        std::cout << "Enter character to replace or “stop”: "; std::getline(std::cin, input_char);
    }
    return 0;
}

void replace_character(std::string &input_str, char chr){
    for(char &c:input_str){
        if(c==chr) c = '_';
    }
}