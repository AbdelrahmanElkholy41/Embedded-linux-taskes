#include <iostream>
#include <vector>
#include <algorithm>

int main(){

int c=0 ;
    std::vector<int> arr = {0, 2, 2, 8, 6, 12, 4};
    for (int  i = 0; i < arr.size(); i++)
    {
        if(arr[i]%  2 == 0)
        {
            c++;
        }

    }
    if(c==arr.size()){
        std::cout << "All elements in the array are even." << std::endl;
    }
}
