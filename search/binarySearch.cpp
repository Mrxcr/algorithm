#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 如果不存在target，则二分搜索结束后，索引i处的值是第一个大于target的元素，索引j处的值是最后一个小于target的元素！ */
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

/* 二分查找插入点（不存在重复元素） */
int binarySearchInsertionSimple(vector<int> & nums, int target){
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

/* 二分查找插入点（存在重复元素） */
int binarySearchInsertion(vector<int> & nums, int target){
    int i = 0, j = nums.size() - 1;
    while (i <= j){
        int m = i + (j - i) / 2;
        if (nums[m] < target){
            i = m + 1;
        }
        else if (nums[m] > target)
        {
            j = m -1;
        }
        else{
            j = m - 1;
        }
    }
    return i;
}


int main(void){
    vector<int> a = {1, 2, 6, 8, 12, 15, 15, 15, 15, 23, 26, 31, 35};
    int res = binarySearchInsertion(a, 16);
    cout << res << endl;
    return 0;
}