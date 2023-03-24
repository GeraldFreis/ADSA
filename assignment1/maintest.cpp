#include <iostream>
#include <string>
#include <math.h>
using namespace std;


/*
string substraction(string first_num, string second_num, int base)
{

	int num1_len = first_num.size();
	int num2_len = second_num.size();
	int result_len = max(num1_len, num2_len);
	string result_str="";
	int carry = 0;
	//add 0s in beginning to make length equal
	if (num1_len < num2_len)
	{
		for (int i = 0; i < num2_len - num1_len; i++)
		{
			first_num = '0' + first_num;
		}
		num1_len = num2_len;
	}
	else if (num1_len > num2_len)
	{
		for (int i = 0; i < num1_len - num2_len; i++)
		{
			second_num = '0' + second_num;
		}
		num2_len = num1_len;
	}

	//add one by one
	for (int i = 0; i < result_len; i++)
	{
		int num1, num2, curr_result;
		num1 = first_num[num1_len - 1 - i] - '0';
		num2 = second_num[num2_len - 1 - i] - '0';
		int current = num1 - carry - num2;
		// num1 = num1 - carry;
		if (current < 0)
		{
			carry = 1;
			curr_result = base + current;
		}
		else
		{
			carry = 0;
			curr_result = current;
		}
		result_str = to_string(curr_result) + result_str;
	}

	//remove all 0s in the beginning
	int breakpoint = result_str.size();
	for (int i = 0; i < breakpoint; i++)
	{
		if (result_str[i] != '0')
		{
			breakpoint = i;
			break;
		}
	}

	result_str = result_str.substr(breakpoint, result_str.size() - breakpoint);
	return result_str;
}
*/


string convertBase(int number, int base, string result)
{
	if (number < base)
	{
		return to_string(number);
	}
	else
	{
		int x = number % base;
		number = number / base;
		result = convertBase(number, base, result);
		result = result + to_string(x);
	}
	return result;
}

std::string nozeros(std::string a){
    int end=a.size();
    for(int i = 0; i < a.size(); i++){
        if(a.at(i) != '0'){end=i; break;}
    }
    a = a.substr(end,a.size()-end);
    if(a.size() == 0) return "0";
    return a;
}
std::string addition(std::string a, std::string second_num, int base) {
    std::string sum=""; 
    int largern=a.size(),smallern=second_num.size(), dig_c=0, dig_1, dig_2, current;
    // ensuring that the length of both strings is equal for addition
    if(largern > smallern){for(int i = 0; i < largern-smallern; i++){second_num = '0' + second_num;} smallern=largern;}
    else if(smallern > largern){for(int i = 0; i < smallern-largern;i++){a = '0' + a;} largern=smallern;}
    // largern--; smallern--;
    // std::cout << smallern << " " << largern << "\n";
    
    for(int i = 0; i < a.size(); i++){
        dig_1 = a.at(largern-1-i)-'0';
        dig_2 = second_num.at(smallern-1- i)-'0';
        current = dig_1 + dig_2 + dig_c;
        if(current < base){dig_c=0;}
        else{dig_c=1; current = current - base;}

        // prepending the result onto sum as otherwise i have to reverse and that's not worth it
        sum = std::to_string(current) + sum;
    }
    // ensuring the last carry is added

    return nozeros(std::to_string(dig_c) + sum);
}

std::string substraction(std::string a, std::string second_num, int base){
     std::string sum=""; 

    int largern=a.size(),smallern=second_num.size(), dig_c=0, dig_1, dig_2, current;
    // ensuring that the length of both strings is equal for subtraction
    if(largern > smallern){for(int i = 0; i < largern-smallern; i++){second_num = '0' + second_num;} smallern=largern;}
    else if(smallern > largern){for(int i = 0; i < smallern-largern;i++){a = '0' + a;} largern=smallern;}

    int i = 0;
    // just the inverse of intAddition
    while(smallern - 1 - i >= 0){
        dig_1 = a.at(largern - 1 - i) - '0'; dig_2 = second_num.at(smallern - 1 -i) - '0';
        current = dig_1 - dig_2 - dig_c; 
        if(current >= 0){dig_c=0;}
        else{dig_c=1; current+= base;}
        // prepending the current sum into the sum (so we don't have to reverse because Im lazy)
        sum = std::to_string(current) + sum;
        i++;
    }

    return nozeros(std::to_string(dig_c)+sum);

}

std::string converter(std::string a, int base){
    if(std::stoi(a) > base){
		int remainder = std::stoi(a) % base;
		int n = std::stoi(a) / base;
		std::string res = converter(std::to_string(n), base);
		res += std::to_string(remainder);
		return res;
	} else {
		return a;
	}
	return "0";
}


