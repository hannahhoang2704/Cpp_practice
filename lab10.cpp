//
// Created by Hanh Hoang on 28.2.2024.
//
//Exceptions
//what the class from exercise 5 should do:
//Constructor takes two parameters that determine the range of numbers that the
//generator produces. The parameters are upper and lower limit of the range. Both
//values are included in the range. For example: lower = 2, upper = 6 can produce
//following random numbers: 2, 3, 4, 5, 6 (in random order).
//The generator in the exercise 5 gets stuck in an infinite loop if all numbers in the range have
//already been used. Improve the generator so that it throws runtime_error with
//explanation "Unable to produce unique random number" if all numbers in the range have already been used.
//Implement function test_generator that generates requested number of unique random
//numbers. Function catches exceptions and prints a message if an exception occurs.
//Finally, the program prints the generated random numbers. The following example assumes
//that the class is called UniqueRng. Change the class name to match your random number
//class name.
//void test_generator(UniqueRng ur, int count)
//int main(void) {
//    UniqueRng randGen(5, 13);
//    test_generator(randGen, 6);
//    test_generator(randGen, 9);
//    test_generator(randGen, 13); // this will cause exception
//    UniqueRng randGen2(1, 35);
//    test_generator(randGen2, 7);
//    test_generator(randGen2, 7);
//    test_generator(randGen2, 7);
//    test_generator(randGen2, 70); // this will cause exception
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RandGen {
public:
    RandGen(int min, int max);
    RandGen(): numbers() {srand(time(NULL));};
    int operator()();
private:
    vector<int> numbers;
    int range_min;
    int range_max;
};

class Print_matching_vector{
public:
    Print_matching_vector();
    void operator()(int nr);
private:
    int index=0;
};

void test_generator(RandGen ur, int count);

int main(void) {
    RandGen randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13); // this will cause exception
    RandGen randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70); // this will cause exception

    return 0;
}

RandGen::RandGen(int min, int max):range_min(min), range_max(max){}

int RandGen::operator()() {
    int number;
    int range = range_max - range_min + 1;
    if (numbers.size() >= range){
        throw runtime_error("Unable to produce unique random number.");
    }
    do {
        number = rand() % range + range_min;
    } while(find(numbers.begin(), numbers.end(), number) != numbers.end());

    numbers.push_back(number);
    return number;
}

Print_matching_vector::Print_matching_vector():index(0) {}

void Print_matching_vector::operator()(int nr) {
    cout << "#" << ++index << ": " << nr << endl;
}

void test_generator(RandGen ur, int count){
    vector<int> vec;
    cout << "Generating numbers" << endl;
    try{
        for(int i = 0; i < count; ++i){
            vec.push_back(ur());
        }
    }catch(runtime_error &e){
        cout << e.what();
        cout << " Tried to generate " << count << " random numbers. Got only " << vec.size() << endl;
    }
    for(auto i = vec.begin(); i != vec.end(); ++i){
            cout << *i << endl;
    }
}