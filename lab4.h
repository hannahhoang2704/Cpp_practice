//
// Created by Hanh Hoang on 7.2.2024.
//

#ifndef CPP_EXCERCISES_LAB4_H
#define CPP_EXCERCISES_LAB4_H
#include <sstream>
#include<limits> //used to get numeric limits
#include<ios> //used to get stream size

#define VECTOR_SIZE 5

class House{
    friend std::istream &operator>>(std::istream &in, House &object);
    friend std::ostream &operator<<(std::ostream &out, const House &object);
public:
    House(std::string name="", double size=0.0, int house_price=0);
    bool operator<(const House &obj) const;
    void setAddress(const std::string addr);
    void setArea(const double area);
    void setPrice(const int p);
    std::string getHouseAddress();
private:
    std::string address;
    double area_size;
    int price;
};

std::istream &operator>>(std::istream &in, House &object){
    std::getline(in, object.address, ',');
    in >> object.area_size >> object.price;
    return in;
}

std::ostream &operator<<(std::ostream &out, const House &object){
    out << object.address << "," << object.area_size << " " << object.price;
    return out;
}

House::House(std::string name, double size, int house_price):address(name), area_size(size), price(house_price){
}

bool House::operator<(const House &obj) const{
    double price_per_m = obj.price/obj.area_size;
    return price_per_m < price/area_size;
}

void House::setAddress(const std::string addr) {
    address = addr;
}

void House::setArea(const double area) {
    area_size = area;
}

void House::setPrice(const int p) {
    price = p;
}

std::string House::getHouseAddress() {
    return address;
}
#endif //CPP_EXCERCISES_LAB4_H
