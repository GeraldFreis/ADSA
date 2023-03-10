#include <iostream>
#include <string>
#include <cmath>

extern int* base_converter(int, int);
extern int reconverter(int);

int main()
{
    int n1 = 111001; // 57
    int n2 = 100011; // 35

    int *arr = base_converter(n1, n2);

    std::cout << arr[0] << " " << arr[1] << "\n"; 
    std::cout << reconverter(arr[0]) << " " << reconverter(arr[1]) << "\n";
}