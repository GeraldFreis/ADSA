#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parser(std::string *);

int main()
{
    std::string line;
    std::cin >> line;
    std::vector<std::string> commands = parser(&line);
    
}

/*
Takes a string filled with spaces and stores the parts into a vector
Returns vector
*/
std::vector<std::string> parser(std::string *str)
{

}