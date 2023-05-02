#include <iostream>
#include <string>

struct Pair {
    char key;
    std::string value;
};

class Table {
    private:
        Pair *entries;
    public:
        Table();
        ~Table();
        int findIndex(std::string val);
        void Insert(std::string val);
        void Delete(std::string val);
};

Table::Table()
{
    this->entries = new Pair[26];
    // setting up each entry
    for(int i = 0; i < 26; i++){
        this->entries[i].key = 'a' + i;
    }
}

Table::~Table(){delete [] entries;}

int Table::findIndex(std::string val){
    // i know index will be at val.end - 'a' // because I'm smart
    return int(val.at(val.size()-1)- 'a');
}

void Table::Insert(std::string val){

}
void Table::Delete(std::string val){

}

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