#include<bits/stdc++.h>
using namespace std;
int first_occurrence(vector<int> vec,int target){
      int found=-1;
      int st=0;
      int end=vec.size()-1;
      int mid=(st+end)/2;
      while(st<=end){
            mid=(st+end)/2;
            if(vec[mid]==target){
            found=mid;
            end=mid-1;
            }
            else if(vec[mid]>target){
                  end=mid-1;
            }
            else {
                  st=mid+1;
            }
            
      }
      return found;
}
int last_occurrence(vector<int> vec,int target){
      int found=-1;
      int st=0;
      int end=vec.size()-1;
      int mid=(st+end)/2;
      while(st<=end){
            mid=(st+end)/2;
            if(vec[mid]==target){
                  // return mid;
            found=mid;
            st=mid+1;
            }
            else if(vec[mid]>target){
                  end=mid-1;
            }
            else {
                  st=mid+1;
            }
            
      }
      return found;
}
int total_occurrence(vector<int> vec,int target){
      int first=first_occurrence(vec,target);
      int last=last_occurrence(vec,target);
      if(first==-1) return 0;
      // if(first==last){
      //       return 1;
      // }
      return last-first+1;

}
int main()
{
vector<int>vec={1,2,3,6,6,6,7,8,9,10};
int target=11;
cout<<first_occurrence(vec,target)<<endl;
cout<<last_occurrence(vec,target)<<endl;
cout<<total_occurrence(vec,target)<<endl;
return 0;
}