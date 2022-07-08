#include "mainpage.h"
#include <unistd.h>

using namespace std;

void Page::MainPage()
{
    while(repeat)
    {
        if(login == false)
        {
            
            cout<<"1) 회원가입"<<endl;
            cout<<"2) 로그인"<<endl;
            cout<<"3) 종료"<<endl;
            cin>>num;
            cin.ignore();
            system("clear");
            repeat = true;
            switch(num)
            {
                case 1:
                    //회원가입 클래스
                    break;
                case 2:
                    //로그인 클래스
                    login = true;
                    loginID ="asd";
                    break;
                case 3:
                    repeat = false;
                    break;
                default:
                    cout<<"잘못 입력하셨습니다"<<endl;
                    break;
            }
        }
        else
        { 
            LoginPage(loginID);
        }
    }
}

void Page::LoginPage(string loginID)
{
    cout<<"1) 회원정보 수정/탈퇴"<<endl;
    cout<<"2) 관광지 예약"<<endl;
    cout<<"3) 숙박 예약"<<endl;
    cout<<"4) 가이드 예약"<<endl; 
    cout<<"5) 로그아웃"<<endl;
    cin>>sel;
    cin.ignore();
    system("clear");
    switch(sel)
    {
        case 1:
        
            break;
        case 2:

            break;
        case 3:
            stay.Menu(loginID);
            stay.Choose();
            break;
        case 4:
            guide.Menu(loginID);
            guide.Choose();
            break;
        case 5:
            login = false;
            break;
        default:
            cout<<"잘못 입력하셨습니다"<<endl;
            break;
    }
}

