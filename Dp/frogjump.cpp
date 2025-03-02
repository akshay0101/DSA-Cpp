#include <bits/stdc++.h> 
int calcualteTopDown(int ind,vector<int> &heights,vector<int> &dp){     // top down solution
    if(ind ==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left = calcualte(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1)right = calcualte(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    return dp[ind] = min(left,right);
}

int calcualteBottomUp(int ind,vector<int> &heights,int k){
    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i =1;i<ind;i++){
        for(int j =1;j<=k;j++){
            int left = dp[i-1]+abs(heights[i]-heights[i-j]);
            int right = INT_MAX;
            if(i-j>0) right =abs( dp[i-j]+heights[i]-heights[i-j]);
            dp[i] = min(left,right);
        }
    }
    return dp[ind-1]
}


int frogJump(int n, vector<int> &heights)
{
    int k =2;
    vector<int>dp(n,-1,k);
    return calcualte(n-1,heights,dp);
}