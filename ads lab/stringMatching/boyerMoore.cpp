#include <bits/stdc++.h>
using namespace std;
void findBadTable(map<char, int>&mpp,string pattern,int m){
    mpp['*']=m;
    mpp[pattern[m-1]]=m;
    for(int i=m-2;i>=0;i--){
        if(mpp.find(pattern[i])==mpp.end()){
            mpp[pattern[i]]=m-i-1;
        }   
    }
    
}
int boyer(string text,string pattern,map<char,int>&mpp,int n,int m){
    int p=m-1;
    int t=m-1;
    int count=0;
    while(t<n){
        int i=p;//for pattern 
        int j=t;//for text
        while(text[j]==pattern[i]){
            i--;
            j--;
            if(i==-1) break;
        }
        if(i<=-1) return j+1;
        else{
            int shift;
            if(mpp.find(text[j])==mpp.end()) shift=mpp['*'];
            else
                shift=mpp[text[j]];
            t=t+shift;
        }

    }
    return -1;
}
int main(){
    string text="akhilreddy";
    string pattern="reddy";
    int n=text.size();
    int m=pattern.size();
    map<char, int>mpp;
    findBadTable(mpp,pattern,m);
    cout<<boyer(text,pattern,mpp,n,m)<<endl;
    return 0;
}