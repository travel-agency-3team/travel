#include <iostream>
#include <string>
#include <cstring>
#include "database.h"

using namespace std;

class Member
{
private:
    string id;
    string pw;
    string name;
public:
    Member()
    {
        this->id = id;
        this->pw = pw;
        this->name = name;
    }
    Member(const string& _id, const string& _pw, const string& _name)
    {
        id = _id;
        pw = _pw;
        name = _name;
    }
    string ID_Get()
    {
        cout << "ID: ";
        cin >> id;
        return id;
    }
    string PW_Get()
    {
        cout << "PW: ";
        cin >> id;
        return pw;
    }
    string Name_Get()
    {
        cout << "Name: ";
        cin >> id;
        return name;
    }

    /*
    Member(const Member& copy) : select(copy.select)
    {
        id = copy.id;
        pw = copy.pw;
        name = copy.name;
        query = copy.query;
        vip_user = true;
        common_user = false;
    }
    ~Member() {}
    */
};

class Vip : public Member
{
private:
    bool vip_member;
public:
    Vip() { vip_member = true; }
    Vip(const string& id, const string& pw, const string& name)
        : Member(id, pw, name) {
        vip_member = true;
    }
    bool Vip_()
    {
        return vip_member;
    }
};

class Common : public Member
{
private:
    bool common_member;
public:
    Common() { common_member = false; }
    Common(const string& id, const string& pw, const string& name)
        : Member(id, pw, name) {
        common_member = false;
    }
    bool Common_()
    {
        return common_member;
    }
};

class Handler :public Database
{
private:
    Member member;
    int num;
    char query[1024];

public:
    Handler() : num(0)
    {
        strcpy(this->query, query);
    }

    void Show_Info() const
    {
        cout << "=== 유진초이 여행사 입니다 ===" << endl;
        cout << "1. 로그인" << endl;
        cout << "2. 회원가입" << endl;
        cout << "3. 내정보 수정" << endl;
        cout << "5. 탈퇴" << endl;
        cout << "입력: ";
    }

    bool Member_Choice()
    {
        cout << "1.일반 2.정회원" << endl;
        cin >> num;
        cin.ignore();
        return num != 1 ? true : false;
    }

    void Log_in() // 1 로그인
    {
        if (sprintf(query, "SELECT id, name FROM common WHERE id ='%s' AND pw='%s'", member.ID_Get().c_str(), member.PW_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                cout << "로그인 완료" << endl;
                mysql_free_result(sql_result);
            }
        }
        else if (sprintf(query, "SELECT id, name FROM vip WHERE id ='%s' AND pw='%s'", member.ID_Get().c_str(), member.PW_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                cout << "로그인 완료" << endl;
                mysql_free_result(sql_result);
            }
        }
    }

    void Member_Join() //2. 회원가입
    {
        if (Member_Choice())
        {
            sprintf(query, "INSERT INTO vip(id, pw, name) VALUES ('%s', '%s', '%s')", member.ID_Get().c_str(), member.PW_Get().c_str(), member.Name_Get().c_str());
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
                cout << "완" << endl;
        }
        else
        {
            sprintf(query, "INSERT INTO common(id, pw, name) VALUES ('%s', '%s', '%s')", member.ID_Get().c_str(), member.PW_Get().c_str(), member.Name_Get().c_str());
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
                cout << "완" << endl;
        }
    }

    void Find_Member() //3 분실
    {
        if (sprintf(query, "SELECT id, pw FROM common WHERE name LIKE '%s')", member.Name_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                sql_result = mysql_store_result(&conn);
                sql_row = mysql_fetch_row(sql_result);
                cout << "ID: " << sql_row[0] << endl;
                cout << "PW: " << sql_row[1] << endl;
            }
        }
        else if (sprintf(query, "SELECT id, pw FROM vip WHERE name LIKE '%s')", member.Name_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                sql_result = mysql_store_result(&conn);
                sql_row = mysql_fetch_row(sql_result);
                cout << "ID: " << sql_row[0] << endl;
                cout << "PW: " << sql_row[1] << endl;
            }
        }
    }


    void Chage_Member_Info() // 수정
    {
        //아이디 확인 후 비번 변경
        if (sprintf(query, "UPDATE vip SET pw='%s' where id='%s')", member.PW_Get().c_str(), member.ID_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                sql_result = mysql_store_result(&conn);
                sql_row = mysql_fetch_row(sql_result);
                cout << "변경된 PW: " << sql_row[1] << endl;
            }
        }
        if (sprintf(query, "UPDATE common SET pw='%s' where id='%s')", member.PW_Get().c_str(), member.ID_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                sql_result = mysql_store_result(&conn);
                sql_row = mysql_fetch_row(sql_result);
                cout << "변경된 PW: " << sql_row[1] << endl;
            }
        }
    }

    void Cancel_Member() // 탈퇴
    {
        if (sprintf(query, "DELETE FROM vip WHERE id='%s' AND pw='%s')", member.ID_Get().c_str(), member.PW_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                cout << "삭제 완" << endl;
            }
        }
        if (sprintf(query, "DELETE FROM common WHERE id='%s' AND pw='%s')", member.ID_Get().c_str(), member.PW_Get().c_str()))
        {
            if (mysql_query(&conn, query) != 0)
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            else
            {
                cout << "삭제 완" << endl;
            }
        }
    }

    void Come_In()
    {
        Show_Info();
        cin >> num;
        switch (num)
        {
        case 1: //로그인
            Log_in();
            break;
        case 2:  //회원 가입
            Member_Join();
            break;
        case 3: //분실
            Find_Member();
            break;
        case 4: //수정
            Chage_Member_Info();
            break;
        case 5: //탈퇴
            Cancel_Member();
            break;
        default:
            break;
        }
    }
};

int main()
{
    Handler handler;
    handler.Come_In();

    return 0;
}