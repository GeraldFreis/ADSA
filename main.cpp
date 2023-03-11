#include <vector>
#include <iostream>
#include <string>
#include <cmath>

int intaddition(int binaryint_1, int binaryint_2, int b){
    std::vector<int> carrydigits;
    std::string binarystr_1 = std::to_string(binaryint_1);
    std::string binarystr_2 = std::to_string(binaryint_2);

    int i = 0, sum=0, str1size=binarystr_1.size()-1, str2size=binarystr_2.size()-1;
    for(i = 0; i <= str1size && i <= str2size; i++){
        int currentsum = 0;
        if(i!=0){currentsum+=carrydigits.at(carrydigits.size()-1);} // adding the previous carry over digit to the current sum
        currentsum += binarystr_1.at(str1size-i)-'0'+binarystr_2.at(str2size-i)-'0';


        if(currentsum == 2){carrydigits.push_back(1);}
        else if(currentsum > 2){carrydigits.push_back(1); sum += 1 * pow(10,i);}
        else {carrydigits.push_back(0); sum += currentsum * pow(10,i);}
    }
    if(carrydigits.size() == i){sum += carrydigits.at(carrydigits.size()-1) * pow(10,i);}
    return sum;
}

int base10intaddition(int decimalint_1, int decimalint_2){
return 0;
}

int main(){
    std::cout << intaddition(1001,1010, 2);
}