#include <iostream>
#include <string>
#include <vector>

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
    int corresponding_index = int(val.at(val.size()-1)- 'a');
    if(this->entries[corresponding_index].value == val){return corresponding_index;}
    // we know that we are going to need to wrap around
    int current_index = corresponding_index+1;
    while(current_index < 26){
        if(this->entries[current_index].value == val){return current_index;}
        current_index++;
    }
    // going back through the top of the list
    for(int i = 0; i < corresponding_index; i++){
        if(this->entries[i].value == val){return i;}
    }
    return -1; // was not found
}

void Table::Insert(std::string val){
    int corresponding_index = findIndex(val);
    if(corresponding_index == -1)
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

std::vector<std::string> parser(std::string given_string)
{
    std::vector<std::string> commandies;
    if(given_string.size() < 2) {return commandies;}
    std::string substr="";
    for(int i = 0; i < static_cast<int>(given_string.size()); i++)
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
    if(substr.size() > 1){
        commandies.push_back(substr);
    }

    return commandies;
}

int main(){ // doing everything at the same time as we receive the input
    std::string commands;
    Table tab;
    std::getline(std::cin, commands);
    for(auto command: parser(commands)){ // for each command
        if(command.at(0) == 'A'){
            tab.Insert(command.substr(1, command.size()));
        } else if(command.at(0) == 'D'){
            tab.Delete(command.substr(1, command.size()));
        }
    }
    tab.printTable();
}