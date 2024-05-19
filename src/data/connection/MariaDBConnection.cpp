#include "MariaDBConnection.h"
#include <iostream>

// TODO: Add class on compilation script (make.sh)
// src/data/connection/MariaDBConnection.cpp
// -I"C:\Program Files\MariaDB\MariaDB C++ Connector 64-bit\include" -L"C:\Program Files\MariaDB\MariaDB C++ Connector 64-bit" -lmariadbcpp

MariaDBConnection::MariaDBConnection() 
{
    try
    {
        this->driver = sql::mariadb::get_driver_instance();
        string connString = "jdbc:mariadb://" + serverIp + ":" + serverPort + "/" + serverDatabase;
        sql::SQLString url(connString);
        sql::Properties properties({
            {"user", this->serverUser},
            {"password", this->serverPassword}
        });

        this->connection = driver->connect(url, properties);
    }
    catch (sql::SQLException &myException)
    {
        cerr << "Error Connecting to MariaDB Platform: \n" << myException.what() << endl;
        exit(1);
    }
}

MariaDBConnection::~MariaDBConnection()
{
    if (this->connection)
    {
        this->connection->close();
        delete this->connection;
    }
}

sql::Connection* MariaDBConnection::getConnection() const
{
    return this->connection;
}
