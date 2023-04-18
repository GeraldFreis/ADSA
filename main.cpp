#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parser(std::string);
void executer(std::vector<std::string>);

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> commands = parser(line);
    for(auto command: commands) std::cout << command << "\n";
    executer(commands);
}

std::vector<std::string> parser(std::string str)
{
    std::vector<std::string> commandies;
    std::string substr;
    for(int i = 0; i < str.size(); i++)
    {
        
        if(str.at(i) != ' ')
        {
            substr += str.at(i);
        } else {
            commandies.push_back(substr);
            substr = "";
        }
    }
    // there will be one more substring at the end of the line
    commandies.push_back(substr);

    return commandies;
}

// function to take the commands and execute them 
void executer(std::vector<std::string> given_commands)
{
   int *array = new int[given_commands.size()]; // an array to represent the tree (in order)
   // left child is at 2n right is at 2n+1
   // if we correctly balance we should not go out of range
    int index = 0;
    for(auto command: given_commands){
        // checking the first value
        switch(command.at(0))
        {
            case 'A': // adding the values to the array
                array[index] = std::stoi(command.substr(1,command.size()));
                // std::cout << array[index] << "\n";
                index++;

                // restructuring if neccessary
                break;

            case 'D':
            // std::cout << "del\n";
                break;

            default: // means we hit the post or pre or in order command (print)
                break; 
        }
    } 
    delete [] array;
}