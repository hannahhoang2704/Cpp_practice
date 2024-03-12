//
// Created by Hanh Hoang on 7.3.2024.
//

#ifndef LAB12_OBSERVER_H
#define LAB12_OBSERVER_H
#include <iostream>
class Observer {
public:
    virtual void Update() = 0;
};

class IntObserver: public Observer{
public:
    virtual void Update(){
        std::cout << "Value changed" << std::endl;
    }
};
#endif //LAB12_OBSERVER_H
