#include "database.hpp"
#include<iostream>

using namespace std;

database::database(const char* host, const char* user, const char* password,unsigned int port)
{

    conn = mysql_init(0);

    if(!conn) 
    {
        cout << "failed " <<endl;
        exit(1);
    }
    conn = mysql_real_connect(conn,host,user,password,nullptr,port,nullptr,0);
    if(!conn) 
    {
        cout << "connection failed!" << mysql_error(conn) << endl;
        exit(1);
    }
    cout << "successful connection" << endl;
}



void database::createdatabase(const string& dbName) 
{
    string query = "CREATE DATABASE IF NOT EXISTS " + dbName + ";";
    mysql_query(conn,query.c_str());
}

void database::selectdatabase(const string& dbName) 
{
    if (mysql_select_db(conn,dbName.c_str())) 
    {
        cout << "failed to select the db" << mysql_error(conn) << endl;
        mysql_close(conn);
        exit(1);
    }
}

void database::executeQuery(const string& query) {
    if (mysql_query(conn, query.c_str())) {
        cout << "failed" << mysql_error(conn) << endl;
    }
}

database :: ~database() {
    mysql_close(conn);
}

void UserManager::usertable(database& db) {
    string query = R"( CREATE TABLE IF NOT EXISTS users(
                        user_id INT PRIMARY KEY AUTO_INCREMENT,
                        username VARCHAR(50) NOT NULL UNIQUE,
                        password VARCHAR(255) NOT NULL,
                        role ENUM('developer','Senior Developer','Senior Tester', 'tester') NOT NULL,
                        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
                    );
                )";
            db.executeQuery(query);
} 

void ItemManager::itemtypetable(database& db) {
    string types = R"(CREATE TABLE IF NOT EXISTS item_types (
                        item_id INT PRIMARY KEY AUTO_INCREMENT,
                        type_name VARCHAR(50) NOT NULL
                    );
            )";
    db.executeQuery(types);
}

void ItemManager::insertitemtype(database& db) {
    string insert = R"(INSERT IGNORE INTO item_types (type_name) VALUES ('Bug'))";
        db.executeQuery(insert);
}

void ItemManager::itemdescriptiontable(database& db) {
    string description = R"(CREATE TABLE IF NOT EXISTS item_description(
        description_id INT PRIMARY KEY AUTO_INCREMENT,
        feature_type VARCHAR(50) NOT NULL,
        item_type VARCHAR(50) NOT NULL,
        item_status VARCHAR(50) NOT NULL,
        description TEXT NOT NULL
    );
    )";
    db.executeQuery(description);
}

void  AssignTables::seniordeveloperassign(database& db) {
    string assign = R"(CREATE TABLE IF NOT EXISTS item_assign (
        assign_id INT PRIMARY KEY AUTO_INCREMENT,
        description_id INT NOT NULL,
        assignee_id INT NOT NULL,
        assigned_by INT,
        assigned_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY (description_id) REFERENCES item_description(description_id),
        FOREIGN KEY (assignee_id) REFERENCES users(user_id)
    );
    )";
    db.executeQuery(assign);
}

