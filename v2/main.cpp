#include <string>
#include <cmath>
#include <iostream>

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
    std::cout << addition << " " << kara << " " << addition / kara;
}

int karatsuba(int a, int b){
    if(a < 10 || b < 10){return a * b;}
    int a_0, b_0, a_1, b_1, p, p_1, p_2, p_3, k, n;
    std::string n1 = std::to_string(a), n2 = std::to_string(b);
    n = n1.size();
    k = int(n/2);
    // splitting a and b into a = a_1*
}

int intaddition(int n1, int n2, int base){

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