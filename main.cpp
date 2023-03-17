#include <vector>
#include <iostream>
#include <string>
#include <cmath>

int* base_converter(int num1, int num2);
int reconverter(int n);

int intaddition(int binaryint_1, int binaryint_2, int b){
    std::vector<int> carrydigits;
    std::string binarystr_1 = std::to_string(binaryint_1);
    std::string binarystr_2 = std::to_string(binaryint_2);

    int i = 0, sum=0, str1size=binarystr_1.size()-1, str2size=binarystr_2.size()-1;
    for(i = 0; i <= str1size && i <= str2size; i++){
        int currentsum = 0;
        if(i!=0){currentsum+=carrydigits.at(carrydigits.size()-1);} // adding the previous carry over digit to the current sum
        currentsum += binarystr_1.at(str1size-i)-'0'+binarystr_2.at(str2size-i)-'0';


        if(currentsum == b){carrydigits.push_back(1);}
        else if(currentsum > b){carrydigits.push_back(1); sum += 1 * pow(10,i);}
        else {carrydigits.push_back(0); sum += currentsum * pow(10,i);}
    }
    // if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}

    if(str1size > str2size){ // if we did not read all digits of the first number
        for(i=i; i <= str1size; i++){
            int currentsum = carrydigits.at(carrydigits.size()-1);
            currentsum += binarystr_1.at(str1size-i)-'0';
            if(currentsum == b-1){
                sum += 1*pow(10,i);
            } else if(currentsum == b){
                carrydigits.push_back(1);
            }
        }
    } else if(str1size < str2size){
        for(i=i; i <= str2size; i++){
            int currentsum = carrydigits.at(carrydigits.size()-1);
            currentsum += binarystr_2.at(str2size-i)-'0';
            if(currentsum == b-1){
                sum += (binarystr_2.at(str2size-i)-'0') * pow(10,i);
            } else if(currentsum == b){
                carrydigits.push_back(1);
            }
        }
    }  /* else {
        if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}
    } */
    if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}
    return sum;
}


int karatsuba(int numero_uno, int numero_dos){
    if(numero_uno <= 10 || numero_dos <= 10){
        return numero_uno*numero_dos;
    }
    std::string n1 = std::to_string(numero_uno), n2 = std::to_string(numero_dos);
    std::cout << n1 << " "  << n2 << "\n";
    int a_1, b_1, a_0, b_0, base, k, p_1, p_2, p_3;
    if(n1.size() != 2 && n2.size() != 2){
        base = n1.size()-1; // what we multiply the first two characters by
        k = std::ceil(n1.size()-1/2); // k = [n/2]

        // determining a_0, b_0, a_1 and b_0
        a_1 = (n1.at(0)-'0')*10 + (n1.at(1)-'0');
        a_0 = numero_uno - a_1 * std::pow(10, base-1);
        b_1 = (n2.at(0)-'0')*10 + n2.at(1)-'0';
        b_0 = numero_dos - b_1 * std::pow(10, base-1); 
        
        p_1 = (karatsuba(a_1,b_1)) * std::pow(10, 2*k);
        p_2 = (karatsuba((a_1+a_0), (b_1+b_0))-(karatsuba(a_1, b_1)+karatsuba(a_0, b_0))) * std::pow(10, k);
        p_3 = karatsuba(a_0, b_0);
    } else {
        base = n1.size()-1; // what we multiply the first two characters by
        k = std::ceil(float(base/2)); // k = [n/2]
        
        // determining a_0, b_0, a_1 and b_0
        a_1 = (n1.at(0)-'0');
        a_0 = n1.at(1)-'0';
        b_1 = (n2.at(0)-'0');
        b_0 = n2.at(1)-'0'; 
        if(a_1*10 == numero_uno || b_1*10 == numero_dos){
            std::cout <<  a_1  * b_1 * 10 + a_0 * b_1 * 10 + b_0 * a_1 * 10 + a_0 * b_0 <<"\n";return (a_1 * 10 * b_1 * 10 + a_0 * b_1 * 10 + b_0 * a_1 * 10 + a_0 * b_0);}
        std::cout << a_1 << " " << a_0 << "\n";
        /*  one with karatsuba called */
        p_1 = (karatsuba(a_1*10,b_1*10)) * std::pow(10, 2*k);  std::cout << p_1 << "\n";
        p_2 = (karatsuba((a_1+a_0), (b_1+b_0))-(karatsuba(a_1*10, b_1*10)+karatsuba(a_0, b_0))) * std::pow(10, k);
        p_3 = karatsuba(a_0, b_0);
        
    }
    std::cout << p_1 <<  " " << p_2 << " " << p_3 << " " << p_1 + p_2 + p_3 << "\n"; 
    return (p_1+p_2+p_3);
}


int main(){
    std::cout << intaddition(1001,1010, 2) << "\n";
    std::cout << intaddition(1011,101,2) << "\n";
    std::cout << intaddition(101, 30, 10) << "\n";
    std::cout << karatsuba(2,3) << "\n";
    std::cout << karatsuba(10,10) << "\n";
    std::cout << karatsuba(1234,5678) << "\n";
}

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