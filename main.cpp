#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::vector<std::string> parser(std::string);
void executer(std::vector<std::string>);
void insert(int *, int, int);
void restructure(int *, int);
void leftRotation(int *, int);
void rightRotation(int *, int);

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> commands = parser(line);
    // for(auto command: commands) std::cout << command << "\n";
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
    for(auto a: given_commands) std::cout << a << " ";
    std::cout << "\n";
    int maxsize = std::pow(2, given_commands.size());
    int *array = new int[maxsize]; // an array to represent the tree (in order)
    for(int i = 0; i < given_commands.size(); i++){ array[i] = 0; }
    // left child is at 2n right is at 2n+1
    // if we correctly balance we should not go out of range
    for(auto command: given_commands){
        // checking the first value
        switch(command.at(0))
        {
            case 'A': // adding the values to the array
                insert(array, maxsize, std::stoi(command.substr(1,command.size())));

                // restructuring if neccessary
                restructure(array, maxsize);
                break;

            case 'D':
            // std::cout << "del\n";
                break;

            default: // means we hit the post or pre or in order command (print)
                break; 
        }
    } 
    // std::cout << "Before: ";
    // for(int i = 0; i < maxsize; i++){std::cout << array[i] << " ";}
    // std::cout << "\n";
    // restructure(array, maxsize);
    std::cout << "After: ";
    for(int i = 0; i < maxsize; i++){std::cout << array[i] << " ";}
    std::cout << "\n";
    delete [] array;
}

void insert(int *array, int len, int value){
    // do the usual BST insertion
    for(int i = 0; i < len; i++){
        if(array[i] != 0){
            if(value > array[i]){
                i = i*2+1;
            }
            else if(value < array[i]) { // no duplicates
                i = i*2;
            }
            else { return; } // returning if value == array[i]
        } else {
            array[i] = value;
            break;
        }
    }
}

void rightRotation(int *array, int unbalanced_index)
{
    // in a right rotation we really just change the positions of things on the right
    if(array[unbalanced_index*2+2] == 0){ // if the right child node of this node is empty
        int index = unbalanced_index;
        array[index*2+2] = array[index]; // moving the current node to its right child

        while(array[index*2+1] != 0) // while the left child of the current index is not zero
        {
            array[index] = array[index*2+1];
            index = index * 2 + 1; // index moves to the index of the left child
        }
        array[index] = 0; // ensuring the last place of the node moved goes back to being a zero

    } else { // if the right child node of this node is not empty

        int index = unbalanced_index;
        int temp = array[unbalanced_index];

        // moving the nodes on the right of the child down
        while(array[index*2+2] != 0)
        {
            int current = array[index*2+2];
            array[index*2+2] = temp;
            // std::cout << "temp: "  << temp << '\n';
            temp = current;
            index = index * 2 + 2;
        }

        array[index*2+2] = temp;
        index = unbalanced_index;

        // now there is space to move everything on the left up
        while(array[index*2+1] != 0)
        {
            array[index] = array[index*2+1];
            index = index * 2 + 1;
        }
        array[index] = 0;
        // now the array has been rotated
    }
}

void leftRotation(int *array, int unbalanced_index)
{
    if(array[unbalanced_index*2+1] == 0){ // if the left child node of this node is empty
        int index = unbalanced_index;
        array[index*2+1] = array[index]; // moving the current node to its left child

        while(array[index*2+2] != 0) // while the right child of the current index is not zero
        {
            array[index] = array[index*2+2];
            index = index * 2 + 2; // index moves to the index of the right child
        }
        array[index] = 0;

    } else { // if the left child node of this node is not empty

        int index = unbalanced_index;
        int temp = array[index*2+1];

        // moving the nodes on the right of the child down
        while(array[index*2+1] != 0)
        {
            int current = array[index*2+1];
            array[index*2+1] = temp;

            temp = current;
            index = index * 2 + 1;
        }

        array[index*2+1] = temp;
        
        index = unbalanced_index;
        // now there is space to move everything on the left up
        while(array[index*2+2] != 0)
        {
            array[index] = array[index*2+2];
            index = index * 2 + 2;
        }

        // now the array has been rotated
        array[index] = 0;
    }
}

int isBalanced(int *array, int len, int current_index)
{
    int i = current_index;
    int leftlen = 0, rightlen = 0;

    while(2*i + 2< len)
    {

        if(array[2 * i + 2] != 0) rightlen++;
        else {break;}

        if(i == 0){i=1;}
        else {i = i * 2 + 2;}
    }

    i = current_index;
    while(2*i+1 < len){
        if(array[2*i + 1] != 0) leftlen++;
        else {break;}
        if(i == 0){i=1;}
        else {i = i * 2 + 1;}
    }
    // std::cout << leftlen << " " << rightlen << "\n";
    // if(std::abs(leftlen - rightlen) >= 2){return false;}
    return leftlen-rightlen;
}

void restructure(int *array, int len){

    for(int i = 0; i < len; i++){
        if(array[i] != 0){
            int unb = isBalanced(array, len, i);
            if(unb >= 2){
                rightRotation(array, i);
                restructure(array, len);
            }
            else if(unb <= -1)
            {
                // std::cout << "here" << "\n";
                std::cout << "Before left rotation: ";
                for(int j  = i; j < len; j++){if(array[j] != 0) std::cout << array[j] << " ";}
                std::cout << std::endl;
                leftRotation(array, i);
                std::cout << "After left rotation: ";
                for(int j  = i; j < len; j++){if(array[j] != 0) std::cout << array[j] << " ";}
                std::cout << std::endl;
                restructure(array, len);

            }
        }
    }


}