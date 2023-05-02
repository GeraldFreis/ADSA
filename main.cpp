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
        void printTable();
};

Table::Table()
{
    this->entries = new Pair[26];
    // setting up each entry
    for(int i = 0; i < 26; i++){
        this->entries[i].key = 'a' + i;
        this->entries[i].value = "Never Used";
    }
}

Table::~Table(){delete [] entries;}

int Table::findIndex(std::string val){
    // i know index will be at val.end - 'a' // because I'm smart
    return int(val.at(val.size()-1)- 'a');
}

void Table::Insert(std::string val){
    int corresponding_index = findIndex(val);
    if(entries[corresponding_index].value == "Never Used"){ // if the index is never used
        entries[corresponding_index].value = val;
    }
}
void Table::Delete(std::string val){
    int corresponding_index = findIndex(val);
    if(entries[corresponding_index].value != "Never Used"){ // if the index is never used
        entries[corresponding_index].value = "0";
    }
}

void Table::printTable(){
    for(int i = 0; i < 26; i++){
        if(entries[i].value == "0" || entries[i].value == "Never Used"){
            continue;
        } else {
            std::cout << entries[i].value << " ";
        }
    }
}

int main(){ // doing everything at the same time as we receive the input
    std::string command="";
    Table tab;
    while(command != "\n" && command != "\0"){
        // for each command we just do what we want
        std::cin >> command;
        if(command.size() < 2) {return;} // base case

        if(command.at(0) == 'A'){ // if we have an addition
            tab.Insert(command.substr(1, command.size()));
        }
        else if(command.at(0) == 'D'){ // if we have a deletion from the table
            tab.Delete(command.substr(1, command.size()));
        }

    }

}