#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parser(std::string);
void executer(std::vector<std::string>);
void insert(int *, int, int);
void restructure(int *, int);

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
   int *array = new int[given_commands.size()*2]; // an array to represent the tree (in order)
   for(int i = 0; i < given_commands.size(); i++){array[i] = 0;}
   // left child is at 2n right is at 2n+1
   // if we correctly balance we should not go out of range
    for(auto command: given_commands){
        // checking the first value
        switch(command.at(0))
        {
            case 'A': // adding the values to the array
                insert(array, given_commands.size(), std::stoi(command.substr(1,command.size())));
                // restructuring if neccessary

                break;

            case 'D':
            // std::cout << "del\n";
                break;

            default: // means we hit the post or pre or in order command (print)
                break; 
        }
    } 
    for(int i = 0; i < given_commands.size()*2; i++){
        std::cout << array[i] << "\n";
    }
    delete [] array;
}

void insert(int *array, int len, int value){
    // do the usual BST insertion
    for(int i = 0; i < len; i++){
        if(array[i] != 0){
            if(value > array[i]){
                i = i*2+1;
            }
            else {
                i = i*2;
            }
        } else {
            array[i] = value;
            break;
        }
    }
}

bool isBalanced(int *array, int len, int current_index)
{
    int i = current_index;
    int leftlen = 0, rightlen = 0;
    
    while(2*i < len)
    {
        if(array[2*i] != 0) leftlen++;
        else {break;}
        i *= 2;
    }

    i = current_index;
    while(2*i + 1 < len){
        if(array[2*i + 1] != 0) rightlen++;
        else {break;}
        i = i * 2 + 1;
    }

    if(std::abs(leftlen - rightlen) >= 2){return false;}
    return true;
}

void restructure(int *array, int len){

}