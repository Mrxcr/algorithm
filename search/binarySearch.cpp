#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> & nums, int target){
    int i = 0, j = nums.size() - 1;
    while (i <= j)
    {
        int m = (i + j) / 2;
        if (target > nums[m]){
            i = m + 1;
        } 
        else if (target < nums[m])
        {
            j = m - 1;
        }
        else if (target == nums[m])
        {
            return m;
        }        
    }
    return -1;
}

int main(void){
    vector<int> a = {1, 2, 6, 8, 12, 15, 23, 26, 31, 35};
    int res = binarySearch(a, 16);
    int i;
    cin>> i;
    cout<< res<< endl; 
    return 0;
}