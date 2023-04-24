#include <iostream>
#include <string>
#include <vector>


struct Node{
    Node *leftpr;
    Node *rightptr;
    int val;
};

// this chromie homie brings joy to my little life
std::vector<std::string> parser(std::string);
void execute(std::vector<std::string>); // this hombre takes in the commandies and commands
void preTids(Node *); // prints stuff in preorder
void postTids(Node *); // prints stuff in postorder
void inTids(Node *); // prints stuf in order

int main() 
{
    std::string line;
    std::getline(std::cin, line); // taking the string as an input because I am cool and don't exist in a lucid dream

    std::vector<std::string> commands = parser(line);
    execute(commands); // executing
}

// parses things
std::vector<std::string> parser(std::string given_string)
{
    std::vector<std::string> commandies;
    std::string substr;
    for(int i = 0; i < given_string.size(); i++)
    {
        
        if(given_string.at(i) != ' ')
        {
            substr += given_string.at(i);
        } else {
            commandies.push_back(substr);
            substr = "";
        }
    }
    // there will be one more substring at the end of the line
    commandies.push_back(substr);

    return commandies;
}


void execute(std::vector<std::string> commandies)
{
    // i want to iterate through all little commandies except the last one (but maybe the last one)
    // We compile with g++11 which means I can use auto
    for(auto commands: commandies)
    {
        // we can use if statements (I like them more than switches)
        if(commands.at(0) == 'A') // if we need to add to the thingy
        {

        } else if(commands.at(0) == 'D') // if we need to delete to the thingy        
        {

        } else if(commands == "IN") // printing in order
        {

        } else if(commands == "PRE") // printing in pre order
        {

        } else if(commands == "POST") // printing in post order
        {

        }
    }
}

