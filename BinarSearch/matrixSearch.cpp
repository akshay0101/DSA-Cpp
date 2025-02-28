#include<iostream>
#include<vector>
using namespace std;


void findElelmetInMatrix(vector<vector<int>> arr,int key){
    int rows = arr.size();
    int columns = arr[0].size();
    int l = 0;int h=rows*columns -1;
    while(l<=h){

        int mid = l + (h-l)/2;
        int r = mid/columns;
        int c = mid%columns;
        if(arr[r][c]>key)h=mid-1;
        else if (arr[r][c]<key)l= mid+1;
        else{
            cout <<r << " "<< c<<endl;
            return;
        }
    }
}
int main(){
    vector<vector<int>> arr = {{1, 3,5,7}, {10, 11,16,20},{23,30,34,60}};
    int key = 11;
    findElelmetInMatrix(arr,key);
    return 0;
}