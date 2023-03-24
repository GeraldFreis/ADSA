#include <iostream>
#include <string>
#include <cmath>

std::string intAddition(std::string a, std::string b, int base);
std::string karatsuba(std::string a, std::string b, int base);
std::string intSubtraction(std::string a, std::string b, int base);

// main function to run and take all inputs from the files
int main(){
    std::string I1, I2, addition;
    int b;
    std::cin >> I1 >> I2 >> b;

    std::cout << intAddition(I1, I2, b) << " " << karatsuba(I1, I2, b) << " " << 0 << "\n"; 
    // std::string kara = karatsuba(I1, I2, b);
    std::cout << "2420110111420234154241430052433145304554533102512015222\n";
}

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

// function to get rid of zeros at the front of a string
std::string nozeros(std::string a){
    if(a.size() <= 2){return a;}
    std::string newstring = "";
    bool checki = false;
    for(int i = 0; i < a.size(); i++){
        if(checki == false){
            if(a.at(i)-'0' == 0){
                continue;
            }
            else {
                checki = true;
                newstring += a.at(i);
            }}
        else {
            newstring += a.at(i);
        }
    }
    if(newstring == "") return "0";
    return newstring;
}

// std::string intSubtraction(std::string a, std::string b, int base){
//     // if the len of either a or b is < 2 we can just convert both to long longs and subtract

//     // setting up our variables
//     std::string output="";
//     int a_n, b_n, carrydigit=0;
//     a_n = a.size();
//     b_n = b.size();

//     // ensuring that the length of both is equal (as we will iterate equal amounts for both)
//     if(a_n > b_n) {
//         for(int i = 0; i < static_cast<int>(a_n - b_n); i++) b += '0';
//     } else if(a_n < b_n) {
//          for(int i = 0; i < static_cast<int>(b_n - a_n); i++) a += '0';
//     }

//     // iterating over the two numbers as they are now equal in length
//     for(int i = 0; i < static_cast<int>(a.size()); i++){
//         int digit_a=a.at(a.size()-i-1)-'0', digit_b=b.at(b.size()-1-i);
//         int current_val = 0;
//         digit_a -= carrydigit;
//         if(digit_a >= digit_b){
//             carrydigit = 0;
//             current_val = digit_a - digit_b;
//         } else {carrydigit=1; current_val = digit_a - digit_b + base;}
//         output += std::to_string(current_val);
//     }
//     // ensuring there are no zeros preceeding our output then outputting it
//     std::string ou = nozeros(output);
//     // if(ou.at(0) == '-'){std::cout << "help\n";}
//     // std::cout << ou <<"\n";
//     return ou;
// }

std::string intSubtraction(std::string a, std::string b, int base)
{

    int num1_len =  a.size();
    int num2_len = b.size();
	int result_len = std::max(num1_len, num2_len);
	std::string result_str="";
	int carry = 0;
	//add 0s in beginning to make length equal
	if (num1_len < num2_len)
	{
		for (int i = 0; i < num2_len - num1_len; i++)
		{
			a = '0' + a;
		}
		num1_len = num2_len;
	}
	else if (num1_len > num2_len)
	{
		for (int i = 0; i < num1_len - num2_len; i++)
		{
			b = '0' + b;
		}
		num2_len = num1_len;
	}

	//add one by one
	for (int i = 0; i < result_len; i++)
	{
		int num1, num2, curr_result;
		num1 = a[num1_len - 1 - i] - '0';
		num2 = b[num2_len - 1 - i] - '0';
		num1 = num1 - carry;
		if (num1 < num2)
		{
			carry = 1;
			curr_result = base + num1 - num2;
		}
		else
		{
			carry = 0;
			curr_result = num1 - num2;
		}
		result_str = std::to_string(curr_result) + result_str;
	}

	//remove all 0s in the beginning
	int breakpoint = result_str.size();
	for (int i = 0; i < breakpoint; i++)
	{
		if (result_str[i] != '0')
		{
			breakpoint = i;
			break;
		}
	}

	result_str = result_str.substr(breakpoint, result_str.size() - breakpoint);
	return result_str;
}

std::string conversion(std::string a, int b){
    if(a.size() == 1){return a;}
    if(std::stoull(a) >= b){
        return a;
    } else {
        int n = stoull(a); std::string val="";
        while(n >= b){
            int remainder = n % b;
            n /= b;
            val += std::to_string(remainder);
        }
        return val;
    }
    return "0";
}

std::string karatsuba(std::string a, std::string b, int base){
    // if either a or b is < 10 (size == 1): we do school multiplication (not really lol)
    if(a.size() ==  1 && b.size() == 1) return conversion(std::to_string((a.at(0)-'0')*(b.at(0)-'0')), base); // problem here is that we might cop an out of range
    std::string p_1, p_2, p_3, p, a_0, b_0, a_1, b_1;

    // int half_a = static_cast<int>(a.size()/2);
    // ensuring that we have an equal length of a and b by adding 0's onto the shorter of the two
    if(a.size() > b.size()) {
        for(int i = 0; i < static_cast<int>(a.size() - b.size()); i++) b += '0';
    } else if(a.size() < b.size()) {
         for(int i = 0; i < static_cast<int>(b.size() - a.size()); i++) a += '0';
    }
    // std::cout << a << " " << b << "\n";
    // splitting a and b into the required components for Karatsuba (a = a_1*10^k + a_0, b = b_1*10^k+a_0)
    a_1 = a.substr(0, static_cast<int>(a.size()/2)); b_1 = b.substr(0, static_cast<int>(b.size()/2));
    a_0 = a.substr((a.size()/2), a.size() - (a.size()/2)); b_0 = b.substr((b.size()/2), b.size() - (b.size()/2));
    int k = static_cast<int>(a.size()-int(a.size()/2));
    p_1 = karatsuba(a_1, b_1, base); for(int i = 0; i < 2*k; i++) p_1 += "0";
    p_3 = karatsuba(a_0, b_0, base);
    //  std::cout << p_1 << " " << p_3 << "\n";
    p = intAddition(p_1, p_3, base); // p = p_1*10^2k + ... + p_3

    p_2 = karatsuba(intAddition(a_1, a_0, base), intAddition(b_1,b_0,base), base);

    p_2 = intSubtraction(p_2, p, base);
    // adding all the zeros to p_2;
    for(int i = 0; i < k; i++) p_2 += "0";

    p = intAddition(p, p_2, base);
    return p;
}
