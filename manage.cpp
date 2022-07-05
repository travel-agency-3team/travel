#include "header/manage.h"
using namespace std;

void Manage::MenuSelect()
{
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
        Check();
        break;
    case 2:
        ManageMenu();
        ManageSelect();
        break;
    dafault:
        cout << "잘못 선택하셨습니다" << endl;
        break;
    }
}

void Manage::ManageMenu()
{
    cout << "1) 예약조회" << endl;
    cout << "2) 예약변경" << endl;
    cout << "3) 예약취소" << endl;
}

void Manage::ManageSelect()
{
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
        ManageCheck();
        break;
    case 2:
        ManageModify();
        break;
    case 3:
        ManageDelete();
        break;
    default:
        cout << "잘못 입력하셨습니다" << endl;
        return;
    }
}
