//
// Created by Hanh Hoang on 26.2.2024.
//
//Multiple inheritance
//Observer pattern
//Improve lab7 by using observer pattern to report when a spy’s resistance is broken. Add the
//following abstract class definitions:
//class Observer;
//class Subject {
//public:
//    virtual void Attach(Observer *o) = 0; // Set
//    virtual void Notify() = 0;
//};
//// Abstract interface of Observer
//class Observer {
//public:
//    virtual void Update() = 0;
//};
//Derive a Spy class from Person and Subject and change interrogate so that when spy’s
//resistance is broken the registered observer is notified. Leave the rest of the spy’s as it was in lab7.
//Derive a Judge class from Person and Observer. When Judge gets an update the name of
//the judge is printed plus a text “I’m sending a spy to prison”. Note that Judge inherits
//functionality from Person so you need to implement only constructor and Update().
//Change the beginning of the main():
//Person agent("James Bond");
//Spy spy("Emilio Largo", "William Johnson", 3);
//Spy spy2("Ernst Blofield", "John Keats", 5);
//Judge judge("Judge Barnhill");
//spy.Attach(&judge);
//spy2.Attach(&judge);

#include <iostream>
#include <string>
#include <vector>
#include "lab7_main.cpp"

class Observer;
class Subject {
public:
    virtual void Attach(Observer *o) = 0; // Set
    virtual void Notify() = 0;
};
// Abstract interface of Observer
class Observer {
public:
    virtual void Update() = 0;
};

class Spy:public Person, public Subject{
public:
    explicit Spy(const char *name, std::string alias="", int resistance=0);
    virtual void identity() const override;
    virtual void interrogate() override;
    void set_identity(const char *alias);
    virtual void Attach(Observer *o) override;
    virtual void Notify() override;
private:
    std::string alias;
    int resistance;
    Observer *observer;
};

class Judge: public Person, public Observer{
public:
    Judge(const char* name): Person(name){};
    virtual void Update() {
        std::cout << "[";
        Person::identity();
        std::cout << "I’m sending a spy to prison.]" << std::endl;
    };
};


int main(int argc, char** argv) {

    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);
    Judge judge("Judge Barnhill");
    spy.Attach(&judge);
    spy2.Attach(&judge);

    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy.interrogate();
        spy.identity();
    }
    spy.set_identity("Bill Munny");
    spy.identity();

    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy2.interrogate();
        spy2.identity();
    }

    return 0;
}

Spy::Spy(const char *name, std::string alias, int resistance): Person(name), alias(alias), resistance(resistance) {}

void Spy::set_identity(const char *alias){
    this->alias = alias;
}

void Spy::interrogate() {
    if(resistance>0){
        resistance--;
    } else if(resistance == 0){
        Notify();
    }
}

void Spy::identity() const {
    if(resistance>0){
        std::cout << alias << std::endl;
    }else{
        std::cout << alias << ", real identity: ";
        Person::identity();
    }
}

void Spy::Attach(Observer *o) {
//    observer = std::move(o);
    observer = o;
}

void Spy::Notify() {
    observer->Update();
}