//
// Created by Hanh Hoang on 6.2.2024.
//
//Smart pointers
//Implement class Apartment for storing information about rented apartment. The class must contain
//a shared_ptr to House (the class you implemented in an earlier exercise), apartment number, size of
//the apartment in m2 and the monthly rent. All data members must be private.
//There can be multiple apartments in a house and each apartment has a smart pointer to the house
//they are in and the pointer can be used to get the address of the apartment. You need to add a
//member function to House for getting the address.
//The apartment class must implement less than operator that compares apartments by monthly rent.
//The apartment class must have a member function that prints the apartment information:
//• Address and apartment nr
//• Size of the apartment
//• The monthly rent
//Write a program that creates two houses and defines a vector of Apartments. Program adds three
//apartments of the first house and four apartments of the second house to the vector. Then program
//sorts the apartments and prints the apartment information on separate lines

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <memory>
#include "lab4.h"

class Apartment{
public:
    Apartment(std::shared_ptr<House> house_p, int nr, double size, int rent);
    void get_apartment_info();
    bool operator<(const Apartment &obj) const;
private:
    std::shared_ptr<House> house_ptr;
    int apartment_nr;
    double apartment_size;
    int rent;
};

Apartment::Apartment(std::shared_ptr<House> house_p, int nr, double size, int rent): house_ptr(house_p), apartment_nr(nr), apartment_size(size), rent(rent) {
}

bool Apartment::operator<(const Apartment &obj) const {
    return this->rent < obj.rent;
}

void Apartment::get_apartment_info() {
    std::cout << house_ptr->getHouseAddress() << " " << apartment_nr << ", " << apartment_size << " " << rent << std::endl;
}

int main(){
    std::shared_ptr<House> house_p1 = std::make_shared<House>("Hämeentie 12", 100, 25000);
    std::shared_ptr<House> house_p2 = std::make_shared<House>("Rautatieasema 1", 200, 15000);
    std::vector<Apartment> apartment_vec;

    Apartment apt1(house_p1, 12, 20, 500);
    Apartment apt2(house_p1, 10, 40, 450);
    Apartment apt3(house_p1, 5, 45, 349);

    apartment_vec.push_back(apt1);
    apartment_vec.push_back(apt2);
    apartment_vec.push_back(apt3);

    Apartment apt4(house_p2, 25, 45, 650);
    Apartment apt5(house_p2, 8, 55, 400);

    apartment_vec.push_back(apt4);
    apartment_vec.push_back(apt5);

    std::sort(apartment_vec.begin(), apartment_vec.end());

    for(auto &apt:apartment_vec){
        apt.get_apartment_info();
    }
    return 0;
}