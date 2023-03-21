#include <string>
#include <iostream>

std::string intSubtraction(std::string a, std::string b){
    // definitions
    std::string larger, smaller, output="";
    int largern, smallern, i=0, j=0, carrydigit=0;
     
    // setting required variables
    if(a.size() > b.size()) {larger = a; smaller = b; smallern = b.size()-1; largern = a.size()-1;}
    else if(a.size() == b.size()) {
        for(int x = 0; x < static_cast<int>(a.size()); x++){
            if(a.at(x) > b.at(x)){
                larger = a; smaller = b;
                smallern = b.size()-1; largern = a.size()-1;
                break;
            } else if(a.at(x) < b.at(x)){
                smaller = a; larger = b;
                smallern = a.size()-1; largern = b.size()-1;
                break;
            }
        }
    }
    else {larger = b; smaller = a; smallern = a.size(); largern = b.size();} 

    // reversing the strings:
    std::string reversed_larger="", reversed_smaller="";
    for(i = 0; i < static_cast<int>(largern); i++){reversed_larger += larger.at(largern-i);}
    for(i = 0; i < static_cast<int>(smallern); i++){reversed_smaller += smaller.at(smallern-i);}
    i=0;
    while(smallern - i > 0){
        // getting each digit
        int digit_smaller = reversed_smaller.at(i)-'0', digit_larger = reversed_larger.at(i)-'0';
        int val = digit_larger-digit_smaller-carrydigit;
        std::cout << val << " " << digit_larger << " " << digit_smaller << " " << carrydigit << '\n';
        if(val < 0){carrydigit=1;
        output += val + 10 + '0';}
        else {output += val + '0'; carrydigit=0;} 
        i++;
        // std::cout << smallern - i << "\n";
        std::cout << output << "\n";
    }

    for(int x = i; x < static_cast<int>(largern); x++){
        int val = (reversed_larger.at(x)-'0') - carrydigit;
        std::cout << val << "\n";
        if(val < 0){output += val + 10 + '0'; carrydigit=1;}
        else {output += val+'0'; carrydigit=0;} 
    }

    // reversing the final string (output)
    std::string newout="";
    for(int n = 0; n < static_cast<int>(output.size()); n++){
        newout += output.at(output.size()-1-n);
    }
    return newout;
}

int main(){
    std::cout << intSubtraction("168", "162");
}