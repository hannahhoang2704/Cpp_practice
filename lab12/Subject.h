//
// Created by Hanh Hoang on 7.3.2024.
//

#ifndef LAB12_SUBJECT_H
#define LAB12_SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual void Attach(Observer *o) = 0; // Set
    virtual void Notify() = 0;
};
#endif //LAB12_SUBJECT_H
