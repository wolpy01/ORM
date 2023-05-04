#pragma once
#include <string>
#include <fstream>

class DatabaseMOCK
{
public:
    static std::string execute(std::string &&request);
};