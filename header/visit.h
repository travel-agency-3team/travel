#ifndef __VISIT_H__
#define __VISIT_H__

#include <iostream>
#include "manage.h"
#include "database.h"

class Visit : public Manage
{

public:
    virtual void Menu();
    virtual void Check();
    virtual void ManageCheck();
    virtual void ManageModify();
    virtual void ManageDelete();
};

#endif
