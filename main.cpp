#include <iostream>
#include <string>

struct Entry {
    char key;
    std::string value;
};

class Table {
    private:
        Entry *entries;
        
};



int main(){ // doing everything at the same time as we receive the input
    std::string command;

    while(std::cin >> command){
        // for each command we just do what we want

        if(command.size() < 2) {return;} // base case
        if(command.at(0) == 'A'){ // if we have an addition

        }
        else if(command.at(0) == 'D'){ // if we have a deletion from the table

        }

    }

}