#include<iostream>
#include<vector>
using namespace std;

int findElement(vector<int>arr,int val){
    int n = arr.size();
    int l =0;
    int h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid] == val)return val;
        else if(arr[mid]<val){
            if(arr[l] <arr[mid])l=mid+1;
            else h=mid-1;

        }else{
            if(arr[mid] > arr[l] && a[l]<val) h=mid-1;
            else l=mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {3,4,5,6,1,2};
    int val = 4;
    int minElement = findElement(arr,val);
    cout<<minElement<<endl;
    return 0;
}