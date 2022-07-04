#include "member.h"
using namespace std;

void Member::Menu()
{
    cout<<"(1) 회원목록 조회"<<endl;
    cout<<"(2) 회원정보 수정"<<endl;
    cout<<"(3) 회원정보 삭제"<<endl;
    cout<<"(4) 탈퇴회원 조회"<<endl;
}

void Member::Sel()
{
    cin>>choice;
    switch(choice)
    {
        case 1:
            Check();
        case 2:
            Modify();
        case 3:
            Delete();
        case 4:
            Withdraw();
        default:
            cout<<"잘못 입력"<<endl;
            break;
    }
}


void Check()
{   
    cout<<"== 일반 회원 =="
    sprintf(query, "SELECT * FROM common;");
    if(mysql_query(&conn, query)!=0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
    else
    {
        sql_result = mysql_store_result(&conn);
        if((sql_row = mysql_fetch_row(sql_result)) == NULL)
        {
            cout<<"검색 결과 없음"<<endl;
        }
        else
        {
            cout<<"ID : "<<sql_row[0]<<"Name : "<<sql_row[1]<<endl;

        }
}