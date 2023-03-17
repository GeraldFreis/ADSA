#include <string>
#include <cmath>
#include <iostream>
#include <vector>

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
    std::cout << addition << " " << kara << " " << std::floor(float(float(I1) / float(I2)));
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

    std::cout << a << "=" << a_1 << "*10^(" << k << ") +  " << a_0 << ", " << b << "=" << b_1 << "*10^(" << k <<")" << " + " << b_0 << "\n";
    return p;
}

int intAddition(int n1, int n2, int base){
    std::vector<int> carrydigits;
    std::string binarystr_1 = std::to_string(n1);
    std::string binarystr_2 = std::to_string(n2);

    int i = 0, sum=0, str1size=binarystr_1.size()-1, str2size=binarystr_2.size()-1;
    for(i = 0; i <= str1size && i <= str2size; i++){
        int currentsum = 0;
        if(i!=0){currentsum+=carrydigits.at(carrydigits.size()-1);} // adding the previous carry over digit to the current sum
        currentsum += binarystr_1.at(str1size-i)-'0'+binarystr_2.at(str2size-i)-'0';


        if(currentsum == base){carrydigits.push_back(1);}
        else if(currentsum > base){carrydigits.push_back(1); sum += 1 * pow(10,i);}
        else {carrydigits.push_back(0); sum += currentsum * pow(10,i);}
    }
    // if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}

    if(str1size > str2size){ // if we did not read all digits of the first number
        for(i=i; i <= str1size; i++){
            int currentsum = carrydigits.at(carrydigits.size()-1);
            currentsum += binarystr_1.at(str1size-i)-'0';
            if(currentsum == base-1){
                sum += 1*pow(10,i);
            } else if(currentsum == base){
                carrydigits.push_back(1);
            }
        }
    } else if(str1size < str2size){
        for(i=i; i <= str2size; i++){
            int currentsum = carrydigits.at(carrydigits.size()-1);
            currentsum += binarystr_2.at(str2size-i)-'0';
            if(currentsum == base-1){
                sum += (binarystr_2.at(str2size-i)-'0') * pow(10,i);
            } else if(currentsum == base){
                carrydigits.push_back(1);
            }
        }
    }  /* else {
        if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}
    } */
    if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}
    return sum;
}

// conversion functions

int *converterToBase10(int n1, int n2){
    int *conversions = new int[2];

    int total_1 = 0, total_2 = 0;
    std::string num1_str = std::to_string(n1), num2_str = std::to_string(n2); 

    for(int i = 0; i < num1_str.size(); i++)
    {
        total_1 += (num1_str.at(i) - '0') * pow(2, num1_str.size()-1-i);
        // std::cout << total_1 << " " << i << " " << (num1_str.at(i) - '0') << "\n";
    } 

    for(int i = 0; i<num2_str.size(); i++)
    {
        total_2 += (num2_str.at(i)-'0') * pow(2,num2_str.size()-1-i);
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
    reverse(numero.begin(), numero.end());
    return std::stoi(numero);
}