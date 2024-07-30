#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

int find(int a[]){
    int mx=a[0];
    for (int i = 0; i <10 ; i++)
    {
        if(a[i]>mx){
            mx=a[i];
        }
    }
    return mx;
}
int main()
{

int arr[10]={0,1,2,3,4,5,6,7,8 ,9};

std::cout<<find(arr)<<std::endl;

}
