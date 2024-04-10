#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int partition(int arr[],int low,int high){
    int pivot=low;
    int i=low+1;
    int j=high;
    while(i<j){
        while(i<=high&&arr[i]<=arr[pivot]){
            i++;
        }
        while(j>=low&&arr[j]>arr[pivot]){
            j--;
        }
        if(i<j){
            swap(arr,i,j);
        }
    }
    swap(arr,pivot,j);
    return j;
}
void quickSort(int arr[],int low,int high){
    if(low>=high) return;
    int partitionInd=partition(arr,low,high);
    quickSort(arr,low,partitionInd-1);
    quickSort(arr,partitionInd+1,high);
}
int main(){
    int arr[]={4,1,16,2,8,11};
    int n=sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}