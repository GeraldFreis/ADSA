#include <iostream>
#include <string>
#include <cmath>
#include <vector>


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

// need to go from the end for this function
int integerAddition(int num1, int num2, int B)
{
    if(B == 2){int *arr = base_converter(num1, num2); num1 = arr[0]; num2=arr[1];}

    int total = 0;
    std::string num_1 = std::to_string(num1), num_2 = std::to_string(num2); 
    
    int *carryvalues = new int[std::max(num_1.size(), num_2.size())];



    if(B == 2){return reconverter(total);}
    return total;

}

int karatsubaMultiplication(int num1, int num2)
{

}

int main()
{


}

