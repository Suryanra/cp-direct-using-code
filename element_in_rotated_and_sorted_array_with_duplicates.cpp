#include <bits/stdc++.h>
using namespace std;


int search(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (nums[mid] == target)
            return true;
        if(nums[st]==nums[mid] && nums[mid]==nums[end])
        {
            st++;
            end--;
            continue;
        }



        if (nums[st] <= nums[mid])
        {
            if (target >= nums[st] && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (target >= nums[mid] && target <= nums[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return false; // Return -1 if the target is not found
}
int main()
{
    vector<int> nums = {1,0,1,1,1};

    int key = 0;
    int index = search(nums, key);

    if (index != -1)
        cout << "Index: " << index << endl;
    else
        cout << "Key not found" << endl;

    return 0;
}
