#include <bits/stdc++.h>
using namespace std;
int find(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    for(int i=0;i<n;i++){
        int count=0;
        if(text[i]==pattern[0]){
            for(int j=0;j<m;j++){
                if(text[i+j]==pattern[j]) count++;
                if(count==m) return i;
            }
        }
    }
    return -1;
}
int main(){
    string text="danduakhilreddy";
    string pattern="akhil";
    cout<<find(text,pattern);
    return 0;
}