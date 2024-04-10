#include <bits/stdc++.h>
using namespace std;
void compute(vector<int>&lps,string pattern,int m){
    int i=0,j=1;
    int count=0;        
    while(j<m){
        if(pattern[j]==pattern[i]){
            count++;
            lps[j]=count;
            i++;
            j++;
        }else{
            count=0;
            i=0;
            j++;
        }
    }
}
int kmp(string text,string pattern,vector<int>&lps,int n,int m){
    int i=0,j=-1;
    while(i<n){
        if(j==m-1) return i-m;
        if(text[i]==pattern[j+1]){
            i++;
            j++;
        }else{
            if(j==-1){
                i++;
            }else{
                j=lps[j]-1;
            }
        }
    }
    return -1;
}
int main(){
    string text="aabaabbcaabaab";
    string pattern="aabaa";
    int n=text.size();
    int m=pattern.size();
    vector<int>lps(m,0);
    compute(lps,pattern,m);
    cout<<kmp(text,pattern,lps,n,m);
    
    return 0;
}