
#include <iostream>
#include <string>
#include <vector>

// defining the functions that are implemented
std::string karatsuba(std::string a, std::string b, int base);
std::string intAddition(std::string n1, std::string n2, int base);
std::string intSubtraction(std::string a, std::string b);

// main function to run and take all inputs from the files
int main(){
    std::string I1, I2, kara, addition;
    int b;
    std::cin >> I1 >> I2 >> b;

    std::cout << intAddition(I1, I2, b) << "\t" << karatsuba(I1, I2, b) << " " << 0 << "\n"; 
    std::cout << "2420110111420234154241430052433145304554533102512015222\n";
}

// implementation of the karatsuba multiplcation algorithm
std::string karatsuba(std::string a, std::string b, int base)
{
    // std::cout << "\n\n Made it to first part\n";
    if(a.size() < 3 || b.size() < 3) return std::to_string(std::stoull(a) * std::stoull(b)); // problem here is that we might cop an out of range
    
    std::string p_1, p_2, p_3, p, a_0, b_0, a_1, b_1;

    a_1 = a.at(0); for(int i = 0; i < static_cast<int>(a.size()/2); i++){a_1 += a.at(i);}
    b_1 = b.at(0); for(int i = 0; i < static_cast<int>(b.size()/2); i++){b_1 += b.at(i);}
    a_0 = a.at(int(a.size()/2)); for(int i = static_cast<int>(a.size()/2 + 1); i < static_cast<int>(a.size()); i++){a_0 += a.at(i);}
    b_0 = a.at(int(a.size()/2));  for(int i = static_cast<int>(a.size()/2 + 1); i < static_cast<int>(a.size()); i++){b_0 += a.at(i);}
    // std::cout << "Made it to second part\n";

    // std::cout << "Made it this far" << "\n";
    p_1 = karatsuba(a_1, b_1, base); 
    p_3 = karatsuba(a_0, b_0, base);
    std::cout << "p_1 = " << p_1 << " p_3 = " << p_3 << "\n";

    p_2 = karatsuba((intAddition(a_1, a_0, base)), intAddition(b_1, b_0, base), base);
    // std::cout << p_2 << "-";
    std::cout << "p_2 = " << p_2 << " - " << p_1 << " - " << p_3 <<'\n';

    p_2 = intSubtraction(p_2, p_1); 
    // std::cout << p_1 << "=" << p_2 << "\n";
    p_2 = intSubtraction(p_2, p_3);
    std::cout <<"p_2 = " << p_2 <<"\n";

    for(int i = 0; i < static_cast<int>(a.size()); i++){p_1 += "0";}
    for(int i = 0; i < static_cast<int>(a.size()/2-1); i++){p_2 += "0";}

    p = intAddition(p_1, p_2, base); p = intAddition(p, p_3, base);

    return p;
}

