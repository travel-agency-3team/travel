#include "header/guide.h"
using namespace std;

void Guide::Menu()
{
    cout<<"(1) 가이드 정보 조회"<<endl;
    cout<<"(2) 가이드 예약 관리"<<endl;
}

void Guide::Check()
{
    sprintf(query, "SELECT * FROM guide");
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        while ((DB.sql_row = mysql_fetch_row(DB.sql_result)) != NULL)
            cout << DB.sql_row[0] << ") " << DB.sql_row[1] <<endl;
    }
}

void Guide::ManageCheck()
{
    int check = 0;
    sprintf(query, "SELECT * FROM guidelist");
    cout << "== 예약 내역 ==" << endl;
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        while ((DB.sql_row = mysql_fetch_row(DB.sql_result)) != NULL)
        {
            cout << DB.sql_row[0] << "번 예약) " << DB.sql_row[1] << "님 예약날짜 : " << DB.sql_row[3] << " 가이드담당 : " << DB.sql_row[2] << endl;
            check++;
        }
        if (check == 0)
            cout << "예약 내역이 없습니다" << endl;
    }

}



void Guide::ManageModify()
{
    int num, choose;
    string column, change;
    cout << "수정할 예약 번호를 입력하세요" << endl;
    cin >> num;
    cout << "수정할 내역을 선택하세요" << endl;
    cout << "1) 담당자\t2) 예약날짜" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        column = "guidepic";
        cout << "담당자 입력" << endl;
        break;
    case 2:
        column = "guidedate";
        cout << "날짜 입력" << endl;
        break;
    default:
        cout << "잘못 입력하셨습니다" << endl;
        return;
    }
    cin >> change;
    sprintf(query, "UPDATE guidelist SET %s ='%s' where num = %d", column.c_str(), change.c_str(), num);
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        if (mysql_affected_rows(&DB.conn) == 0)
            cout << "예약 내역이 없습니다" << endl;
        else
            cout << "수정되었습니다" << endl;
    }
}


void Guide::ManageDelete()
{
    int num;
    cout << "삭제할 예약 번호를 입력하세요" << endl;
    cin >> num;
    sprintf(query, "DELETE FROM guidelist where num = %d", num);
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        if (mysql_affected_rows(&DB.conn) == 0)
            cout << "예약목록에 없는 번호입니다" << endl;
        else
            cout << "삭제되었습니다" << endl;
    }
}