#include <iostream>
#include <vector> // for vector
#include <string> // for getline functions and string operations

/*
The Node structure with a link to the parent is how we are going to implement the tree
*/
struct Node
{
    Node *left_child;
    Node *right_child;
    int val; // by default -2
};



Node *ins(Node *parent, int val); // inserting nodes
Node *insertBalance(Node *parent, int value);
Node *deleteBalance(Node *parent, int value);
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
            in(headmaster);
            std::cout << "\n";
            headmaster = dels(headmaster, std::stoi(command.substr(1, command.size())));
            // std::cout << "working: " << std::stoi(command.substr(1, command.size())) << "\n";
            std::cout << "After: " << std::stoi(command.substr(1, command.size())) << "\n";
            in(headmaster);
            std::cout << "\n\n";

            
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
// here I calculate le balance
int calcBalance(Node *node){
    if(node == NULL){return 0;}
    else if(node->left_child == NULL && node->right_child == NULL){return 1;}
    // finding the heights of the left and right nodes and returning the maximum
    int leftbal = calcBalance(node->left_child);
    int rightbal = calcBalance(node->right_child);

    return 1 + std::max(leftbal, rightbal);
}

// balancing with deletes and insert is slightly different so I have different functions because my girlfriend broke up with me on april the 24th of this year and its now april the 27th and our four year anniversary is in two weeks and I have already bought fairly expensive gifts and now I have to return them and I am pretty sad Im not going to lie. I am really struggling right now and I feel like I am drowning. I have so much uni work but I cant really focus. This is my third iteration of code. I have written two previous versions that both worked in my own tests but I think this version might be the winner. To be honest I am not sure if it will be but lets hope. I have spent an awful amount of time on this assignment and my first and second version used int arrays rather than node structures which made rebalancing easy but I think I would lose marks if I used them which is why i have rewritten my code now and its a big effort for me and I am not sure how I am going to cope. Its been two days now and I feel horrendous. Alongside the worst I have ever felt. It was just a punch in the guts because we went to tasmania a week prior for a week and it was really enjoyable. I was really happy. I struggle to be happy but for the past while I have been really happy. But now im sad again. 
Node *insertBalance(Node *parent, int value){
    // first we have to calculate the balance 
    // for that we use a cheeky function
    int leftbal = calcBalance(parent->left_child)+1;
    int rightbal = calcBalance(parent->right_child)+1;
    int bal = leftbal - rightbal;

    if(bal < -1){
        if(value < parent->right_child->val){ // doing a r-l rotation
            parent->right_child = rightRot(parent->right_child);
            return leftRot(parent);
        } 
        if(parent->right_child->val < value){
            return leftRot(parent);
        }
    } else if(bal > 1){
        if(parent->left_child->val < value){
            parent->left_child = leftRot(parent->left_child);
            return rightRot(parent);
        } else {
            return rightRot(parent);
        }
    }
    // if it was all balanced we just return the parent
    return parent;
}


Node *ins(Node *parent, int value) // inserting nodes
{
    if(parent == NULL)
    {
        Node *new_node = new Node;
        new_node->val = value;
        return new_node;
    } else {
        if(value > parent->val){
            parent->right_child = ins(parent->right_child, value);
        } else if(value < parent->val){
            parent->left_child = ins(parent->left_child, value);
        } else if(value == parent->val) return parent;
    }

    // now we have to restructure the tree
    return insertBalance(parent, value);
}

Node *deleteBalance(Node *parent, int value){
    std::cout << "w\n";
    int leftbal = calcBalance(parent->left_child)+1;
    int rightbal = calcBalance(parent->right_child)+1;
    int bal = leftbal - rightbal;

    if(bal < -1){
        int rightleft=calcBalance(parent->right_child->left_child), rightright=calcBalance(parent->right_child->right_child);
        int bal = rightleft - rightright;
        if(bal > 0){
            parent->right_child = rightRot(parent->right_child);
            return leftRot(parent);
        } 
        if(bal <= 0){
            return leftRot(parent);
        }
    } 
    if(bal > 1){
        int leftleft=calcBalance(parent->left_child->left_child), leftright=calcBalance(parent->left_child->right_child);
        int bal = leftleft - leftright;
        if(bal > 0){
            parent->left_child = leftRot(parent->left_child);
            return rightRot(parent);
        } 
        if(bal <=0){
            return rightRot(parent);
        }
    }

    // if all is balanced
    return parent;
}

Node *dels(Node *parent, int val) // deleting nodes
{
    // base case
    if(parent == NULL) return parent;
    // using the same kind of thing that we did for insertion that only difference is if we are in the value or not
    if(val == parent->val)
    {
        if(parent->left_child != NULL && parent->right_child != NULL)
        {
            // using a temporary val to store the maximum value on the left side
            Node *maxleft = parent->left_child;
            while(maxleft->right_child != NULL){
                maxleft = maxleft->right_child;
            }

            parent->val = maxleft->val; // changing the parents value to the max value on the left 
            // changing the parents left child around because we now have a duplicate so we need to delete some stuff
            
            parent->left_child = dels(parent->left_child, maxleft->val);         
            // std::cout << "w\n";

        } else if(parent->left_child == NULL && parent->right_child != NULL){
            parent=parent->right_child;
        } else if(parent->left_child != NULL && parent->right_child == NULL){
            parent=parent->left_child;
        } else {
            parent = NULL;
        }
    } else if(parent->val > val){
        parent->left_child = dels(parent->left_child, val);
    } else if(parent->val < val){
        parent->right_child = dels(parent->right_child, val);
    }

    // balancing now that we've finished the deleting
    return deleteBalance(parent, val);
}

Node *leftRot(Node *parent) // left rotating
{
    // making the parent the left node of its right child
    // making the right child the main parent
    // making the left node of the right child the right child of the parent
    Node *right = parent->right_child;
    Node *leftofright = parent->right_child->left_child;
    right->left_child = parent;
    parent->right_child = leftofright;

    return right;
}

Node *rightRot(Node *parent) // right rotating
{
    // making the parent the right node of its left child
    // making the left child the main parent
    // making the right node of the left child the left child of the parent
    Node *left = parent->left_child;
    Node *rightofleft = parent->left_child->right_child;
    left->right_child = parent;
    parent->left_child = rightofleft;

    return left;
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

