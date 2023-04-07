#include <iostream>
#include <string>

#define MAXMODS 100

// node houses information about each thing
struct Node {
	Node *parent;
	Node *lefptr;
	Node *rightptr;
	uint8_t val;
}

// takes in current ptr and returns if it is balanced
bool isBalanced(Node *current_root);
// rotates left as neccessary
void leftRotate(Node *current_root);
// rotates right as neccessary
void rightRotate(Node *current_root);
// handles the rebalancing of the trees as necessary
void rebalance();
// handles inserting the node
void insertNode(Node *current_root);
// handles deleting the node
void deleteNode(Node *current_root);
// handles the commands as parsed in from STDIN
void handleCommands(char **commands, int n);
// prints tree in postorder
void postorder(Node *current_root);
// prints tree in preorder
void preorder(Node *current_root);
// prints tree in inorder
void inorder(Node *current_root);

int main(){
	// reading all commands in from stdin
	char *commandline[MAXMODS];
	int counter = 0, i = 0;
	for(i = 0; i < MAXMODS; i++){
		counter++;
		std::cin >> commandline[i];
	}

	// operating commands
	handleCommands(commandline, counter);
}

// takes in commands and number of commands as formal parameters
// function executes commands
void handleCommands(char **commands, int n)
{
	// approach: iterates through 	
}

