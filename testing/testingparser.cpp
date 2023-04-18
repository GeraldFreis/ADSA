#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parser(std::string *);

int main()
{
    std::string line;
    std::cin >> line;
    std::vector<std::string> commands = parser(&line);
    for(auto a: commands){
        std::cout << a << "\n";
    }
}

/*
Takes a string filled with spaces and stores the parts into a vector
Returns vector
*/
std::vector<std::string> parser(std::string *str)
{
    std::vector<std::string> commandies;
    std::string substr;
    for(int i = 0; i < str->size(); i++)
    {
        
        if(str->at(i) != ' ')
        {
            substr += str->at(i);
        } else {
            
        }
    }
}
