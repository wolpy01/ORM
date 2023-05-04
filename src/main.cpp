#include <iostream>
#include <string>
#include <fstream>

template <typename Model>
class IModelManager
{
public:
    virtual Model All() = 0;
    virtual Model Get(size_t object_id) = 0;
    virtual Model Filter(Model filters_object) = 0;
    virtual void Delete(Model object) = 0;
    virtual void Insert(Model object) = 0;
    virtual Model GetModelName() = 0;
    virtual Model GetDeafultModel() = 0;
};

class ORMGenerator
{
public:
    void Generate();

private:
    const std::string JSON_model_file;
    void GenerateFilters();
    void GenerateModelManager();
    void GenerateModels();
    // void FillModels(); to do (сделаем, если успеем, к концу)
};

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
        std::cout << (request == request_text);
    }
};

class ORM
{
public:
    static void Select(std::string table)
    {
        if (!ConnectionDB("connection_MOCK"))
            throw EXIT_FAILURE;

        std::ofstream SelectRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
        SelectRequest << ("SELECT *\nFROM " + table + ";");
        SelectRequest.close();

        DatabaseMOCK::execute("SELECT *\nFROM table;");
    }
    static void Filter(std::string table, std::string parameter);

    static void Find(std::string table, std::string object_id)
    {
        if (!ConnectionDB("connection_MOCK"))
            throw EXIT_FAILURE;

        std::ofstream SelectRequest("../data/request.txt", std::ofstream::out | std::ofstream::trunc);
        SelectRequest << ("SELECT *\nFROM " + table + " WHERE object_id = " + object_id + ";");
        SelectRequest.close();

        DatabaseMOCK::execute("SELECT *\nFROM table WHERE object_id = 1;");
    };
    static void Delete(std::string table, std::string object_id);
    static void Insert(std::string table, std::string object);
    static void Update(std::string table, std::string objеct);

private:
    static bool ConnectionDB(std::string connection)
    {
        return DatabaseMOCK::ping_connection(connection);
    }
};

int main()
{
    ORM::Find("table", "1");
    return 0;
}
