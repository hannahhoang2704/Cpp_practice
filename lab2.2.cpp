//
// Created by Hanh Hoang on 24.1.2024.
//
//Ex2.2 oftream and std::filesystem
//Std::filesystem abstracts path handling and directory creation. The library provides functionality to
//resolve relative path to absolute path and operators for easy building of paths in a platform
//independent way.
//Std::filesystem::path has overloaded operators for creating a path by concatenating paths or strings.
//The resulting path can be used to open files or for example, to create multiple directories.
//Implement a program that asks user to enter directory names or enter a blank line to stop entry. The
//read names are stored in a vector of strings. When user has stopped entering directory names the
//program forms a relative path from the entered directory names. For example, if user entered “this”,
//“is”, and “test” the path is “this/is/test” (assuming posix opera=ng system, on windows the result ).
//To form a path use concatenation operator defined for std::filesystem::path.
//Then program creates the path using create_directories (see:
//https://en.cppreference.com/w/cpp/filesystem/create_directory ). After creating the directory, the
//program opens a text file “result.txt” for writing in the created directory and outputs the following
//thing both to screen and the file:
//• Absolute path to the file (there is a function to get that)
//• Content of the string vector one per line
//• Relative path to the file
//Note that since C++17 ofstream (and fstream in general) constructor can take filesystem::path as parameter.

#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <string>

void generate_content(std::ostream &stream, std::filesystem::path path, std::vector<std::string> v);

int main(){
    std::vector<std::string> dir_vector;
    std::filesystem::path path;
    std::string dir_name;

    std::cout << "Enter a directory name or blank to stop: ";
    while(std::getline(std::cin, dir_name), dir_name != ""){
        dir_vector.push_back(dir_name);
        std::cout << "Enter a directory name or blank to stop: ";
    };
    for(std::string str:dir_vector){
        path /= str;
    }
    std::filesystem::create_directories(path);
    generate_content(std::cout,  path, dir_vector);
    std::ofstream MyFile("result.txt");
    if(!MyFile.is_open()){
        std::cout << "Error" << std::endl;
        return -1;
    }else{
        generate_content(MyFile, path, dir_vector);
    }
    return 0;
}

void generate_content(std::ostream &stream, std::filesystem::path path, std::vector<std::string> v){
    stream << "Relative path: " << path << "\n";
    stream << "Absolute path created is " << std::filesystem::absolute(path) << "\n";
    stream << "Vector contains: " << "\n";
    for(std::string str:v){
        stream << str << "\n";
    }
}