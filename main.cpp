#include "database.hpp"
#include "crow_all.h"
#include <mysql.h>
#include <vector>
using namespace std;

class user_routes{
public:
    static void setup(crow::SimpleApp& app, database&db) {
        CROW_ROUTE(app,"/register").methods("POST"_method)
            ([&db] (const crow::request& req) {
                auto jsonData = crow::json::load(req.body);
                if (!jsonData) return crow::response(400,"Invalid JSON payload");

                string username = jsonData["username"].s();
                string password = jsonData["password"].s();
                string role = jsonData["role"].s();

                string query = "INSERT INTO users (username, password, role) VALUES ('" + username + "', '" + password + "', '" + role + "');";

                if (mysql_query(db.conn, query.c_str())) {
                    return crow::response(500, mysql_error(db.conn));
                }

                return crow::response(200,"user creation successful");
            });
               
        CROW_ROUTE(app,"/login").methods("POST"_method)
        ([&db] (const crow::request& req) {
            auto jsonData = crow::json::load(req.body);
            if (!jsonData) return crow::response(400, "Invalid json payload");

            string username = jsonData["username"].s();
            string password = jsonData["password"].s();

            string query = "SELECT user_id, password, role FROM users WHERE username = '" + username + "' AND password = '" + password + "';";

            if (mysql_query(db.conn, query.c_str())) {
                return crow::response(500, mysql_error(db.conn));
            }

            MYSQL_RES* res = mysql_store_result(db.conn);
            MYSQL_ROW row = mysql_fetch_row(res);

            if (row) {
                string dbRole = row[2];
                std::string loweredRole = dbRole;
                std::transform(loweredRole.begin(), loweredRole.end(), loweredRole.begin(), ::tolower);

                if (loweredRole == "senior tester" || loweredRole == "senior developer") {
                    crow::json::wvalue result;
                    result["message"] = "Login successful";
                    result["user_id"] = std::stoi(row[0]);
                    result["role"] = dbRole;
                    mysql_free_result(res);
                    return crow::response(result);
                } else {
                    mysql_free_result(res);
                    crow::json::wvalue result;
                    result["message"] = "Access denied: unauthorized role";
                    return crow::response(403, result);
                }
            } else {
                mysql_free_result(res);
                crow::json::wvalue result;
                result["message"] = "User not found or incorrect credentials";
                return crow::response(404, result);
            }
        });
  
        CROW_ROUTE(app, "/home")([] {
            return "<h1>Home Page</h1>";
        });
        
        CROW_ROUTE(app,"/api/item-types").methods("GET"_method)([&db] () {
            string query = "SELECT type_name FROM item_types;";
            if (mysql_query(db.conn, query.c_str()) != 0) {
                return crow::response(500, mysql_error(db.conn));
            }

            MYSQL_RES* res = mysql_store_result(db.conn);
            MYSQL_ROW row;

            crow::json::wvalue result;
            crow::json::wvalue typesArray;
            int index = 0;

            while ((row = mysql_fetch_row(res))) 
            {
                typesArray[index++] = row[0];
            }

            result["types"] = std::move(typesArray);
            mysql_free_result(res);
            return crow::response(result); 
        });


        CROW_ROUTE(app,"/api/description").methods("POST"_method)([&db] (const crow::request& req) {
            auto jsonData = crow::json::load(req.body);

            if(!jsonData){
                return crow::response(400,"Invalid JSON payload");
            }

            string item_type = jsonData["item_type"].s();
            string item_status = jsonData["item_status"].s();
            string Description = jsonData["description"].s();
            string feature_type = jsonData["feature_type"].s();
            string query = "INSERT INTO item_description (item_type, item_status, Description, feature_type) VALUES ('" +
               item_type + "', '" + item_status + "', '" + Description + "', '" + feature_type + "');";



            if (mysql_query(db.conn, query.c_str())) {
                return crow::response(500, mysql_error(db.conn));
            }

            return crow::response(200, "Description inserted successfully.");
        });


        CROW_ROUTE(app, "/api/description/by-status").methods("GET"_method)
            ([&db](const crow::request& req){
                auto urlParams = crow::query_string(req.url_params);
                auto status = urlParams.get("status");

                string query = "SELECT description_id, item_type, item_status, feature_type, description FROM item_description";
                if (status) {
                    query += " WHERE item_status = '" + std::string(status) + "'";
                }
                query += ";";

                if (mysql_query(db.conn, query.c_str())) {
                    return crow::response(500, mysql_error(db.conn));
                }

                MYSQL_RES* res = mysql_store_result(db.conn);
                MYSQL_ROW row;
                crow::json::wvalue result;
                crow::json::wvalue items;

                int i = 0;
                while ((row = mysql_fetch_row(res))) {
                    crow::json::wvalue entry;
                    entry["description_id"] = stoi(row[0]);
                    entry["item_type"] = row[1];
                    entry["item_status"] = row[2];
                    entry["feature_type"] = row[3];
                    entry["description"] = row[4];
                    items[i++] = std::move(entry);
                }

                mysql_free_result(res);
                result["items"] = std::move(items);
                return crow::response(result);
            });


        CROW_ROUTE(app,"/api/edit").methods("POST"_method)([&db](const crow::request&req)
        {
            auto jsonData = crow::json::load(req.body);
            if (!jsonData) {
                return crow::response(400, "Invalid JSON");
            }

            int id = jsonData["description_id"].i(); // use the ID
            string item_type = jsonData["item_type"].s();
            string item_status = jsonData["item_status"].s();
            string description = jsonData["description"].s();
            string feature_type = jsonData["feature_type"].s();

            string query = "UPDATE item_description SET "
            "item_type = '" + item_type + "', "
            "item_status = '" + item_status + "', "
            "description = '" + description + "', "
            "feature_type = '" + feature_type + "' "
            "WHERE description_id = " + to_string(id) + ";";
            
            if (mysql_query(db.conn, query.c_str())) {
                return crow::response(500, mysql_error(db.conn));
            }

            if (mysql_affected_rows(db.conn) == 0) {
                return crow::response(404, "No matching record to update.");
            }

            return crow::response(200, "Description and status updated successfully.");
        });


       CROW_ROUTE(app, "/api/delete").methods("POST"_method)([&db](const crow::request& req){
            auto jsonData = crow::json::load(req.body);
            if (!jsonData){
                return crow::response(400, "Invalid JSON");
            }

            int id = jsonData["description_id"].i();

            std::string deleteAssign = "DELETE FROM item_assign WHERE description_id = " + std::to_string(id);
            mysql_query(db.conn, deleteAssign.c_str()); 

            std::string deleteDesc = "DELETE FROM item_description WHERE description_id = " + std::to_string(id);
            if (mysql_query(db.conn, deleteDesc.c_str()) == 0) {
                return crow::response(200, "Item deleted");
            } else {
                std::string error = mysql_error(db.conn);
                return crow::response(500, error);
            }
        });

        CROW_ROUTE(app, "/api/seniordevelopers").methods("GET"_method)([&db](const crow::request& req) {  //fetch the senior developers in the assign box
            string query = "SELECT user_id, username FROM users WHERE role = 'Senior Developer';";

            if (mysql_query(db.conn, query.c_str()) != 0) {
                return crow::response(500, mysql_error(db.conn));
            }

            MYSQL_RES *res = mysql_store_result(db.conn);
            if (!res) {
                return crow::response(500, "Failed to store result.");
            }

            MYSQL_ROW row;
            crow::json::wvalue result;
            crow::json::wvalue developer_list;
            int i = 0;

            while ((row = mysql_fetch_row(res))) {
                crow::json::wvalue entry;
                entry["id"] = std::stoi(row[0]);
                entry["username"] = row[1];
                developer_list[i++] = std::move(entry);
            }

            mysql_free_result(res);
            result["developers"] = std::move(developer_list);
            return crow::response(result);
        });
        
        CROW_ROUTE(app,"/api/assign").methods("POST"_method)([&db](const crow::request& req){ //assign to seniordevelopers by testers
            auto jsonData = crow::json::load(req.body);
            if (!jsonData) {
                return crow::response(400, "Invalid JSON");
            }

            int bug_id = jsonData["description_id"].i();
            int assignee_id = jsonData["assigned_to"].i();
            int assigned_by = jsonData["assigned_by"].i();  // Senior Tester’s ID

            CROW_LOG_INFO << "Assigning bug " << bug_id 
                          << " to " << assignee_id 
                          << " by " << assigned_by;

            string query = "INSERT INTO item_assign (description_id, assignee_id, assigned_by) VALUES (" +
                           to_string(bug_id) + ", " + to_string(assignee_id) + ", " + to_string(assigned_by) + ");";

            if (mysql_query(db.conn, query.c_str()) == 0) {
                return crow::response(200, "Bug assigned successfully.");
            } else {
                return crow::response(500, mysql_error(db.conn));
            }
        });   
        
        CROW_ROUTE(app, "/api/assigned-to").methods("GET"_method)([&db](const crow::request& req){
            auto urlParams = crow::query_string(req.url_params);
            int assignee_id = stoi(urlParams.get("id"));

            string query = "SELECT d.description_id, d.description, d.item_type, d.item_status "
                        "FROM item_description d "
                        "JOIN item_assign a ON d.description_id = a.description_id "
                        "WHERE a.assignee_id = " + to_string(assignee_id) + ";";

            if (mysql_query(db.conn, query.c_str())) {
                return crow::response(500, mysql_error(db.conn));
            }

            MYSQL_RES *res = mysql_store_result(db.conn);
            MYSQL_ROW row;
            crow::json::wvalue result;
            crow::json::wvalue bug_list;
            int i = 0;

            while ((row = mysql_fetch_row(res))) {
                crow::json::wvalue entry;
                entry["description_id"] = std::stoi(row[0]);
                entry["description"] = row[1];
                entry["item_type"] = row[2];
                entry["item_status"] = row[3];
                bug_list[i++] = std::move(entry);
            }

            mysql_free_result(res);
            result["assigned_bugs"] = std::move(bug_list);
            return crow::response(result);
        });
    }
};

int main() {
    crow::SimpleApp app;

    database db("127.0.0.1", "root", "arnav@123", 3306);
    db.createdatabase("bugtracker");
    db.selectdatabase("bugtracker");

    UserManager::usertable(db);
    ItemManager::itemtypetable(db);
    ItemManager::insertitemtype(db);
    ItemManager::itemdescriptiontable(db);
    AssignTables::seniordeveloperassign(db);

    user_routes::setup(app,db);

    CROW_ROUTE(app,"/")([] () {
        return "<h1>server is Running</h1>";
    });

    app.port(18080).multithreaded().run();
}