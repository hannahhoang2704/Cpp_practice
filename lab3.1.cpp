//
// Created by Hanh Hoang on 23.1.2024.
//
//ex3.1 std::map
//Write a program that defines a map<string, int>
//Program asks user to enter a name or “stop” or “print”. If user enters “stop” the program stops. If
//user enters “print” then the program prints the content of the map as key-value pairs. If input is
//neither “stop” not “print” then program asks user to enter an integer. Then program uses the
//entered name as the key (~index to map) to store the entered integer.
//To get the keys from the map you need to use iterators or range-for to loop through the map. When
//looping through the map the elements of the map are std::pairs that contain key and the value. If
//using iterator, the iterator “points” to a pair where first is key and second is the value. For example, if
//your iterator is called it then key of the current element is it->first and value is it->second.

#include <iostream>
#include <map>

int main() {
    std::string line;
    typedef std::map<std::string, int> map;
    map mymap;
    map::iterator it = mymap.begin();
    std::cout << "Enter name or “stop” or “print”: ";
    while(std::getline(std::cin, line), line != "stop"){
        if(line != "print"){
            int value;
            std::cout << "Enter integer: ";
            std::cin >> value;
            mymap.insert(std::pair<std::string, int>(line, value));
            std::cin.ignore();
        }else{
            for(it= mymap.begin(); it!= mymap.end(); ++it){
                std::cout << it->first << " : " << it->second << std::endl;
            }
        }
        std::cout << "Enter name or “stop” or “print”: ";
    }
    std::cout << "<program stops>";
    return 0;
}
