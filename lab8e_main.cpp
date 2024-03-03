//
//Abstract class
//In this exercise you need to derive two classes from an abstract class and write a function
//that helps in testing the classes. Your starting point is an abstract class called Counter that
//defines an interface for incrementing and decrementing a counter and a conversion
//operator that can be used to read or print the current counter value.
//Derive a class called LimitedCounter.
//• The constructor takes two parameters: initial value and upper limit.
//• Counter can’t be incremented over the upper limit. If inc() is called when counter has
//reached the upper limit nothing happens
//• Counter can’t be decremented below zero. If counter is zero then calling dec() will
// have no effect
//Derive a class called OverflowCounter.
//• The constructor takes two parameters: initial value and upper limit.
//• When counter has reached the upper limit incrementing the value will set the counter
//to zero.
//• When counter is zero decrementing the counter sets counter to upper limit.
//Implement function called UseCounter.
//• void UseCounter(Counter& ctr, int num);
//• Function takes two parameters: a reference to Counter and number that tells how
//many times the counter should be incremented or decremented. A negative value
// decrements counter and positive value increments counter.
//Test your counters with different values and ways. Pay attention to the limits and make sure
//that they work properly.

#include <iostream>

using namespace std;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter: public Counter{
public:
    explicit LimitedCounter(int initial_val, int upper_limit): init_value(initial_val), limit_value(upper_limit){};
    virtual void inc() override;
    virtual void dec() override;
    virtual operator int() override;
private:
    int init_value;
    int limit_value;
};

class OverflowCounter: public Counter{
public:
    explicit OverflowCounter(int initial_val, int upper_limit):init_value(initial_val), limit_value(upper_limit){};
    virtual void inc() override;
    virtual void dec() override;
    virtual operator int() override;
private:
    int init_value;
    int limit_value;
};

// you need to implement this function
void UseCounter(Counter& ctr, int num);


int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}


void LimitedCounter::dec() {
    if(init_value > 0) init_value--;
}

void LimitedCounter::inc() {
    if(init_value < limit_value) init_value++;
}

LimitedCounter::operator int() {return init_value;}

void OverflowCounter::dec() {
    if(init_value > 0) init_value--;
    else if (init_value == 0) init_value = limit_value;
}

void OverflowCounter::inc() {
    if(init_value<limit_value) init_value++;
    else if(init_value == limit_value) init_value=0;
}

OverflowCounter::operator int() {return init_value;}

void UseCounter(Counter& ctr, int num){
   if (num > 0){
       for(int i = 0; i < num; ++i){
           ctr.inc();
       }
   }else if(num < 0){
       for(int i = 0; i > num; --i){
           ctr.dec();
       }
   }
}