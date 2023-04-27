#include <iostream>
#include <vector> // for vector
#include <string> // for getline functions and string operations

/*
The Node structure with a link to the parent is how we are going to implement the tree
*/
struct Node
{
    Node *left_child = nullptr;
    Node *right_child = nullptr;
    Node *parent = nullptr;
    int val=-2; // by default -2
};



Node *ins(Node *parent, int val); // inserting nodes
Node *dels(Node *parent, int val); // deleting nodes
Node *leftRot(Node *parent); // left rotating
Node *rightRot(Node *parent); // right rotating
void in(Node *parent); // printing inorder
void pre(Node *parent); // printing preorder
void post(Node *parent); // printing postorder
void execute(std::vector<std::string> commandiess); // executing everything
std::vector<std::string> parser(std::string given_string); // parsing the commands

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
    Node *headmaster = NULL;
    for(auto command: commandies)
    {
        // we can use if statements (I like them more than switches)
        if(command.at(0) == 'A') // if we need to add to the thingy
        {
            headmaster = ins(headmaster, std::stoi(command.substr(1, command.size())));
        } else if(command.at(0) == 'D') // if we need to delete to the thingy        
        {
            headmaster = dels(headmaster, std::stoi(command.substr(1, command.size())));
        } else if(command == "IN") // printing in order
        {
            in(headmaster);
        } else if(command == "PRE") // printing in pre order
        {
            pre(headmaster);
        } else if(command == "POST") // printing in post order
        {
            post(headmaster);
        }   
    }
}

Node *ins(Node *parent, int val) // inserting nodes
{

}

Node *dels(Node *parent, int val) // deleting nodes
{

}

Node *leftRot(Node *parent) // left rotating
{

}

Node *rightRot(Node *parent) // right rotating
{

}

void in(Node *parent) // printing inorder
{
    if(parent == NULL) return;
    else if(parent != NULL){
        in(parent->left_child);
        std::cout << parent->val << " ";
        in(parent->right_child);
    }
}

void pre(Node *parent) // printing preorder
{
    if(parent == NULL) return;
    else if(parent != NULL){      
        std::cout << parent->val << " ";
        pre(parent->left_child);
        pre(parent->right_child);
    }

}

void post(Node *parent) // printing postorder
{
    if(parent == NULL) return;
    else if(parent != NULL){
        post(parent->left_child);
        post(parent->right_child);
        std::cout << parent->val << " ";
    }

}

