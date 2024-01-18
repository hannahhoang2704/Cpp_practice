//
// Created by Hanh Hoang on 18.1.2024.
//
//Ex.2.1
//Write a program that asks user to enter a line that contains integers or “stop” to stop the program. If
//user enters a string that starts with “stop” the program stops. Otherwise, the program creates a
//string stream from the user input and reads integers from the stream. Program keeps reading and
//summing integer until the stream ends or reading an integer fails because text or other nonnumerical character is encountered. When the reading stops the sum and count are printed and
//program asks user to enter another string
#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

int main() {
    int nr;
    std::string line;

    std::cout << "Enter a line with numbers or “stop”: ";
    while(std::getline(std::cin, line), line != "stop") {
        std::vector<int> score;
        std::istringstream sin(line);
        while (sin >> nr){
            score.push_back(nr);
        }
        int total = std::accumulate(score.begin(), score.end(), 0);
        std::cout << "Total of " << score.size() << " numbers is " << total << std::endl;
        std::cout << "Enter a line with numbers or “stop”: ";
    }

    return 0;
}
