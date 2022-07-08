#ifndef __STAYBOOKING_H__
#define __STAYBOOKING_H__

#include "database.h"
#include <iostream>


class StayBooking
{
    private:
        int choice;
        char query[100];
        std::string where;
        std::string date;
        std::string loginID;
        Database DB;
    public:
        std::string Location();
        std::string Date();
        void Book();
        void Menu(std::string ID);
        void Choose();
        void Check();
        void Change();
        void Modify();
        void Delete();
};

#endif