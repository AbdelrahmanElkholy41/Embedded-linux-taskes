#include <iostream>
#include <algorithm>
#include <string>

int main()
{
std::string s="aeiouAEIOU";
    std::string ss;

    std::cin >>ss;
    for (int  i = 0; i < ss.size(); i++)
    {
        for (int j= 0; j < ss.size()-1; j++)
        {
            
        
        if (ss[i]==s[j])
        {
            std::cout <<ss[i] <<" is vowel"<<std::endl;
        }
        
    }
}
}
