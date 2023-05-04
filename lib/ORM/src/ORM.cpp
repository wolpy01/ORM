#include "ORM.hpp"

#include <iostream>
#include <string>
#include <fstream>

const std::string DIRECTORY_PATH = "../data/request.txt";
const std::string TEST_CONNECTION = "connectionMOCK";

void ORM::Select(std::string table)
{
    if (!ConnectionDB(TEST_CONNECTION))
        throw "Connection is failed.";

    std::ofstream SQLRequest(DIRECTORY_PATH, std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("SELECT *\nFROM " + table + ";");
    SQLRequest.close();
}

void ORM::Filter(std::string table, std::string parameter)
{
    if (!ConnectionDB(TEST_CONNECTION))
        throw "Connection is failed.";

    std::ofstream SQLRequest(DIRECTORY_PATH, std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("SELECT *\nFROM " + table + " WHERE " + parameter + ";");
    SQLRequest.close();
}

void ORM::Find(std::string table, std::string object_id)
{
    if (!ConnectionDB(TEST_CONNECTION))
        throw "Connection is failed.";

    std::ofstream SQLRequest(DIRECTORY_PATH, std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("SELECT *\nFROM " + table + " WHERE object_id = " + object_id + ";");
    SQLRequest.close();
}

void ORM::Delete(std::string table, std::string object_id)
{
    if (!ConnectionDB(TEST_CONNECTION))
        throw "Connection is failed.";

    std::ofstream SQLRequest(DIRECTORY_PATH, std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("DELETE *\nFROM " + table + " WHERE object_id = " + object_id + ";");
    SQLRequest.close();
}

void ORM::Insert(std::string table, std::string object)
{
    if (!ConnectionDB(TEST_CONNECTION))
        throw "Connection is failed.";

    std::ofstream SQLRequest(DIRECTORY_PATH, std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("INSERT INTO " + table + "\nVALUES " + object + ";");
    SQLRequest.close();
}

void ORM::Update(std::string table, std::string objеct)
{
    if (!ConnectionDB(TEST_CONNECTION))
        throw "Connection is failed.";

    std::ofstream SQLRequest(DIRECTORY_PATH, std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("UPDATE " + table + "\nSET " + objеct + ";");
    SQLRequest.close();
}

bool ORM::ConnectionDB(std::string connection) // очень грубая заглушка
{
    return connection == "connectionMOCK";
}
