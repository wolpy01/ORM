#include "ORM.hpp"
#include "DatabaseMOCK.hpp"
#include "ORMGenerator.hpp"

int main()
{
    ORM::Select("table");
    DatabaseMOCK::execute("SELECT *\nFROM table;");
    ORM::Filter("table", "predicate");
    DatabaseMOCK::execute("SELECT *\nFROM table WHERE predicate;");
    ORM::Find("table", "1");
    DatabaseMOCK::execute("SELECT *\nFROM table WHERE object_id = 1;");
    ORM::Insert("table", "object");
    DatabaseMOCK::execute("DELETE *\nFROM table WHERE object_id = 1;");
    ORM::Delete("table", "1");
    DatabaseMOCK::execute("INSERT INTO table\nVALUES object;");
    ORM::Update("table", "object");
    DatabaseMOCK::execute("UPDATE table\nSET object;");
    return 0;
}
