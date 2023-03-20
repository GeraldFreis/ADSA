#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

int converterToBase2(int n);
int *converterToBase10(int n1, int n2);
int karatsuba(int a, int b);
int intAddition(int n1, int n2, int base);

int main(){
    int I1, I2, b, kara, addition;
    std::cin >> I1 >> I2 >> b;
    addition = intAddition(I1, I2, b);
    if(b == 2){
        int *convertednums = converterToBase10(I1, I2);
        kara = converterToBase2(karatsuba(convertednums[0], convertednums[1]));
    }
    else {kara = karatsuba(I1, I2);}
    std::cout << addition << " " << kara << " " << 0 << '\n';
}

int karatsuba(int a, int b){
    if(a < 10 || b < 10){return a * b;}
    int a_0, b_0, a_1, b_1, p, p_1, p_2, p_3, k, n;

    std::string n1 = std::to_string(a), n2 = std::to_string(b);

    n = n1.size();
    k = int(n/2);

    // splitting a and b into a = a_1*k + a_0; b = b_1 * k + b_0;
    a_1 = a / std::pow(10, k); b_1 = b / std::pow(10, k);
    a_0 = a - a_1 * std::pow(10,k); b_0 = b - b_1 * std::pow(10, k);

    // finding p1, p2 and p3 using their respective formulas
    p_1 = karatsuba(a_1, b_1);
    p_3 = karatsuba(a_0, b_0);

    p_2 = karatsuba((a_1+a_0), (b_1+b_0)) - p_1 - p_3;

    p = p_1 * std::pow(10, n) + p_2 * std::pow(10, k) + p_3; 

    // std::cout << a << "=" << a_1 << "*10^(" << k << ") +  " << a_0 << ", " << b << "=" << b_1 << "*10^(" << k <<")" << " + " << b_0 << "\n";
    return p;
}

int intAddition(int n1, int n2, int base){
    int base_1 = 0;
    if(base == 2) base_1 = 10;
    else base_1 = 10;
    std::vector<int> carrydigits; carrydigits.push_back(0);
    std::string binarystr_1 = std::to_string(n1), largerstr;
    std::string binarystr_2 = std::to_string(n2), smallerstr;


    // std::cout << binarystr_1 << " " << binarystr_2 << "\n";
    int i=0,j=0, sum=0, str1size=(binarystr_1.size()-1), str2size=(binarystr_2.size()-1) , last_digit = 1;
    int larger = 0, smaller = 0; 

    if(str1size > str2size){
        larger = str1size; largerstr = binarystr_1;
        smaller = str2size; smallerstr = binarystr_2;
    } else if(str1size == str2size){
        larger = str1size; smaller = str1size;
        largerstr = binarystr_1; smallerstr = binarystr_2;
    } else {
        larger = str2size; largerstr = binarystr_2;
        smaller = str1size; smallerstr = binarystr_1;
    }

    while(larger - i >= 0)
    {
        // std::cout << largerstr << " " << smallerstr << "\n";
        while(smaller - j >= 0){
            int digit_1 = (largerstr.at(larger - i) - '0'), digit_2 = (smallerstr.at(smaller-j) - '0'), carry=carrydigits.back();
            int current_sum = digit_1 + digit_2 + carry; 
            // std::cout << current_sum << " " << digit_1 << " " << digit_2 << " " << carry << '\n';
            if(current_sum > base)
            {
                sum += (current_sum - base) * std::pow(base_1, j); last_digit = current_sum - base;
                carrydigits.push_back(1);
            } else if(current_sum == base) {
                carrydigits.push_back(1); last_digit = 0;
            } else if (current_sum < base){
                sum += current_sum * std::pow(base_1, j);
                carrydigits.push_back(0); last_digit = current_sum;
            } else {
                carrydigits.push_back(0);
                last_digit = 0;
            }



            // std::cout << sum << '\n';
            
            i++;
            j++;
        }

        if(larger - i >= 0){ // just ensuring that after termination of the other while loop that we are still in range
            int digit = (largerstr.at(larger - i)-'0'), carry = carrydigits.back();
            // std::cout << digit << " " << carry << " " << digit + carry << " " << largerstr <<"\n";
            if(digit + carry >= base){
                sum += (digit + carry - base) * std::pow(base_1, i); // digit+carry-base == 0 when digit+carry == base
                carrydigits.push_back(1); last_digit = digit+carry-base;
            } else {
                sum += (digit + carry) * std::pow(base_1, i); last_digit = digit+carry;
                carrydigits.push_back(0);
            }
        // std::cout << sum << '\n';
        }
        // std::cout << i << " " << larger-i << "\n";
        i++;
    }

    if(carrydigits.back() == 1 && last_digit == 0){sum += 1 * std::pow(base_1,i);}

    return sum;
}

// conversion functions

int *converterToBase10(int n1, int n2){
    int *conversions = new int[2];

    int total_1 = 0, total_2 = 0;
    std::string num1_str = std::to_string(n1), num2_str = std::to_string(n2); 

    for(int i = 0; i < static_cast<int>(num1_str.size()); i++)
    {
        total_1 += (num1_str.at(i) - '0') * std::pow(2, num1_str.size()-1-i);
        // std::cout << total_1 << " " << i << " " << (num1_str.at(i) - '0') << "\n";
    } 

    for(int i = 0; i<static_cast<int>(num2_str.size()); i++)
    {
        total_2 += (num2_str.at(i)-'0') * std::pow(2,num2_str.size()-1-i);
    }

    conversions[0] = total_1;
    conversions[1] = total_2;
    return conversions;
}

int converterToBase2(int n){
    std::string numero = ""; 

    while(n > 0)
    {
        if(n % 2 == 0){numero += '0'; n /= 2;}
        else if(n%2 != 0){numero += '1'; n/=2;}
    }
    
    std::string newnumero = "";
    for(int i = 0; i < static_cast<int>(numero.size()); i++){
        newnumero += numero.at(numero.size()-1-i);
    }

    return std::stoi(newnumero);
}