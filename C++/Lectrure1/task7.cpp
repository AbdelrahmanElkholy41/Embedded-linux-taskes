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

if(n%2==0){
std::cout <<'1';

}
else
{
    std::cout <<'0';
}
n/=2;
}
std::cout<<std::endl;

}
