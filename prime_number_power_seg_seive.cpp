#include<bits/stdc++.h>
using namespace std;
// gcd calculator
int gcd(int a,int b){
      if(a==0) return b;
      if(b==0) return a;
      while(a>0 and b> 0){
            if(a>b) a=a-b;
            else b=b-a;
      }
      return a==0?b:a;
}

// pow calculator of a to power b 
double power(double a,long long b){
      double ans=1;
      while(b>0){
            if(b%2==1){
            ans=ans*a;
            }
            a=a*a;
            b=b/2;
      }
      return ans;
}
double myPow(double a, int b){
      if(a==1) return 1;
      long long bc=b;
      if(bc <0){
      bc=-1*bc;
      a=1/a;
      }
      return power(a,bc);
}



// isprime  
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
            if(n%i==0||n%(i+2)==0){
            return false;
            }
      }
      return true;
}




// counting number of prime in given range:erasthonese 
// tc=n*loglog(n);
int N_of_Prime(int n){
      vector<bool>number(n+1,true);
      number[0]=false;
      number[1]=false;
      // for(int i=2;i<n+1;i++)
      // cout<<number[i]<<" ";
      // cout<<endl;
      int count=0;
      for(int i=2;i<n+1;i++){
            if(number[i]==1){
                  int index=i+i;
                  // cout<<i<<" "<<index<<endl;
                  while(index< n+1){
                        number[index]=false;
                        index+=i;
                        count++;
                  }
            }
      }
      int cnt=0;
      for(int i=0;i<n+1;i++){
      if(number[i]==true) {cnt++;}
      }
      cout<<"unpotimised running loop count "<<count<<endl;
      return cnt;
}





// optimised erasthoneses: 
// tc=n*loglog(n); in worst case it still remain same but it is beeter than unptimised as you can see
// by running  the code and counting that how many times loop runned
int N_of_Prime_optimised(int n){
      vector<bool>number(n+1,true);
      number[0]=false;
      number[1]=false;
      int count=0;
      for(int i=2;i<sqrt(n+1);i++){//optimising outer loop
            if(number[i]==1){
                  int index=i*i;//optimising condition for inner loop:
                  while(index< n+1){
                        number[index]=false;
                        index+=i;
                        count++;
                  }
            }
      }
      int cnt=0;
      for(int i=0;i<n+1;i++){
      if(number[i]==true) {cnt++;}
      }
      cout<<"optimised running loop count "<<count<<endl;
      return cnt;
}





// segemnted sieve theorem:
vector<bool>Sieve(int n){
    vector<bool>sieve(n,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i<=sqrt(n);i++)
    {
        int j=i*i;
        while(j<=n)
        {
            sieve[j]=false;
            j+=i;
        }
    }
      return sieve;   
}
vector<long long> SegSieve(int l,int r){
      // using previous sieve theorem to get all primes lewss than equal to sqrt(n);
      vector<bool>sieve=Sieve(sqrt(r)+1);
      vector<int>base_prime;
      for(int i=0;i<sieve.size();i++){
      if(sieve[i]) base_prime.push_back(i);
      }
      vector<bool>segsieve(r-l+1,true);
      for(auto prime:base_prime){
            int first_mul=(l/prime)*prime;//very important techniques you can go to notes for depper 
            //understanding why we do that
            if(first_mul< l) first_mul+=prime; 

            // note an important case also found:
            int j=max(first_mul,prime*prime);//think about this man
            while(j <= r){//you will have to use less than or equal to carefull about this
            segsieve[j-l]=false;
            j+=prime;
            }
      }
      cout<<endl<<"seg sive result range : "<<endl;
      vector<long long>all_prime_in_given_range;
      for(int i=0;i<segsieve.size();i++){
      if(segsieve[i]) {
            all_prime_in_given_range.push_back(i+l);
            }
      }
      return all_prime_in_given_range;



}



int main()
{
cout<<"total prime number "<<N_of_Prime(1000)<<endl<<endl;
cout<<"total prime number "<<N_of_Prime_optimised(1000)<<endl<<endl;

int a=2;int b=10;
cout<<"power of a to b "<<power(a,b)<<endl<<endl;
// cout<<"power of a to b "<<power(a,b)<<endl;

cout<<"segemnted sieve "<<endl;
SegSieve(10,50);
// cout<<"segemnted sieve "<<segsieve(10,50)<<endl;
return 0;
}