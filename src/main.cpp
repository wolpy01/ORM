#include <ORM.hpp>
#include <ORMGenerator.hpp>

#include <iostream>
#include <string>
#include <fstream>

class DatabaseMOCK
{
public:
    static bool ping_connection(std::string test_connection)
    {
        return test_connection == "connection_MOCK";
    }
    static void execute(std::string request)
    {
        std::ifstream requestSQL("../data/request.txt");

        if (requestSQL.bad())
            throw EXIT_FAILURE;

        std::string request_text = "";
        while (!requestSQL.eof())
        {
            std::string fileline;
            getline(requestSQL, fileline);
            request_text += fileline;
            if (!requestSQL.eof())
                request_text += '\n';
        }
        requestSQL.close();
        if (request == request_text)
            std::cout << "The request is correct!" << std::endl;
        else
            std::cout << "The request isn't correct!" << std::endl;
    }
};

int main()
{
    ORM::Select("table");
    ORM::Filter("table", "predicate");
    ORM::Find("table", "1");
    ORM::Insert("table", "object");
    ORM::Delete("table", "1");
    ORM::Update("table", "object");
    return 0;
}
