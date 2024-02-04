//
// Created by Hanh Hoang on 23.1.2024.
//ex3.2 class and constructor
//Implement a class for calculating running average of a number of values. The idea of running average
//that average is calculated of last N values. For example, when running average of last 10 values is
//calculated every time a new value is added if there are already 10 values the oldest value is removed.
//Implement a class called RunningAverage:
//• Constructor takes number of values as a parameter for example:
//RunningAverage avg(5);
//Creates an instance that remember five last values.
//• A deque of integers is used to store the values
//• Class has member function void add_value(int value) which is used to add a new
//value and to remove the oldest value if there are specified number of elements so that
//number of values in the never exceeds the size given in the constructor.
//• Class has member function double get_average() that returns the average of the stored
//values.
//Write a program that creates running average object to calculate running average of last five
//numbers. Program asks user to enter numbers and to enter zero to stop. If entered value is not zero
//it is added to the running average and program prints the current running average. If value is zero the
//program prints the current running average and then stops.

#include <iostream>
#include <deque>
class RunningAverage{
public:
    RunningAverage(int size=0);
    void add_value(int value);
    void print_queue() const;
    double get_average();
private:
    int size;
    std::deque<int> dequeue;
};


int main(){
    RunningAverage runningAvg(5);
    int input_value;
    std::cout << "Enter number to insert or 0 to stop: ";
    while (std::cin >> input_value && input_value != 0){
        runningAvg.add_value(input_value);
        runningAvg.print_queue();
        std::cout << "Enter number to insert or 0 to stop: ";
    }
    std::cout << "Average of the queue is " << runningAvg.get_average() << std::endl;
    return 0;
}

void RunningAverage::print_queue() const {
    std::cout << "Queue now is: ";
    for(int val:dequeue){
        std::cout << val << " ";
    }
    std::cout << "\n";
}
RunningAverage::RunningAverage(int size0):dequeue(size0) {
    size = size0;
}

void RunningAverage::add_value(int value) {
    dequeue.pop_front();
    dequeue.push_back(value);
}

double RunningAverage::get_average() {
    double sum=0;
    for(int val:dequeue){
        sum += val;
    }
    return sum/size;
}