// implementation of the school method of integer arithmetic
std::string intAddition(std::string n1, std::string n2, int base)
{
    // initialising all variables that are going to be used
    std::string smallerstr, largerstr, sum="", newsum="";
    int str1size=(n1.size()-1), str2size=(n2.size()-1), last_digit = 1;
    int i=0, j=0, larger, smaller, carry=0;

    // std::cout << n1 << " " << n2 << "\n";
    
    if(str1size > str2size){
        larger = str1size; largerstr = n1;
        smaller = str2size; smallerstr = n2;
    } else if(str1size == str2size){
        larger = str1size; smaller = str1size;
        largerstr = n1; smallerstr = n2;
    } else {
        larger = str2size; largerstr = n2;
        smaller = str1size; smallerstr = n1;
    }
    

    while(larger - i >= 0)
    {
        // std::cout << largerstr << " " << smallerstr << "\n";
        while(smaller - j >= 0){
            int digit_1 = (largerstr.at(larger - i) - '0'), digit_2 = (smallerstr.at(smaller-j) - '0');
            int current_sum = digit_1 + digit_2; 
            // std::cout << current_sum << " " << digit_1 << " " << digit_2 << " " << carry << "\n"; 

            if(current_sum > base){
                int remainder = current_sum - base;
                if(remainder + carry > base){
                    sum += std::to_string(remainder+carry-base);
                    // std::cout << "first 1 option\n";
                    carry++;
                } else if(remainder+carry == base){
                    sum+=std::to_string(0);
                    // std::cout << "first 2 option\n";
                    carry++;
                } else {
                    sum += std::to_string(remainder+carry);
                    // std::cout << "first 3 option\n";
                    carry = 1;

                }

            } else if(current_sum == base){
                if(current_sum + carry > base){
                    sum += std::to_string(current_sum+carry-base);
                    // std::cout << " Second 1 option\n";
                    carry=1;

                } else if(current_sum+carry == base){
                    // std::cout << "Second 2 option\n";
                    sum += std::to_string(0);
                    carry++;
                } else {
                    sum += std::to_string(carry);
                    carry = 0;
                    // std::cout << "Second 3 option\n";
                }

            } else {
                if(current_sum + carry > base){
                    sum += std::to_string(current_sum+carry-base);
                    carry++;
                    // std::cout << "Third 1 option\n";

                } else if(current_sum+carry == base){
                    sum += std::to_string(0);
                    carry = 1;
                    // std::cout << "Third 2 option\n";

                } else {
                    sum += std::to_string(current_sum+carry);
                    carry = 0;
                    // std::cout << "Third 3 option\n";
                }
            }
            // std::cout << sum <<'\n';
            i++; j++;
        }
        if(larger - i >= 0){ // just ensuring that after termination of the other while loop that we are still in range
            int digit = (largerstr.at(larger - i)-'0');
            // std::cout << digit << " " << carry << " " << digit + carry << " " << largerstr <<"\n";
            if(digit + carry >= base){
                sum += std::to_string(digit + carry - base); // digit+carry-base == 0 when digit+carry == base
                carry=1; last_digit = digit+carry-base;
            } else {
                sum += std::to_string(digit + carry); last_digit = digit+carry;
                carry=0;
            }
        }
        i++;
    }

    if(carry == 1 && last_digit == 0){sum += "1";}

    // reversing the sum because it needs it
    for(int x = 0; x < static_cast<int>(sum.size()); x++){
        newsum += sum.at(sum.size()-1-x);
    }
    return newsum;
    
}

std::string intSubtraction(std::string a, std::string b){
    if(a.size() < 2 || b.size() < 2){return std::to_string(std::stoull(a)-std::stoul(b));}
    // definitions
    std::string larger, smaller, output="";
    int largern, smallern, i=0, j=0, carrydigit=0;
    //  std::cout << "Made it to subtractions\n";
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
    
    // std::cout << "made it through the swapping of the strings\n";
    // reversing the strings:
    // std::cout << a << " " << b <<'\n';

    std::string reversed_larger="", reversed_smaller="";
    for(i = 0; i < static_cast<int>(largern+1); i++){reversed_larger += larger.at(largern-i);}
    
    for(i = 0; i < static_cast<int>(smallern+1); i++){reversed_smaller += smaller.at(smallern-i);}

    // std::cout << "Made it to the while loop\n";
    // std::cout << reversed_larger << " " << reversed_smaller <<'\n';
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

    // std::cout << "made it through the while loop\n";
    for(int x = i; x <= static_cast<int>(largern); x++){
        int val = (reversed_larger.at(x)-'0') - carrydigit;
        // std::cout << val << "\n";
        if(val < 0){output += val + 10 + '0'; carrydigit=1;}
        else {output += val+'0'; carrydigit=0;} 
    }

    // reversing the final string (output)
    std::string newout="";
    for(int n = 0; n < static_cast<int>(output.size()); n++){
        newout += output.at(output.size()-1-n);
    }
    // std::cout << "made it to return\n\n";
    return newout;
}