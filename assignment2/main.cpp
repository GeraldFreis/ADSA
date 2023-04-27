#include <iostream>
#include <string>
#include <vector>


struct Node{
    Node *leftptr = NULL;
    Node *rightptr = NULL;
    int val=0;
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
    Node *headmaster = new Node;
    for(auto command: commandies)
    {
        // we can use if statements (I like them more than switches)
        if(command.at(0) == 'A') // if we need to add to the thingy
        {
            ins(headmaster, std::stoi(command.substr(1, command.size())));
            balance(headmaster);
        } else if(command.at(0) == 'D') // if we need to delete to the thingy        
        {
            dels(headmaster, std::stoi(command.substr(1, command.size())));
            balance(headmaster);
        } else if(command == "IN") // printing in order
        {
            inTids(headmaster);
        } else if(command == "PRE") // printing in pre order
        {
            preTids(headmaster);
        } else if(command == "POST") // printing in post order
        {
            postTids(headmaster);
        }   
    }
}

/*
Calculating the balance for each ball balanced on your jugular
(left scrote - right scrote)
*/
int calc_balance(Node *root)
{
    // finding the length of all nodes on the left 
    Node *temp = root;
    int left_counter=0, right_counter=0; 

    while(true)
    {
        if(temp->leftptr == NULL) break;
        else {left_counter++; temp=temp->leftptr;}
    }

    temp = root;
    while(true)
    {
        if(temp->rightptr == NULL) break;
        else {right_counter++; temp=temp->rightptr;}
    }

    return left_counter - right_counter;
}

void left_rot(Node *root)
{
    // we get the right node and rotate it and reset the root->right
    Node *right_node = root->rightptr;
    Node *left_temp = root->rightptr->leftptr;
    root->rightptr = left_temp;
    right_node->leftptr = root;
    root = right_node;
}

void right_rot(Node *root)
{
    Node *left_node = root->leftptr;
    Node *right_temp = root->leftptr->rightptr;
    root->leftptr = right_temp;
    left_node->leftptr = root;
    root=left_node;
}

/*
Balance these balls on your jugular
*/
void balance(Node *root)
{
    // we need to calculate the balance of each node and their children
    if(root == NULL){return;}

    Node *temp = root;
    while(temp->leftptr != NULL){
        int bal = calc_balance(temp->leftptr);
        if(bal < -1 && (temp->leftptr->val > temp->leftptr->rightptr->val)){
            left_rot(temp->leftptr);
        } else if (bal < -1 && (temp->leftptr->val < temp->leftptr->rightptr->val)){
            left_rot(temp->leftptr);
            right_rot(temp->leftptr);
        } else if(bal > 1 && (temp->leftptr->val > temp->leftptr->rightptr->val)){
            right_rot(temp->leftptr);
        } else if(bal > 1 && (temp->leftptr->val < temp->leftptr->rightptr->val)){
            right_rot(temp->leftptr);
            left_rot(temp->leftptr);
        }
        temp=temp->leftptr;
    }
    temp=root;
    while(temp->rightptr != NULL){
        int bal = calc_balance(temp->rightptr);
        if(bal < -1 && (temp->rightptr->val > temp->rightptr->rightptr->val)){
            left_rot(temp->rightptr);
        } else if (bal < -1 && (temp->rightptr->val < temp->rightptr->rightptr->val)){
            left_rot(temp->rightptr);
            right_rot(temp->rightptr);
        } else if(bal > 1 && (temp->rightptr->val > temp->rightptr->rightptr->val)){
            right_rot(temp->rightptr);
        } else if(bal > 1 && (temp->rightptr->val < temp->rightptr->rightptr->val)){
            right_rot(temp->rightptr);
            left_rot(temp->rightptr);
        }

        temp = temp->rightptr;
    }
}
// I plop the val into an empty Node in the right place
void ins(Node *root, int value)
{
    if(root->leftptr == NULL && root->rightptr == NULL && root->val == 0) // empty 
    {
        root->val = value;
        root->leftptr = new Node;
        root->rightptr = new Node;

    } else if(root->val < value && root->val != value) // if the current value is > the nodes val
    {
        ins(root->rightptr, value); // recursively inserting my nuts in your mouth

    } else if(root->val > value && root->val != value)
    {
        ins(root->leftptr, value);
    } else if(root->val == value){return;}
}
/*
Takes in a value to delete in the tree and the root node and removes that value from the tree
*/
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
            // make the current value the right most value
            Node *temp_node = root;
            while(true){
                if(temp_node->rightptr == NULL && temp_node->leftptr == NULL){
                    root->val = temp_node->val;
                    // now we can recursively delete that node that we just moved
                    dels(root->rightptr, temp_node->val);
                    break;
                } else {
                    temp_node = temp_node->rightptr; // chugging along the chain
                }
            }

        }
    }
}

void preTids(Node *this_node) // pre order
{
    if(this_node == NULL || this_node->val == 0){return;} // base case 
    std::cout << this_node->val << " ";

    if(this_node->leftptr != NULL){ // going over left side
        preTids(this_node->leftptr);
    }
    if(this_node->rightptr != NULL){
        preTids(this_node->rightptr);
    }
} 
void postTids(Node *this_node) // prints stuff in postorder
{
    if(this_node == NULL || this_node->val == 0){return;} // base case

    if(this_node->leftptr != NULL){postTids(this_node->leftptr);}
    
    if(this_node->rightptr != NULL){postTids(this_node->rightptr);}
    std::cout << this_node->val << " ";
}
void inTids(Node *this_node) // prints stuf in order
{
    if(this_node == NULL || this_node->val == 0){return;} // base case
    // std::cout << this_node->val << " ";
    if(this_node->leftptr != NULL){inTids(this_node->leftptr);}
    std::cout << this_node->val << " ";
    if(this_node->rightptr != NULL){inTids(this_node->rightptr);}
}