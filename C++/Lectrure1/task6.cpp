#include <iostream>
#include <algorithm>
#include <string>

int main()
{
int n;
std::cout << "Enter the number of elements: ";
std::cin >> n;
int digt=0;
while (n>0) {
digt+=n%10;
n/=10;


}
std::cout<<digt<<std::endl;
}
