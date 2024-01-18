#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> & nums, int target){
    /* Given a ordered array to search for the target */
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

int binarySearchInsertionSimple(vector<int> & nums, int target){
    /* 如果不存在target，则二分搜索结束后，索引i处的值是第一个大于target的元素，索引j处的值是最后一个小于target的元素！ */
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
    return i;
}

int main(void){
    vector<int> a = {1, 2, 6, 8, 12, 15, 23, 26, 31, 35};
    int res = binarySearchInsertionSimple(a, 16);
    cout << res << endl;
    return 0;
}