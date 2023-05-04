#include "DatabaseMOCK.hpp"

#include <iostream>
#include <string>
#include <fstream>

const std::string DIRECTORY_PATH = "../data/request.txt";

void DatabaseMOCK::execute(std::string request)
{
    std::ifstream requestSQL(DIRECTORY_PATH);

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