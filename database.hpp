#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <mysql.h>
#include <string>
#include <stdexcept>

using namespace std;

class database {
public:
    MYSQL* conn;

    database(const char* host, const char* user, const char* password, unsigned int port);
    void createdatabase(const string& dbName);
    void selectdatabase(const string& dbName);
    void executeQuery(const string& query);
    ~database();
};

class UserManager {
public:
    static void usertable(database& db);
};

class ItemManager {
public:
    static void itemtypetable(database& db);
    static void insertitemtype(database& db);
    static void itemdescriptiontable(database& db);
    
};

class AssignTables{
public:
    static void seniordeveloperassign(database& db);
    static void developerassign(database& db);
};

#endif