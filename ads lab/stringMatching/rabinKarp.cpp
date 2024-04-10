#include <bits/stdc++.h>
using namespace std;
bool confirm(string a,string b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
int rabin(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    int hashPat=0,hashTxt=0;
    for(int i=0;i<m;i++){
        hashPat=hashPat*10;
        hashPat=hashPat+(pattern[i]-'a'+1);
        hashTxt=hashTxt*10;
        hashTxt=hashTxt+(text[i]-'a'+1);
    }
    int j=0;
    while(j<n-m+1){
        if(hashPat==hashTxt){
            if(confirm(text.substr(j,m),pattern)==true) return j;
        }else{
            hashTxt=hashTxt-(text[j]-'a'+1)*pow(10,m-1);
            j++;
            hashTxt=hashTxt*10;
            hashTxt=hashTxt+text[j+m-1]-'a'+1;
            
        }
    }
    return -1;
}
int main(){
    string text="abaabbcaabaab";
    string pattern="aabaa";
    cout<<rabin(text,pattern);
    return 0;
}