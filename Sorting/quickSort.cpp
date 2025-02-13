#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot = (low+high)/2;
    int i = low;
    int j = high;
    while(i<j){
        if(arr[i] <arr[pivot]) i++;
        else {
            while(arr[j]>arr[pivot]){
                j--;
            }
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}

void quickSort(vector<int>&arr,int l,int h){
    if(l<h){
        int part = partition(arr, l,h);
        quickSort(arr,l,part);
        quickSort(arr,part+ 1,h);
    }
}
int main(){
    vector<int>arr = {2,5,1,7,3,55,23,56,21};
    int n = arr.size();
    quickSort(arr,0,n-1);
    for(auto num : arr){
        cout<< num <<endl;
    }
    return 0;
}