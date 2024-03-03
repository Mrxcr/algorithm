/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

你不需要考虑数组中超出新长度后面的元素。
*/

#include <vector>
#include <iostream>
using namespace std;

// My code
// 时间复杂度 O(n), 空间复杂度 O(1)
int RemoveEle(vector<int> &nums, int val){
    int index = 0;
    for (int i = 0; i < nums.size(); i++){
        nums[index] = nums[i];
        if (nums[index] != val){          
            index++;
        }
    }
    return index;
}

// 双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作
// 快指针：for循环
// 慢指针：需要更新的index
int RemoveEle2(vector<int> &nums, int val){
    int slowPt = 0;
    for (int fastPt = 0; fastPt < nums.size(); fastPt ++){
        if (nums[fastPt] != val){
            nums[slowPt] = nums[fastPt];
            slowPt++;
        }
    }
    return slowPt;
}

int main(void){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int len = RemoveEle2(nums, val);
    cout << len << endl;

    for (int i = 0; i < len; i++){
        cout << nums[i] << ", ";
    }
}