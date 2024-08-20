#include <bits/stdc++.h>
using namespace std;
void findLps(vector<int>&lps,string &text,int m){
    int i=0;
    int j=1;
    
    while(j<m){
        int count=0;
        if(text[i]==text[j]){
            count++;
            lps[j]=count;
            i++;
            j++;
        }else{
            if(i==0){
                j++;
            }else{
                i=lps[i-1];
            }
        }
    }
}
int main(){
    string text="danduaaakhilreddy";
    string pattern="akhil";
    int m=text.size();
    int n=pattern.size();
    vector<int>lps(m,0);
    findLps(lps,pattern,n);
    int i=0,j=0;
    int result=-1;
    while(i<m){
        if(j==n){
            result=i-n;
            break;
        }
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j==0) i++;
            else{
                j=lps[j-1];
            }
        }
    }
    cout<<"pattern found at index :"<<result;
    
    return 0;
}
