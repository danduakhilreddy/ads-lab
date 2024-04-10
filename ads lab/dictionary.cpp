#include <bits/stdc++.h>
using namespace std;
class Dict{
    public:
        unordered_map<int,string>mpp;
        Dict(){
            mpp.clear();
        }
        


void add(pair<int,string> p){
    mpp[p.first]=p.second;
}
string get(int key){
    if(mpp.find(key)==mpp.end()){
        return "nostring exist";
    }
    return mpp[key];
}
void deleteEle(int key){
    if(mpp.find(key)==mpp.end()){
        cout<<"no key found to delete"<<endl;
    }
    mpp.erase(key);
}
void print(){
    if(mpp.size()==0) cout<<"dictionary is empty"<<endl;
    for(auto it:mpp){
        cout<<it.first<<" :"<<it.second<<endl;
    }
}
int size(){
    return mpp.size();
}
};

int main(){
    Dict dt;
    dt.add({1,"hello"});
    dt.add({2,"hi"});
    dt.add({3,"world"});
    cout<<dt.get(3);
    dt.deleteEle(2);
    dt.print();
    return 0;
}