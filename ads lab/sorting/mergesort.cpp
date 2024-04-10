#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    vector<int>result;
    int i=low;
    int j=mid+1;
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]){
            result.push_back(arr[i]);
            i++;
        }else{
            result.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        result.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        result.push_back(arr[j]);
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=result[i-low];
    }
}
void mergeSort(int arr[],int low,int high){
    if(low>=high) return;
    int mid=(low+high)>>1;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int arr[]={4,5,2,3,9,1};
    int n=sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ,";
    }

    return 0;
}