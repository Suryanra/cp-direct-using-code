#include<bits/stdc++.h>
using namespace std;
vector<int> factorial_of_a_large_number(int n){
      vector<int>vec;
      vec.push_back(1);
      for(int i=1;i<=n;i++){
            int carry=0;
            for(int j=0;j<vec.size();j++){
                  int value=vec[j];
                  int product=(value * i)+carry;
                  vec[j]=product%10;
                  carry=product/10;
            }
            while(carry)
            {vec.push_back(carry%10);
            carry=carry/10;
            
            }
      }
reverse(vec.begin(),vec.end());
      for(auto it:vec) cout<<it;

      return vec;
}
int main()
{
factorial_of_a_large_number(6);
return 0;
}