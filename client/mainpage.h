#ifndef __MAINPAGE_H_
#define __MAINPAGE_H_

#include <iostream>
#include "staybooking.h"
#include "login.h"
#include "signup.h"
using namespace std;
class Page
{
private:
    StayBooking stay;

    string loginID, membership;
    int num, sel;
    bool repeat;
    bool login;
public:
    Page()
    {
        repeat = true;
        login = false;
    }
    void MainPage();
    void LoginPage(string loginID);
};



#endif