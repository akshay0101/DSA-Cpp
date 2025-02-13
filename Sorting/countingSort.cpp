#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int>&arr){
    int n = arr.size();
    int maxVal = -1;
    for(auto num : arr) maxVal = max(maxVal,num);
    vector<int>result(maxVal+1,0);
    for(auto num : arr){
        result[num]++;
    }
    int i=0;
    for(int j=0 ;j<=maxVal ;j++){
        if(result[j] > 0){
            while(result[j]--){
                arr[i++] = j;
            }
        }
    }
}

int main(){
    vector<int>arr = {1,1,0,0,0,2,3,6,4,3,5};   // taking all +ve for now
    countSort(arr);
    for(auto num : arr){
        cout << num << endl;
    }
    return 0;
}