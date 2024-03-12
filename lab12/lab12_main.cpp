//Menu and observers
//The attached zip-file contains implementation of a simple menu system.
//Improve the menu system by adding an observable integer editing menu item class that
//reports changes to the observers when the change is approved.
//Change the Colors menu to use observable integer edits and create an observer that is
//registered to observe changes to any of the three colors.

#include <cstdlib>

#include <iostream>
#include "Menu.h"
#include "IntEdit.h"



int main(int argc, char **argv) {

    auto sub_menu = std::make_shared<Menu>("Colors");
    auto red = std::make_shared<IntEdit>("Red");
    auto blue = std::make_shared<IntEdit>("Blue");
    auto green = std::make_shared<IntEdit>("Green");
//    sub_menu->add_item(std::make_shared<IntEdit>("Red"));
//    sub_menu->add_item(std::make_shared<IntEdit>("Blue"));
//    sub_menu->add_item(std::make_shared<IntEdit>("Green"));
    auto observer = IntObserver();
    red->Attach(&observer);
    blue->Attach(&observer);
    green->Attach(&observer);

    sub_menu->add_item(red);
    sub_menu->add_item(blue);
    sub_menu->add_item(green);


    auto main_menu = std::make_shared<Menu>("Main menu");
    main_menu->add_item(std::make_shared<IntEdit>("Speed"));
    main_menu->add_item(std::make_shared<IntEdit>("Target"));
    main_menu->add_item(std::make_shared<IntEdit>("Sound"));
    main_menu->add_item(sub_menu);

    //main_menu->add_item(std::make_shared<Menu>("Testing empty menu"));

    main_menu->show();

    std::string s;
    do {
        std::cin >> s;
        if(s[0]=='+') main_menu->event(MenuItem::up);
        if(s[0]=='-') main_menu->event(MenuItem::down);
        if(s[0]=='<') main_menu->event(MenuItem::back);
        if(s[0]=='o') main_menu->event(MenuItem::ok);
    } while(s[0] != 'q');


	return 0;
}


