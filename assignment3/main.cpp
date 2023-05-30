#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parser(std::string); // parses stdin into a vector because that's cute n shit

struct Pair {
    char key;
    std::string value;
};

class Table {
    private:
        Pair *entries;
        int index_counter;
        int findIndex(std::string val);
        int nextOpen(int val);
    public:
        Table();
        ~Table();
        
        void Insert(std::string val);
        void Delete(std::string val);
        void printTable();

};


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

Table::Table()
{
    this->index_counter = 0;
    this->entries = new Pair[26];
    // setting up each entry
    for(int i = 0; i < 26; i++){
        this->entries[i].key = 'a' + i;
        this->entries[i].value = "Never Used";
    }
}

/* Finding the index of this string in the table */
int Table::findIndex(std::string val)
{
    // so what we do is we take the last value as a key
    int value_index = int(val.at(val.size()-1) - 'a');
    // std::cout << value_index << "\n";
    // check that there exists a val in here
    if(this->entries[value_index].value == "Never Used") return -1; // we signify that nothing exists in the current spot by returning -1

    // checking that the value is the value
    if(this->entries[value_index].value == val) return value_index; // if the current val is the same as that we can return its value
    // else if it is not the required value we move down

    for(int i = value_index+1; i < 26; i++){
        if(this->entries[i].value == val) return i;
    }

    // wrapping around if we haven't found it
    for(int i = 0; i < value_index; i++){
        if(this->entries[i].value == val) return i;
    }
    return -1;
}

/*Formal Parameters: int index, returns the next available slot or -1 if table is full*/
int Table::nextOpen(int index){
    for(int i = index; i < 26; i++){
        if(this->entries[i].value == "Never Used"){return i;}
    }
    for(int i = 0; i < index; i++){
        if(this->entries[i].value == "Never Used"){return i;}
    }
    return -1; // if everything is occupied we will return -1
}

void Table::Insert(std::string val)
{
    int index = findIndex(val);
    if(index != -1) return;
    index = nextOpen(int(val.at(val.size()-1) - 'a'));
    this->entries[index].key = val.back();
    this->entries[index].value = val;

    this->index_counter++;
}

void Table::Delete(std::string val)
{
    // for deletions we restructure
    int index = findIndex(val);
    if(index == -1) return; // returning if value is not found
    this->entries[index].value = "Never Used";
    
}

void Table::printTable()
{
    int counter = 0;
    for(int i = 0; i < 26; i++){
        if(this->entries[i].value != "Never Used" && this->entries[i].value != "TombStone"){

            if(counter == 0){
                std::cout << this->entries[i].value; counter++;
            } else {
                std::cout << " " << this->entries[i].value;
            }
        }
    }
    std::cout << std::endl; // killing the buffer because I hate buffers
}



Table::~Table(){delete [] entries;}