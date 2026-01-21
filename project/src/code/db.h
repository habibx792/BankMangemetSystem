#ifndef DB_H
#define DB_H
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

class DB
{
private:
    SQLHENV henv;
    bool isConnected;
    SQLHDBC hdbc;
    DB()
    {
        this->henv = NULL;
        this->hdbc = NULL;
        isConnected = false;
    }
    DB(const DB &) = delete;
    DB &operator=(const DB &) = delete;

public:
    bool connect()
    {
        SQLRETURN retcode;

        // Allocate environment handle
        retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &this->henv);
        if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
        {
            cout << "Error allocating environment handle" << endl;
            return false;
        }

        // Set the ODBC version
        retcode = SQLSetEnvAttr(this->henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
        if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
        {
            cout << "Error setting ODBC version" << endl;
            SQLFreeHandle(SQL_HANDLE_ENV, this->henv);
            return false;
        }

        // Allocate connection handle
        retcode = SQLAllocHandle(SQL_HANDLE_DBC, this->henv, &this->hdbc);
        if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
        {
            cout << "Error allocating connection handle" << endl;
            SQLFreeHandle(SQL_HANDLE_ENV, this->henv);
            return false;
        }

        // Connect to Bank database using direct ODBC
        SQLCHAR *connStr = (SQLCHAR *)"DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost\\SQLEXPRESS;DATABASE=Bank;Trusted_Connection=yes;TrustServerCertificate=yes;";

        SQLCHAR outConnStr[1024];
        SQLSMALLINT outConnStrLen;

        retcode = SQLDriverConnect(this->hdbc, NULL, connStr, SQL_NTS,
                                   outConnStr, sizeof(outConnStr),
                                   &outConnStrLen, SQL_DRIVER_NOPROMPT);

        if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
        {
            cout << "Error connecting to Bank database" << endl;
            SQLFreeHandle(SQL_HANDLE_DBC, this->hdbc);
            SQLFreeHandle(SQL_HANDLE_ENV, this->henv);
            return false;
        }

        this->isConnected = true;
        cout << "Connected to Bank database successfully" << endl;
        return true;
    }
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