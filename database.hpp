#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <mysql.h>
#include <string>

using namespace std;

class database {
public:
    MYSQL* conn;
    database(const char*, const char*, const char*, unsigned int);
    void createdatabase(const string&);
    void selectdatabase(const string&);
    void executeQuery(const string&);
    ~database();
};

class UserManager {
public:
    static void usertable(database&);
};

class ItemManager {
public:
    static void itemtypetable(database&);
    static void insertitemtype(database&);
    static void itemdescriptiontable(database&);
};

class AssignTables {
public:
    static void seniordeveloperassign(database&);
};

#endif