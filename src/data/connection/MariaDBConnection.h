#ifndef MARIA_DB_CONNECTION_H
#define MARIA_DB_CONNECTION_H

#include <mariadb/conncpp.hpp>
#include <string>

using namespace std;

class MariaDBConnection
{
private:
    string serverPort = "3306";
    string serverIp = "143.106.243.64";
    string serverDatabase = "Si300A2024_06";
    string serverUser = "Si300A2024_06";
    string serverPassword = "czn07XWoDJ";

    sql::Driver *driver = nullptr;
    sql::Connection *connection = nullptr;

public:
    MariaDBConnection();
    virtual ~MariaDBConnection();
    sql::Connection* getConnection() const;
};

#endif // MARIA_DB_CONNECTION_H