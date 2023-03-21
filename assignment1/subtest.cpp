#include <iostream>
#include <string>


std::string intSubtraction(std::string a, std::string b);

int main(){
    std::string I1, I2, b, kara, addition;
    std::cin >> I1 >> I2 >> b;
    std::cout <<  intSubtraction(I1, I2) << '\n';
}

std::string intSubtraction(std::string a, std::string b){
    if(a.size() < 2 || b.size() < 2){return std::to_string(std::stoull(a)-std::stoul(b));}
    // definitions
    std::string larger, smaller, output="";
    int largern, smallern, i=0, j=0, carrydigit=0;
     std::cout << "Made it to subtractions\n";
    // setting required variables
    if(a.size() > b.size()) {larger = a; smaller = b; smallern = b.size()-1; largern = a.size()-1;}
    else if(a.size() == b.size()) {
        int allthesame = 0;
        for(int x = 0; x < static_cast<int>(a.size()); x++){
            if(a.at(x) > b.at(x)){
                larger = a; smaller = b;
                smallern = b.size()-1; largern = a.size()-1;
                break;
            } else if(a.at(x) < b.at(x)){
                smaller = a; larger = b;
                smallern = a.size()-1; largern = b.size()-1;
                break;
            } else if(a.at(x) == b.at(x)){
                allthesame++;
            }
        }
        if(allthesame == a.size()){
            return "0";
        }
    }
    else {larger = b; smaller = a; smallern = a.size()-1; largern = b.size()-1;} 
    
    std::cout << "made it through the swapping of the strings\n";
    // reversing the strings:
    std::cout << a << " " << b <<'\n';

    std::string reversed_larger="", reversed_smaller="";
    for(i = 0; i < static_cast<int>(largern+1); i++){reversed_larger += larger.at(largern-i);}
    
    for(i = 0; i < static_cast<int>(smallern+1); i++){reversed_smaller += smaller.at(smallern-i);}

    std::cout << "Made it to the while loop\n";
    std::cout << reversed_larger << " " << reversed_smaller <<'\n';
    i=0;
    while(smallern>i){
        // getting each digit
        int digit_smaller = reversed_smaller.at(i)-'0', digit_larger = reversed_larger.at(i)-'0';
        int val = digit_larger-digit_smaller-carrydigit;
        // std::cout << val << " " << digit_larger << " " << digit_smaller << " " << carrydigit << '\n';
        if(val < 0){carrydigit=1;
        output += val + 10 + '0';
        }
        else {output += val + '0'; carrydigit=0;} 
        i++;
        // std::cout << smallern - i << "\n";
        // std::cout << output << "\n";
    }

    std::cout << "made it through the while loop\n";
    for(int x = i; x <= static_cast<int>(largern); x++){
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
    std::cout << "made it to return\n\n";
    return newout;
}