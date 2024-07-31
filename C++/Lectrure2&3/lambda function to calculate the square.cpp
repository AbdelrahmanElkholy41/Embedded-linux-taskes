#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

auto sq=[](int n){
    return n*n;
 };
int main() {
 
 int n; 
 std::cout << "Enter a number: ";
 std::cin >> n;
std::cout<<sq(n)<<std::endl;
}


