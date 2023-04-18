#include <string>
#include <iostream>
#include <vector>


std::string schoolMultiplication(std::string I1, std::string I2, int base);

int main(){
    int b;
    std::string I1,I2;
    std::cin >> I1 >> I2 >> b;
    std::cout << schoolMultiplication(I1, I2, b) << "\n";
}
std::string converter(std::string a, int base){
    int n = std::stoi(a);
    if(n > base){
		int remainder = n % base;
		n = n / base;
		std::string res = converter(std::to_string(n), base);
		res += std::to_string(remainder);
		return res;
	} else {
		return a;
	}
	return "0";
}

// ensuring there are no zeros preceeding the sum
std::string nozeros(std::string a){
    int end=a.size();
    for(int i = 0; i < a.size(); i++){
        if(a.at(i) != '0'){end=i; break;}
    }
    std::string newa="";
    for(int i=end; i < a.size(); i++){newa += a.at(i);}
    // a = a.substr(end,a.size()-end);
    if(newa.size() == 0) return "0";
    return newa;
}


std::vector<std::string> equal_lengths(std::string a, std::string b){
    int largern=a.size(),smallern=b.size();
    // ensuring that the length of both strings is equal for addition
    if(largern > smallern){for(int i = 0; i < largern-smallern; i++){b = '0' + b;} smallern=largern;}
    else if(smallern > largern){for(int i = 0; i < smallern-largern;i++){a = '0' + a;} largern=smallern;}
    std::vector<std::string> out; out.push_back(a); out.push_back(b);
    return out;
}


std::string intAddition(std::string a, std::string b, int base){
    std::string sum=""; 
    int largern,smallern, dig_c=0, dig_1, dig_2, current;
    // ensuring that the length of both strings is equal for addition
    std::vector<std::string> equals = equal_lengths(a,b);
    a=equals.at(0); largern=a.size(); b=equals.at(1); smallern=b.size();
    // largern--; smallern--;
    // std::cout << smallern << " " << largern << "\n";
    
    for(int i = 0; i < a.size(); i++){
        dig_1 = a.at(largern-1-i)-'0';
        dig_2 = b.at(smallern-1- i)-'0';
        current = dig_1 + dig_2 + dig_c;
        if(current < base){dig_c=0;}
        else{dig_c=1; current = current - base;}

        // prepending the result onto sum as otherwise i have to reverse and that's not worth it
        sum = std::to_string(current) + sum;
    }
    // ensuring the last carry is added

    return nozeros(std::to_string(dig_c) + sum);
}

std::string schoolMultiplication(std::string a, std::string b, int base){
    if(a.size() == 1 || b.size() == 1){return converter(std::to_string(std::stoull(a)*std::stoull(b)), base);}
    int largern, smallern;
    std::vector<std::string> equals = equal_lengths(a,b);
    a=equals.at(0); largern=a.size(); b=equals.at(1); smallern=b.size();
    // splitting a and b into halves
    std::string first_a,first_b,second_a,second_b;
    int middle = largern/2;
    first_a = a.substr(0, middle); second_a = a.substr(middle, largern);
    first_b = b.substr(0, middle); second_b = b.substr(middle, smallern);

    
}