
#include <iostream>
#include <string>
#include <vector>

// defining the functions that are implemented
std::string karatsuba(std::string a, std::string b);
std::string intAddition(std::string n1, std::string n2, int base);

// main function to run and take all inputs from the files
int main(){
    std::string I1, I2, kara, addition;
    int b;
    std::cin >> I1 >> I2 >> b;

    std::cout << intAddition(I1, I2, b) << " " << karatsuba(I1, I2) << " " << 0 << "\n"; 
    std::cout << "510142435045524244505303310520550440450253305012513\n";
}

// implementation of the karatsuba multiplcation algorithm
std::string karatsuba(std::string a, std::string b)
{
    if(a.size() < 2 || b.size() < 2) return std::to_string(std::stoi(a) * std::stoi(b));

    return "a";
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
            std::cout << current_sum << " " << digit_1 << " " << digit_2 << " " << carry << "\n"; 

            if(current_sum > base){
                int remainder = current_sum - base;
                if(remainder + carry > base){
                    sum += std::to_string(remainder+carry-base);
                    std::cout << "first 1 option\n";
                    carry++;
                } else if(remainder+carry == base){
                    sum+=std::to_string(0);
                    std::cout << "first 2 option\n";
                    carry++;
                } else {
                    sum += std::to_string(remainder+carry);
                    std::cout << "first 3 option\n";
                    carry = 1;

                }

            } else if(current_sum == base){
                if(current_sum + carry > base){
                    sum += std::to_string(current_sum+carry-base);
                    std::cout << " Second 1 option\n";
                    carry=1;

                } else if(current_sum+carry == base){
                    std::cout << "Second 2 option\n";
                    sum += std::to_string(0);
                    carry++;
                } else {
                    sum += std::to_string(carry);
                    carry = 0;
                    std::cout << "Second 3 option\n";
                }

            } else {
                if(current_sum + carry > base){
                    sum += std::to_string(current_sum+carry-base);
                    carry++;
                    std::cout << "Third 1 option\n";

                } else if(current_sum+carry == base){
                    sum += std::to_string(0);
                    carry = 1;
                    std::cout << "Third 2 option\n";

                } else {
                    sum += std::to_string(current_sum+carry);
                    carry = 0;
                    std::cout << "Third 3 option\n";
                }
            }
            std::cout << sum <<'\n';
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

    if(carry== 1){sum += "1";}

    // reversing the sum because it needs it
    for(int x = 0; x < static_cast<int>(sum.size()); x++){
        newsum += sum.at(sum.size()-1-x);
    }
    return newsum;
    
}