#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::string intAddition(std::string a, std::string b, int base);
std::string intSubtraction(std::string a, std::string b, int base);
std::string intKaratsuba(std::string a, std::string b, int base);
std::string converter(std::string a, int base, std::string r);
std::string nozeros(std::string a);

int main(){
    std::string I1, I2; int b;
    std::cin >> I1 >> I2 >> b;
    std::cout << intAddition(I1,I2,b) << " " << intKaratsuba(I1,I2,b) << " " << "0" << "\n";
    // std::cout << "31115230444412301421141331340523545503021200534334322440024543053025201553200302122321441121050 221244112351110300053232523422005013541315204001221303502354405503434224000424423425123535225320001054520250420203123113132054313511535414501042130105304513455544223341010540145505444033513\n";
}

// a converting function to ensure that the values we return (when a and b are sufficiently small) will be in the correct base
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


std::string intAddition(std::string a, std::string b, int base) {
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

std::string intSubtraction(std::string a, std::string b, int base){
     std::string sum=""; 

    int largern,smallern, dig_c=0, dig_1, dig_2, current;
    // ensuring that the length of both is equal as that means we don't have to check conditions for when we are out of range
    std::vector<std::string> equals = equal_lengths(a,b);
    a=equals.at(0); largern=a.size(); b=equals.at(1); smallern=b.size();

    int i = 0;
    // just the inverse of intAddition
    while(smallern - 1 - i >= 0){
        dig_1 = a.at(largern - 1 - i) - '0'; dig_2 = b.at(smallern - 1 -i) - '0';
        current = dig_1 - dig_2 - dig_c; 
        if(current >= 0){dig_c=0;}
        else{dig_c=1; current+= base;}
        // prepending the current sum into the sum (so we don't have to reverse because Im lazy)
        sum = std::to_string(current) + sum;
        i++;
    }
    return nozeros(std::to_string(dig_c)+sum);
}

std::string intKaratsuba(std::string a, std::string b, int base){
    if(a.size() == 1 && b.size() == 1){
        return converter(std::to_string((a.at(0)-'0')*(b.at(0)-'0')),base);
        }

    std::string sum="", a_1, b_1, a_0, b_0, p, p_1, p_2, p_3, comp1, comp2, comp3; 
    int largern,smallern, dig_c=0, dig_1, dig_2, current;
    // ensuring that the length of both strings is equal for addition
    std::vector<std::string> equals = equal_lengths(a,b);
    a=equals.at(0); largern=a.size(); b=equals.at(1); smallern=b.size();
    // dividing a and b into the required subsections (a=a_1*10^k+a_0)
    for(int i = 0; i < static_cast<int>(a.size() / 2); i++){a_1 += a.at(i);}
    for(int i = 0; i < static_cast<int>(b.size() / 2); i++){b_1 += b.at(i);}
    for(int i = static_cast<int>(a.size()/2); i < static_cast<int>(a.size()); i++){a_0 += a.at(i);}
    for(int i = static_cast<int>(b.size()/2); i < static_cast<int>(b.size()); i++){b_0 += b.at(i);}

    int k = a.size() - int(a.size()/2);

    // using karatsuba multiplication
    p_1 = intKaratsuba(a_1, b_1, base); 
    p_3 = intKaratsuba(a_0, b_0, base);

    // std::string last_part_of_p_2 = intAddition(p_1, p_3, base);
    std::string a_1_plus_a_0 = intAddition(a_1,a_0,base);
    std::string b_1_plus_b_0 = intAddition(b_1,b_0, base);

    p_2 = intKaratsuba(a_1_plus_a_0, b_1_plus_b_0, base);

    p_2 = intSubtraction(p_2, intAddition(p_1, p_3, base), base);
    for(int i = 0; i < k; i++){p_2 += "0";}
    for(int i = 0; i < 2*k; i++){p_1 += "0";}
    p = p_1;
    p = intAddition(p, p_2, base);
    p = intAddition(p, p_3, base);
    return p;

}

