#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

int find(int a[], int n){
  
    int flag=0;
    for (int i = 0; i <10 ; i++)
    {
        if(a[i] == n){
            flag=1;
        }
    }
    return flag;
}
int main()
{

int arr[10]={0,1,2,3,4,5,6,7,8 ,9};
int n; 
std::cout << "Enter a number: ";
std::cin >> n;
int f=find(arr,n);
if(f==1){
    std::cout<<n<<" is present in the array."<<std::endl;
}
else{
    std::cout<<n<<" is not present in the array."<<std::endl;
}

}