string Karatsuba(string first_num, string second_num, int base)
{

	int strlen1 = first_num.size();
	int strlen2 = second_num.size();
	if (strlen1 < strlen2)
	{
		for (int i = 0; i < strlen2 - strlen1; i++)
		{
			first_num = '0' + first_num;
		}
	}
	else if (strlen1 > strlen2)
	{
		for (int i = 0; i < strlen1 - strlen2; i++)
		{
			second_num = '0' + second_num;
		}
	}

	//return a string with base mutiplication
	if (first_num.size() == 1 && second_num.size() == 1)
	{
		// int num1 = first_num[0] - '0';
		// int num2 = second_num[0] - '0';
		// int mul = num1 * num2;
		// string result = "";
		return converter(std::to_string((first_num[0] - '0')*(second_num[0] - '0')), base);
;
	}
	else
	{
		int mid = first_num.size() / 2;
		std::string a1,a0,b0,b1;
		// string a1 = first_num.substr(0, mid);
		// string a0 = first_num.substr(mid, first_num.size() - mid);
		// string b1 = second_num.substr(0, mid);
		// string b0 = second_num.substr(mid, second_num.size() - mid);
		for(int i = 0; i < static_cast<int>(first_num.size() / 2); i++){a1 += first_num.at(i);}
		for(int i = 0; i < static_cast<int>(second_num.size() / 2); i++){b1 += second_num.at(i);}
		for(int i = static_cast<int>(first_num.size()/2); i < static_cast<int>(first_num.size()); i++){a0 += first_num.at(i);}
		for(int i = static_cast<int>(second_num.size()/2); i < static_cast<int>(second_num.size()); i++){b0 += second_num.at(i);}
		
		int k = first_num.size() - int(first_num.size()/2);
		// std::cout << k <<"\n";
		
		string a1b1 = Karatsuba(a1, b1,base);
		
		string a1_a0 = addition(a1, a0, base);
		string b1_b0 = addition(b1, b0, base);
		string a0b0 =Karatsuba(a0, b0, base);

		string part1 = a1b1;
		// std::cout << part1 << '\n';
        // std::cout << part1;
		for (int i =0;i<2*k;i++){
			part1 = part1 +"0";
		}

		string part2 = Karatsuba(a1_a0, b1_b0, base);
		// string part3 = addition(a1b1, a0b0,base);
		string part_mid = substraction(part2,addition(a1b1, a0b0,base),base);
        // std::cout << "part2 =" << part_mid << ": " << part2 << "-" << part3 << "\n";
		for (int i =0;i<k;i++){
			part_mid =part_mid +"0";
		}

		string part4 = a0b0;

		string result = part1;
		result = addition(result,part_mid,base);
		result = addition(result,part4,base);
		return result;

	}

	return "0";
}


// std::string Karatsuba(std::string a, std::string second_num, int base){
//     if(a.size() <= 2 && second_num.size() <= 2){return converter(std::to_string(std::stoull(a)*std::stoull(second_num)),base);}

//     std::string sum="", a_1, b_1, a_0, b_0, p, p_1, p_2, p_3; 
//     int largern=a.size(),smallern=second_num.size(), dig_c=0, dig_1, dig_2, current;
//     // ensuring that the length of both strings is equal for addition
//     if(largern > smallern){for(int i = 0; i < largern-smallern; i++){second_num = '0' + second_num;} smallern=largern;}
//     else if(smallern > largern){for(int i = 0; i < smallern-largern;i++){a = '0' + a;} largern=smallern;}

//     // dividing a and second_num into the required subsections (a=a_1*10^k+a_0)
//     for(int i = 0; i < static_cast<int>(a.size() / 2); i++){a_1 += a.at(i);}
//     for(int i = 0; i < static_cast<int>(second_num.size() / 2); i++){b_1 += second_num.at(i);}
//     for(int i = static_cast<int>(a.size()/2); i < static_cast<int>(a.size()); i++){a_0 += a.at(i);}
//     for(int i = static_cast<int>(second_num.size()/2); i < static_cast<int>(second_num.size()); i++){a_0 += a.at(i);}

//     int k = a.size() - int(a.size()/2);

//     // using karatsuba multiplication
//     p_1 = Karatsuba(a_1, b_1, base); for(int i = 0; i < 2*k; i++){p_1 += "0";}
//     p_3 = Karatsuba(a_0, b_0, base);

//     std::string last_part_of_p_2 = addition(p_1, p_3, base);
//     std::string a_1_plus_a_0 = addition(a_1,a_0,base);
//     std::string b_1_plus_b_0 = addition(b_1,b_0, base);

//     p_2 = Karatsuba(a_1_plus_a_0, b_1_plus_b_0, base);

//     p_2 = substraction(p_2, last_part_of_p_2, base);for(int i = 0; i < k; i++){p_2 += "0";}

//     p = addition(p_1, p_2, base);
//     p = addition(p, p_3, base);
//     return p;

// }




int main()
{
	string first_num, second_num, base;
	cin >> first_num >> second_num >> base;
	int base_int = stoi(base);
	// cout << substraction(first_num, second_num, base_int)<<endl;
	cout << addition(first_num, second_num, base_int) <<" "<<Karatsuba(first_num, second_num, base_int)<<endl;
	return 0;
}