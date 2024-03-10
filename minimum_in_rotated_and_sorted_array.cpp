#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
       int st=0;
       int end=nums.size()-1;
       while(st<=end){
           int mid=(st+end)/2;

           if(mid-1>=0 && nums[mid]<nums[mid-1]) return nums[mid];
           else if(mid+1<= end && nums[mid] > nums[mid+1]) 
           return nums[mid+1];
           else if(nums[0] > nums[nums.size()-1]){
               if(nums[mid] >  nums[0]) st=mid+1;
               else end=mid;
           }
           else {
               return nums[0];
           }

       }
       return -1;
    }

int main()
{
vector<int>nums={3,4,5,1,2};
cout<<findMin(nums)<<endl;
return 0;
}