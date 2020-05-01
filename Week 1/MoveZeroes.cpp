/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
1. You must do this in-place without making a copy of the array.
2 .Minimize the total number of operations.
*/

/*
Approach:
1. Maintain a varible k.
2. For each non zero element swap with element at index k and increment k. 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                nums.erase(nums.begin()+i);
                i-=1;
                count++;
            }
        }
        for(int i=0;i<count;i++)
        {
            int x = 0;
            nums.push_back(x);
        }
       // return nums;
        
    }
};

int main()
{
    Solution obj;
    vector<int> vec = {0,1,0,3,12};
    obj.moveZeroes(vec);
    for(auto i : vec)
        cout<<i<<" ";
    return 0;
}
