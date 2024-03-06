// finding the given number is prime or not tc=O(sqrt(n)) and sc=O(1):

#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
if(n<=1){
      return false;
}
else if(n==2||n==3) {
      return true;
}
else if(n%2==0||n%3==0) {
      return false;
}
// care full there is sqrt 
for(int i=5;i<sqrt(n);i+=6){
      if(n%i==0||n%(i+2)==0 ){
            return false;
      }
}
return true;
}
int main()
{
cout<<isPrime(33)<<endl;
cout<<isPrime(23)<<endl;
cout<<isPrime(67)<<endl;
cout<<isPrime(96)<<endl;
return 0;
}