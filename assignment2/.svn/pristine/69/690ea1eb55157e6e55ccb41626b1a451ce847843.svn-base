#include <iostream>
#include <string>
#include <vector>


struct Node{
    Node *leftptr;
    Node *rightptr;
    int val;
};

// this chromie homie brings joy to my little life
std::vector<std::string> parser(std::string);
void execute(std::vector<std::string>); // this hombre takes in the commandies and commands
void preTids(Node *); // prints stuff in preorder
void postTids(Node *); // prints stuff in postorder
void inTids(Node *); // prints stuf in order
void ins(Node *, int); // inserts a new node
void dels(Node *, int); // deletes a node if it exists (if not fuck you commie scum)
void balance(Node *);

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
    for(auto commands: commandies)
    {
        // we can use if statements (I like them more than switches)
        if(commands.at(0) == 'A') // if we need to add to the thingy
        {
            ins(headmaster, std::stoi(commands.substr(1, commands.size())));
            balance(headmaster);
        } else if(commands.at(0) == 'D') // if we need to delete to the thingy        
        {
            dels(headmaster, std::stoi(commands.substr(1, commands.size())));
            balance(headmaster);
        } else if(commands == "IN") // printing in order
        {

        } else if(commands == "PRE") // printing in pre order
        {

        } else if(commands == "POST") // printing in post order
        {

        }
    }
}
// I plop the val into an empty Node in the right place
void ins(Node *root, int value)
{
    if(root == NULL)
    {
        Node *thisbugger = new Node;
        thisbugger->val = value;
        thisbugger->leftptr = NULL;
        thisbugger->rightptr = NULL;
    } else if(root->val < value && root->val != value) // if the current value is > the nodes val
    {
        ins(root->rightptr, value); // recursively inserting my nuts in your mouth
    } else if(root->val > value && root->val != value)
    {
        ins(root->leftptr, value);
    } else if(root->val == value){return;}
}

void dels(Node *root, int value)
{
    // base case
    if(root == NULL) return; 
    if(root->val == value) // deleting is not fun
    {
        // if we have a left child but no right child
        if(root->leftptr != NULL && root->rightptr == NULL)
        {
            root = root->leftptr; 
        } else if(root->rightptr != NULL && root->leftptr == NULL) // if we have a right child but no left
        {
            root = root->rightptr;
        } else { // if we have both children
            // make the current value the right hand value
        }

    }
}