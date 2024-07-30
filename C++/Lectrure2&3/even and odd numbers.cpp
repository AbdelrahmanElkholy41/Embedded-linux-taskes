#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

int main() {
   int arr[10]={0,1,2,3,4,5,6,7,8,9};
   for (int  i = 0; i < 10; i++)
   {
    if(arr[i]%2==0){
        std::cout << arr[i] << " is even" << std::endl;
    }
    else {
    std::cout << arr[i] << " is odd" << std::endl;
    }
   }
    return 0;
}


