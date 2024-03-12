//
// Created by Keijo Länsikunnas on 5.3.2024.
//

#ifndef LAB12_INTEDIT_H
#define LAB12_INTEDIT_H
#include <string>
#include "MenuItem.h"
#include "Subject.h"

class IntEdit : public MenuItem, public Subject {
public:
    explicit IntEdit(std::string menu_title);
    bool event(menuEvent e) override;
    void show() override;
    virtual void Attach(Observer *o) override;
    virtual void Notify() override;
protected:
    int value;
    int backup;
    bool changed;
    Observer *observer;
//    std::vector<Observer*> observer;
};


#endif //LAB12_INTEDIT_H
