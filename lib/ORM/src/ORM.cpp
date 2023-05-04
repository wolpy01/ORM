#include "ORM.hpp"

#include <iostream>
#include <string>
#include <fstream>

ORM::static void Select(std::string table)
{
    if (!ConnectionDB("connection_MOCK"))
        throw EXIT_FAILURE;

    std::ofstream SQLRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("SELECT *\nFROM " + table + ";");
    SQLRequest.close();

    DatabaseMOCK::execute("SELECT *\nFROM table;");
}

ORM::static void Filter(std::string table, std::string parameter)
{
    if (!ConnectionDB("connection_MOCK"))
        throw EXIT_FAILURE;

    std::ofstream SQLRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("SELECT *\nFROM " + table + " WHERE " + parameter + ";");
    SQLRequest.close();

    DatabaseMOCK::execute("SELECT *\nFROM table WHERE predicate;");
}

ORM::static void Find(std::string table, std::string object_id)
{
    if (!ConnectionDB("connection_MOCK"))
        throw EXIT_FAILURE;

    std::ofstream SQLRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("SELECT *\nFROM " + table + " WHERE object_id = " + object_id + ";");
    SQLRequest.close();

    DatabaseMOCK::execute("SELECT *\nFROM table WHERE object_id = 1;");
}

ORM::static void Delete(std::string table, std::string object_id)
{
    if (!ConnectionDB("connection_MOCK"))
        throw EXIT_FAILURE;

    std::ofstream SQLRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("DELETE *\nFROM " + table + " WHERE object_id = " + object_id + ";");
    SQLRequest.close();

    DatabaseMOCK::execute("DELETE *\nFROM table WHERE object_id = 1;");
}

ORM::static void Insert(std::string table, std::string object)
{
    if (!ConnectionDB("connection_MOCK"))
        throw EXIT_FAILURE;

    std::ofstream SQLRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("INSERT INTO " + table + "\nVALUES " + object + ";");
    SQLRequest.close();

    DatabaseMOCK::execute("INSERT INTO table\nVALUES object;");
}

ORM::static void Update(std::string table, std::string objеct)
{
    if (!ConnectionDB("connection_MOCK"))
        throw EXIT_FAILURE;

    std::ofstream SQLRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
    SQLRequest << ("UPDATE " + table + "\nSET " + objеct + ";");
    SQLRequest.close();

    DatabaseMOCK::execute("UPDATE table\nSET object;");
}

ORM::static bool ConnectionDB(std::string connection) //заглушка, в дальшейшем надо по-другому реализовать
{
    return DatabaseMOCK::ping_connection(connection);
}
