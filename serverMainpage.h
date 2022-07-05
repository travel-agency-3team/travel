#ifndef __SERVERMAINPAGE_H_
#define __SERVERMAINPAGE_H_

#include <iostream>
#include "member.h"


class Page
{
    private:
        Member member;
        int choice;

    public:
        void ShowMenu();
        void Select();
};

#endif
