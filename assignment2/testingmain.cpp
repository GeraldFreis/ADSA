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
    int val=-2; // by default -2
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
    // std::getline(std::cin, line); // taking the string as an input because I am cool and don't exist in a lucid dream
    line="A27 D9 D38 A10 A26 D80 D63 A73 D90 A77 A69 A95 D49 D30 A55 D42 D51 D6 D49 D41 A71 D48 D63 A31 A26 D80 D88 A18 D65 D51 A55 D41 A74 D7 D91 D22 A60 D76 A13 A36 D48 D67 A32 A25 D4 D40 A69 A79 D43 D35 A79 A19 D22 A15 D16 A81 D53 D77 A96 A30 A19 D41 A1 A88 A15 D67 D43 D69 D80 D11 A66 A36 D53 D55 A36 D66 A53 A8 D92 D73 D85 A19 A41 D59 D22 D11 A100 A66 A6 D69 A9 D61 A94 D95 D61 D96 D62 A79 A34 A67 PRE";
    std::vector<std::string> commands = parser(line);
    execute(commands); // executing
    std::cout << "\n";
    std::cout << "27 13 8 1 6 10 9 18 15 25 19 26 60 32 31 30 41 36 34 53 81 74 67 66 71 79 94 88 100\n\n";

    line="A76 D59 A69 D33 D8 D30 D54 D44 D36 D89 D38 A34 D64 A100 D60 D31 A92 D19 D98 A25 D16 A79 D16 A64 D81 D16 D38 D81 D82 D62 D46 D10 D15 D4 A73 A29 A79 D12 A36 A81 A55 A22 A92 A48 D42 D62 D51 A37 A10 A8 A96 D38 A94 D81 D63 A31 A70 D87 D88 D29 D61 D86 A90 A62 A1 D63 A10 A85 D89 A11 D65 D21 D39 A11 A88 D88 D70 D7 A12 D96 A99 A2 D48 A62 D48 A14 A26 D76 D79 A22 D55 D36 D35 A78 D76 D95 D29 D1 A2 A38 POST";
    commands = parser(line);
    
    execute(commands); // executing
    std::cout << "\n";
    std::cout << "8 2 11 14 12 25 31 26 22 10 38 37 64 62 78 73 69 90 94 100 99 92 85 34\n\n";

    line="A3 A22 D86 A67 A86 D66 D6 D51 D44 A63 D11 A75 A76 D89 D99 A36 A62 D90 D47 D90 A71 A7 D30 D63 D64 D57 A22 A46 D50 A14 D25 A41 A87 D25 D39 D40 A9 A38 A17 A100 A65 D94 D14 A98 D76 A45 A59 D8 A99 D97 D68 D7 A43 D33 D25 A26 D9 A68 D25 D9 A10 D25 A80 D44 D66 A60 D89 A45 D16 A85 A47 A63 A61 D98 D72 A95 D87 A39 A20 D22 A13 D22 A36 D36 D24 D36 A12 D27 A31 D75 A57 D39 D42 D26 D13 A41 A68 A8 D19 A61 POST";
    commands = parser(line);
    
    execute(commands); // executing
    std::cout << "\n";
    std::cout << "8 3 12 10 31 20 41 45 43 38 17 57 47 61 60 59 63 65 68 67 62 80 85 95 100 99 86 71 46\n\n";

    line="A40 A96 D52 A43 A65 A84 A25 A36 D42 A29 A86 A2 A4 D78 D33 D82 A40 A84 D41 D94 A79 D54 A8 A12 A46 D41 D29 A83 D49 A92 D93 D10 D3 D44 A45 A83 A39 A77 A13 A1 A46 A68 A9 D83 A76 D57 D55 D69 D78 D12 A75 A63 D75 D30 A3 D94 D5 A11 D90 A35 A22 A11 D58 A68 D75 A56 D94 D4 D59 A26 A27 A17 D71 D52 D40 D94 D83 D68 D92 A47 D24 D66 D98 D10 A77 A28 D27 D28 D68 D59 D35 A34 A99 A62 D90 D65 D31 A81 A76 A89 POST";
    commands = parser(line);
    
    execute(commands); // executing
    std::cout << "\n";
    std::cout << "1 2 8 3 11 17 22 13 34 26 39 36 25 9 45 47 46 62 56 77 76 81 84 89 99 96 86 79 63 43\n\n";

    line="D16 D13 A40 A61 A61 D1 A27 A60 A46 D11 D94 A86 D5 D72 D85 A20 D36 A20 A1 D80 A40 A15 A38 D75 A10 A5 D13 D38 A23 D21 D26 A73 A51 A41 A67 D71 D42 A70 A24 A24 D78 A46 D77 D48 A40 D69 D76 D9 D39 D21 D28 D1 D15 D7 D14 D54 D58 A39 A65 A71 D96 A7 D30 A24 D48 D15 D60 A94 A9 D82 D39 D65 A82 D94 D4 A51 D48 A95 D99 D57 D60 D78 A14 D45 A63 D53 D9 D7 D65 D15 A59 D99 D83 A44 D37 D2 A35 D69 A74 D49 PRE";
    commands = parser(line);
    
    execute(commands); // executing
    std::cout << "\n";
    std::cout << "40 20 10 5 14 24 23 27 35 67 51 44 41 46 61 59 63 73 70 71 86 82 74 95\n\n";

    line="D94 D55 D35 A88 D29 D64 A68 A34 D40 D54 D71 D82 A91 D85 A73 A96 A77 A82 D79 A16 A28 A96 D83 A78 A55 A31 D1 D37 D18 A45 A90 A8 A94 A62 A84 A45 A23 A73 A65 D88 A44 A10 D51 D84 D82 D8 A26 D10 A45 D8 D40 A98 A27 D99 A66 A25 D11 D98 D21 D8 D69 D57 D27 D11 A70 A44 D20 A17 A99 D28 A42 A34 A13 D3 D79 D52 A8 A22 D39 D41 A44 D14 A44 A62 A82 A32 D15 D62 A34 D56 D76 A74 A14 A32 A14 A43 A63 A41 A56 D40 PRE";
    commands = parser(line);
    
    execute(commands); // executing
    std::cout << "\n";
    std::cout << "55 26 16 13 8 14 23 17 22 25 34 31 32 44 42 41 43 45 77 68 65 63 56 66 73 70 74 91 82 78 90 96 94 99\n\n";

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
// here I calculate le balance
int calcBalance(Node *node){
    if(node == NULL || node == nullptr){return 0;}

    // finding the heights of the left and right nodes and returning the maximum
    int leftbal = calcBalance(node->left_child);
    int rightbal = calcBalance(node->right_child);

    return 1 + std::max(leftbal, rightbal);
}

// balancing with deletes and insert is slightly different so I have different functions because my girlfriend broke up with me on april the 24th of this year and its now april the 27th and our four year anniversary is in two weeks and I have already bought fairly expensive gifts and now I have to return them and I am pretty sad Im not going to lie. I am really struggling right now and I feel like I am drowning. I have so much uni work but I cant really focus. This is my third iteration of code. I have written two previous versions that both worked in my own tests but I think this version might be the winner. To be honest I am not sure if it will be but lets hope. I have spent an awful amount of time on this assignment and my first and second version used int arrays rather than node structures which made rebalancing easy but I think I would lose marks if I used them which is why i have rewritten my code now and its a big effort for me and I am not sure how I am going to cope. Its been two days now and I feel horrendous. Alongside the worst I have ever felt. It was just a punch in the guts because we went to tasmania a week prior for a week and it was really enjoyable. I was really happy. I struggle to be happy but for the past while I have been really happy. But now im sad again. 
Node *insertBalance(Node *parent, int value){
    // first we have to calculate the balance 
    // for that we use a cheeky function
    if(parent == NULL) return nullptr;

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
    if(parent == NULL) return nullptr;

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
    if(parent == NULL) return nullptr;

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
