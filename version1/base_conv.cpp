#include <iostream>
#include <string>
#include <cmath>


int* base_converter(int num1, int num2)
{
    int *conversions = new int[2];

    int total_1 = 0, total_2 = 0;
    std::string num1_str = std::to_string(num1), num2_str = std::to_string(num2); 

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

int reconverter(int num)
{
    std::string numero = ""; 

    while(num > 0)
    {
        if(num % 2 == 0){numero += '0'; num /= 2;}
        else if(num%2 != 0){numero += '1'; num/=2;}
    }
    reverse(numero.begin(), numero.end());
    return std::stoi(numero);
}