#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <vector>


int main() {
 
 std::pmr::vector<int>v={8,2,3,1,5,2,1};
 std::sort(v.begin(),v.end(),[](int a,int b){return a<b;});
 for (int  i = 0; i < v.size(); i++)
 {
    std::cout<<v[i]<<" ";

 }
 std::cout<<"\n";
 std::sort(v.begin(),v.end(),[](int a,int b){return a>b;});
 for (int  i = 0; i < v.size(); i++)
 {
   std::cout<<v[i]<<" ";
}
}


