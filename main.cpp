#include <iostream>
#include <string>
#include <cmath>


int* base_converter(int num1, int num2)
{
    int *conversions = new int[2];

    int total_1 = 0, total_2 = 0;
    std::string num1_str = std::to_string(num1), num2_str = std::to_string(num2); 

    for(int i = num1_str.size()-1; i >= 0; i--)
    {
        total_1 += (num1_str.at(i) - '0') * pow(2, i);
    } 

    for(int i = num2_str.size()-1; i>=0; i--)
    {
        total_2 += (num2_str.at(i)-'0') * pow(2,i);
    }

    conversions[0] = total_1;
    conversions[1] = total_2;
    return conversions;
}

int *reconverter(int num)
{

}


int integerAddition(int num1, int num2, int B)
{
    if(B == 2){int *arr = base_converter(num1, num2); num1 = arr[0]; num2=arr[1];}

    

}

int karatsubaMultiplication(int num1, int num2)
{

}

int main()
{


}

