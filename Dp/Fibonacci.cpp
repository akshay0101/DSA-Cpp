#include <bits/stdc++.h>
using namespace std;

vector<int> getFibonacciSeries(int n){
    vector<int>ans(n+1,-1);
    //setting base cases 
    ans[0]=0;
    ans[1]=1;
    for(int i =2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans;
}
int getFibValue(int n,vector<int>&dp){
    if(n==0 || n==1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = getFibValue(n-1,dp)+getFibValue(n-2,dp);  // memoisation  top down
}


int main() {
	int n;
    cin>>n;
    vector<int>fibbonacci = getFibonacciSeries(n);
    vector<int>dp(n+1,-1);
    int val = getFibValue(n,dp);
    cout<<val<<endl;
    for(auto num:fibbonacci)cout<<num << " ";
    return 0;
}
