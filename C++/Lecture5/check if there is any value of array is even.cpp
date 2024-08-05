#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::vector<int> arr ={0,1  ,2,3,4,5,6,7,8,9};
    for (int  i = 0; i < arr.size(); i++)
    {
        if(arr[i]%  2 == 0)
        {
            std::cout << arr[i] << " "<<"is Even" <<std::endl;
        }

    }
    
}
