// find floor value for a key

#include <iostream>
#include <vector>
using namespace std;

int binarSearch (vector<int>arr,int key){
    int l = 0;
    int h = arr.size()-1;
    while(l<h){
        int mid = l + (h-l)/2;
        if(arr[mid]<key){
            l = mid+1;
        }else if(arr[mid] > key){
            h = mid-1;
        }else{
            return mid;
        }
    }
    return l;
}
int main(){
    vector<int>arr =  {-1, 2, 3, 5, 6, 8, 9, 10};
    int ind = binarSearch(arr,7);
    cout << arr[ind] <<endl;
    return 0; 
}