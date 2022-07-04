#include "serverMainpage.h"

using namespace std;


void Page::ShowMenu()
{
    cout<<"== 여행사 관리 서버 =="<<endl;
    cout<<"1) 회원관리"<<endl;
    cout<<"2) 관광지 관리"<<endl;
    cout<<"3) 숙박 관리"<<endl;
    cout<<"4) 가이드 관리"<<endl;
    cout<<"번호를 선택하세요"<<endl;
}

void Page::Select()
{
    cin>>choice;
    switch(choice)
    {
        case 1:

            break;
        case 2:

        case 3:

        case 4:

        default:
            cout<<"잘못 입력하셨습니다"<<endl;

    }
}