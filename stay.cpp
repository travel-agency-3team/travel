#include "header/stay.h"
using namespace std;

void Stay::Menu()
{
    cout << "(1) 숙박업소 정보 조회" << endl;
    cout << "(2) 숙박업소 예약 관리" << endl;
}

void Stay::Check()
{
    sprintf(query, "SELECT * FROM stay");
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        while ((DB.sql_row = mysql_fetch_row(DB.sql_result)) != NULL)
            cout << DB.sql_row[0] << ") " << DB.sql_row[1] << " 주소 : " << DB.sql_row[2] << "  전화번호 : " << DB.sql_row[3] << endl;
    }
}

void Stay::ManageCheck()
{
    int check = 0;
    sprintf(query, "SELECT * FROM staylist");
    cout << "== 예약 내역 ==" << endl;
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        while ((DB.sql_row = mysql_fetch_row(DB.sql_result)) != NULL)
        {
            cout << DB.sql_row[0] << "번 예약) " << DB.sql_row[1] << "님 예약날짜 : " << DB.sql_row[3] << " 장소 : " << DB.sql_row[2] << endl;
            check++;
        }
        if (check == 0)
            cout << "예약 내역이 없습니다" << endl;
    }
}

void Stay::ManageModify()
{
    int num, choose;
    string column, change;
    cout << "수정할 예약 번호를 입력하세요" << endl;
    cin >> num;
    cout << "수정할 내역을 선택하세요" << endl;
    cout << "1) 예약장소\t2) 예약날짜" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        column = "stayname";
        cout << "장소 입력" << endl;
        break;
    case 2:
        column = "staydate";
        cout << "날짜 입력" << endl;
        break;
    default:
        cout << "잘못 입력하셨습니다" << endl;
        return;
    }
    cin >> change;
    sprintf(query, "UPDATE staylist SET %s ='%s' where num = %d", column.c_str(), change.c_str(), num);
    cout << query << endl;
    if (mysql_query(&DB.conn, query) != 0)
        fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        if (mysql_affected_rows(&DB.conn) == 0)
            cout << "예약목록에 없습니다" << endl;
        else
            cout << "수정되었습니다" << endl;
    }
}

void Stay::ManageDelete()
{
    int num;
    cout << "삭제할 예약 번호를 입력하세요" << endl;
    cin >> num;
    sprintf(query, "DELETE FROM staylist where num = %d", num);
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