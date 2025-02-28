#include <iostream>
#include<vector>
using namespace std;

int getLeft(vector<int>arr,int key){
  int ans = -1;
  int l = 0;
  int r = arr.size()-1;
  while(l<=r){
    int mid = l + (r-l)/2;
    if(arr[mid]>key)r =mid-1;
    else if(arr[mid]<key)l=mid+1;
    else{
      ans = mid;
      r=mid-1;
    }
  }
  return ans;
}

int getRight(vector<int>arr,int key){
  int ans = -1;
  int l = 0;
  int r = arr.size()-1;
  while(l<=r){
    int mid = l + (r-l)/2;
    if(arr[mid]>key)r =mid-1;
    else if(arr[mid]<key)l=mid+1;
    else{
      ans = mid;
      l=mid+1;
    }
  }
  return ans;
}
int main() 
{
  vector<int>arr = {0,2,2,2,2,3,3,4};
  int val = -1;
    int left = getLeft(arr,val);
    int right = getRight(arr,val);
    if(left == -1 || right == -1)cout<<"Nothing found"<<endl;
    else cout << right-left+1<<endl;
    return 0;
}