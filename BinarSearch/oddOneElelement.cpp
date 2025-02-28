#include<iostream>
#include<vector>
using namespace std;

int findOddOneElement(vector<int>arr){
    int n = arr.size();
    int l =0;
    int h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        int rightElements = h-mid;
        if(mid-1>=0 && arr[mid]==arr[mid-1]){
          if(rightElements % 2 ==0)h=mid-1;
          else l=mid+1;
        }else if(mid+1<n && arr[mid]==arr[mid+1]){
          if(rightElements %2 ==0)l=mid+1;
          else h=mid-1;
        }
        else return arr[mid];
    }
    return -1;
}
int main(){
    vector<int>arr = {1,1,2,3,3,4,4};
    int minElement = findOddOneElement(arr);
    cout<<minElement<<endl;
    return 0;
}