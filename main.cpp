#include <iostream>
#include <string>

template <typename Model>
class IModelManager
{
public:
    Model All();
    Model Get(size_t object_id);
    Model Filter(Model filters[]);
    void Delete(Model object);
    void Create(Model object);
    virtual Model GetModelName() = 0;
    virtual Model GetDeafultModel() = 0;
};

class ORMGenerator
{
public:
    void *Generate();

private:
    void *GenerateFilters();
    void *GenerateModelManager();
    void *GenerateModels();
    void *FillModels();
}

class ORM
{
public:
    static void *Select(std::string table);
    static void *Filter(std::string table, std::string parameter);
    static void *Find(std::string table, std::string object_id);
    static void *Delete(std::string table, std::string object_id);
    static void *Insert(std::string table, std::string object);
    static void *Update(std::string table, std::string objtct);

private:
    static void *connection;
    static bool ConnectionDB();
    ORMGenerator;
};