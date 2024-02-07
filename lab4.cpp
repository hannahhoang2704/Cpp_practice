//
// Created by Hanh Hoang on 27.1.2024.
//
//Implement class House for storing housing information.
//The class must use std::string for storing the address of the house, a double for the size (area in m2)
//of the house and an int for the price of the house in euros. All data member must be private.
//Class must define a constructor that takes the house information as parameters and there must be
//default constructor.
//The class must have the following operators:
//• Output operator for printing the housing information with minimal formatting. No newlines
//may be printed by the operator.
//• Input operator for reading the housing information from a stream. The operator must accept
//the format produced by the output operator. The address of the house may contain spaces
//so the operator must be able to read an address with spaces in it.
//• Less than operator that compares two houses by price/m2
//Class must define the following member functions:
//• setAddress for setting the address of the house
//• setArea for setting the area of the house
//• setPrice for setting the price of the house
//Write a program that defines a vector of House.
//The program asks user to enter information of five houses and stores them in the vector. The houses
//must be asked in the following ways:
//• Ask user to enter the house information (address, area, price) and use constructor to create
//a house by passing the information as parameters
//• Create a house using default constructor, ask user to enter the house information and use
//setter functions before adding the house to the vector
//• Create house using default constructor and read values using the input operator
//You can decide the mix between the five houses but at least one house must be asked using each of
//the above ways.
//Then sort the vector using std::sort and print the house information one house per line.
//Notes:
//To read a string from a stream using other that default delimiter (white space) you can use
//std::getline. It has overload that takes three parameters: stream to read from, reference to a string,
//and delimiting character. For example: std::getline(std::cin, my_str, ':');

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "lab4.h"


void handle_input(std::string &input, std::string &input_addr, double &input_size, int &input_price);

int main(){
    std::vector<class House> house_vector(VECTOR_SIZE);

    for(int i=0; i < VECTOR_SIZE; ++i){
        std::string input;
        std::string input_addr="";
        double input_size=0.0;
        int input_price=0;
        if(i==0){
            std::cout << "Enter house info (address, area, price) using ',' to separate parameters: ";
            std::getline(std::cin, input);
            handle_input(input, input_addr, input_size, input_price);
            House house(input_addr, input_size, input_price);
            house_vector[i]= house;
        } else if (i==1){
            House house;
            std::cout << "Enter house info (address, area, price) using ',' to separate parameters: ";
            std::getline(std::cin, input);
            handle_input(input, input_addr, input_size, input_price);
            house.setAddress(input_addr);
            house.setArea(input_size);
            house.setPrice(input_price);
            house_vector[i]= house;
        }else{
            House house;
            std::cout << "Enter address, size, house price using ',' to separate address and others: ";
            std::cin >> house;
            house_vector[i]= house;
        }
    }

    //sort vector
    std::sort(house_vector.begin(), house_vector.end());
    std::cout << "Sort house objects: " << std::endl;
    for(const auto &object:house_vector){
        std::cout << object << std::endl;
    }
    return 0;
}

//std::istream &operator>>(std::istream &in, House &object){
//    std::getline(in, object.address, ',');
//    in >> object.area_size >> object.price;
//    return in;
//}
//
//std::ostream &operator<<(std::ostream &out, const House &object){
//    out << object.address << "," << object.area_size << " " << object.price;
//    return out;
//}
//
//House::House(std::string name, double size, int house_price):address(name), area_size(size), price(house_price){
//}
//
//bool House::operator<(const House &obj) const{
//    double price_per_m = obj.price/obj.area_size;
//    return price_per_m < price/area_size;
//}
//
//void House::setAddress(const std::string addr) {
//    address = addr;
//}
//
//void House::setArea(const double area) {
//    area_size = area;
//}
//
//void House::setPrice(const int p) {
//    price = p;
//}
//
//std::string House::getHouseAddress() {
//    return address;
//}

void handle_input(std::string &input, std::string &input_addr, double &input_size, int &input_price){
    std::istringstream line(input);
    std::getline(line, input_addr, ',');
    line >> input_size;
    line.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    line >> input_price;
    line.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
