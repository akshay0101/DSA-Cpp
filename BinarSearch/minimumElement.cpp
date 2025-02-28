#include<iostream>
#include<vector>
using namespace std;

int getMinimumElement(vector<int>arr){

    int n = arr.size();
    int l =0;
    int h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]>arr[h])l=mid+1;
        else{
            if(mid-1 >=0 && mid+1<n && arr[mid]<arr[mid-1] && arr[mid] < arr[mid+1])return arr[mid];
            else h= mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {5,4,3,1,2};
    int minElement = getMinimumElement(arr);
    cout<<minElement<<endl;
    return 0;
}