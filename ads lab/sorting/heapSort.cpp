#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void heapify(int arr[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    
    if(left<n&&arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n&&arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr,largest,i);
        heapify(arr,largest,n);
    }
    return;
    

}
int main(){
    int arr[]={4,1,2,3,7,8,9};
    int n=sizeof(arr)/sizeof(int);
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr,0,i);
        heapify(arr,0,i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}