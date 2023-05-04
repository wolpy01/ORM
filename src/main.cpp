#include "ORM.hpp"
#include "DatabaseMOCK.hpp"
#include "ORMGenerator.hpp"
#include <cassert>

int main()
{
    ORM::Select("table");
    
    assert( == "The request is correct!");
    
    assert( == "The request is correct!");
    ORM::Delete("table", "1");
    assert( == "The request is correct!");
    
    assert( == "The request is correct!");
   
    assert( == "The request is correct!");
    return 0;
}
