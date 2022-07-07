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
    sprintf(query, "SELECT num FROM guidelist WHERE num = %d", num);
    if (mysql_query(&DB.conn, query) != 0)
            fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
    else
    {
        DB.sql_result = mysql_store_result(&DB.conn);
        if (mysql_affected_rows(&DB.conn) == 0)
        {
            cout << "없는 번호입니다" << endl;
            return;
        }
    }
    cout << "수정할 내역을 선택하세요" << endl;
    cout << "1) 담당자\t2) 예약날짜" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        column = "guidepic";
        cout << "담당자 입력" << endl;
        cin >> change;
        sprintf(query, "SELECT guide FROM guide WHERE guide = '%s'", change.c_str());
        if (mysql_query(&DB.conn, query) != 0)
            fprintf(stderr, "database connect error : %s\n", mysql_error(&DB.conn));
        else
        {
            DB.sql_result = mysql_store_result(&DB.conn);
            if (mysql_affected_rows(&DB.conn) == 0)
            {
                cout << "등록되지 않은 담당자입니다" << endl;
                return;
            }
        }
        break;
    case 2:
        int year, month, day;
        column = "guidedate";
        cout << "연도 입력 ex)2022" << endl;
        cin >> year;
        if(year<2022)
        {
            cout<<"예약불가능한 연도입니다"<<endl;
            return;
        }
        else
            change = to_string(year);

        cout <<"월 입력 ex) 5"<< endl;
        cin>> month;
        if(month>0 && month<13)
        {
            if(month<10)
                change = change + "0";

            change = change + to_string(month);

        }
        else
        {
            cout<<"월 입력이 잘못되었습니다"<<endl;
            return;
        }
        cout <<"일 입력 ex) 10" << endl;
        cin>>day;
        if(month == 1 || month == 3 || month == 5 || month ==7 || month == 8 || month == 10 || month == 12)
        {
            if(day>0 && day<32)
            {
                if(day<10)
                    change = change + "0";
                
                change = change + to_string(day);
            }
            else
            {
                cout<<"잘못된 날짜입니다"<<endl;
                return;
            }
        } 
        else
        {
            if(day>0 && day<31)
            {
                if(day<10)
                    change = change + "0";
                
                change = change + to_string(day);
            }
            else
            {
                cout<<"잘못된 날짜입니다"<<endl;
                return;
            }
        }
        break;
    default:
        cout << "잘못 입력하셨습니다" << endl;
        return;
    }

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