#ifndef DB_H
#define DB_H
#include <sqlext.h>
#include <winddi.h>
#include <sql.h>
#include <string>
#include <iostream>
using namespace std;

class DB
{
private:
    SQLHENV hENV;
    SQLHDBC db;
    DB()
    {
        this->hENV = NULL;
        this->db = NULL;
    }
    DB(const DB &) = delete;
    DB &operator=(const DB &) = delete;

public:
    bool excuteQuery(string query)
    {

    }
    bool dbStatus()
    {

    }
    void dbError()
    {
        
    }
};

#endif // DB_H