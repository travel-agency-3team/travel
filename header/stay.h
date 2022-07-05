#ifndef __STAY_H__
#define __STAY_H__

#include "manage.h"

class Stay : public Manage
{
public:
    virtual void Menu();
    virtual void Check();
    virtual void ManageCheck();
    virtual void ManageModify();
    virtual void ManageDelete();
};

#endif