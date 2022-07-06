#ifndef __MANAGE_H__
#define __MANAGE_H__

#include <iostream>
#include <stdlib.h>
#include "database.h"

class Manage
{
protected:
    int choice;
    char query[100];
    Database DB;

public:
    virtual void Menu() = 0;
    void MenuSelect();
    virtual void Check() = 0;
    void ManageMenu();
    void ManageSelect();
    virtual void ManageCheck() = 0;
    virtual void ManageModify() = 0;
    virtual void ManageDelete() = 0;
};

#endif