#include "ORM.hpp"
#include "DatabaseMOCK.hpp"
#include "ORMGenerator.hpp"
#include <cassert>

int main()
{
    ORM::Select("table");
    assert(DatabaseMOCK::execute("SELECT *\nFROM table;") == "The request is correct!");
    ORM::Filter("table", "predicate");
    assert(DatabaseMOCK::execute("SELECT *\nFROM table WHERE predicate;") == "The request is correct!");
    ORM::Find("table", "1");
    assert(DatabaseMOCK::execute("SELECT *\nFROM table WHERE object_id = 1;") == "The request is correct!");
    ORM::Delete("table", "1");
    assert(DatabaseMOCK::execute("DELETE *\nFROM table WHERE object_id = 1;") == "The request is correct!");
    ORM::Insert("table", "object");
    assert(DatabaseMOCK::execute("INSERT INTO table\nVALUES object;") == "The request is correct!");
    ORM::Update("table", "object");
    assert(DatabaseMOCK::execute("UPDATE table\nSET object;") == "The request is correct!");
    return 0;
}
