#pragma once
#include <iostream>

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