#ifndef __GUIDE_H__
#define __GUIDE_H__

#include "manage.h"

class Guide : public Manage
{
   
public:
    virtual void Menu();
    virtual void Check();
    virtual void ManageCheck();
    virtual void ManageModify();
    virtual void ManageDelete();

};

#endif