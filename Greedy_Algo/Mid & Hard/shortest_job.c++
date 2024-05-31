#include<bits/stdc++.h>
using namespace std;

 long long solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        int ans=0,wt=0;
        sort(bt.begin(),bt.end());
        
        for(int i=0;i<n;i++){
             ans+=wt;
            wt+=bt[i];
        }
        return (ans/n);
    }

int main()
{
vector<int> bt = {4,3,7,1,2};
 
int cnt = solve(bt);
 cout <<"answer is"<<cnt<<endl;  
  return 0;
}