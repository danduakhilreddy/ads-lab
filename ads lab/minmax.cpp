#include <bits/stdc++.h>
using namespace std;
class heap{
    
        
    public:
        vector<int>node;
        int getParent(int i){
            return (i-1)/2;
        }
        int getMinChild(int i){
            int leftChild=2*i+1;
            int rightChild=2*i+2;
            if(node[leftChild]<node[rightChild]) return leftChild;
            return rightChild;
        }
        int getMaxChild(int i){
            int leftChild=2*i+1;
            int rightChild=2*i+2;
            if(node[leftChild]>node[rightChild]) return leftChild;
            return rightChild;
        }
        void minHeapify(int i){
            int minChildren=getMinChild(i);
            while(minChildren<node.size()&&node[minChildren]<node[i]){
                swap(node[minChildren],node[i]);
                minHeapify(minChildren);
            }
        }
        void maxHeapify(int i){
            int maxChildren=getMaxChild(i);
            while(maxChildren<node.size()&&node[maxChildren]>node[i]){
                swap(node[maxChildren],node[i]);
                maxHeapify(maxChildren);
            }
        }
        void insert(int data){
            node.push_back(data);
            int i=node.size()-1;
            int parent=getParent(i);
            while(i>0&&node[parent]>node[i]){
                swap(node[i],node[parent]);
                i=parent;
                parent=getParent(i);
            }
        }
        void deleteMin(){
            if(node.size()<0) return;
            node[0]=node.back();
            node.pop_back();
            minHeapify(0);
        }
        void deleteMax(){
            if(node.size()<0) return;
            int maxEle=getMaxChild(0);//it will be maximum in min max heap
            if(maxEle<node.size()){
                node[maxEle]=node.back();
                node.pop_back();
                maxHeapify(maxEle);
            }


        }
        void printHeap(){
            for(int i=0;i<node.size();i++){
                cout<<node[i]<<" ";
            }
        }
        void swap(int &a,int &b){
            int temp=a;
            a=b;
            b=temp;
        }
};
int main(){
    heap h;
    h.insert(5);
    h.insert(6);
    h.insert(1);
    h.insert(10);
    h.insert(34);
    h.printHeap();
    cout<<endl;
    h.deleteMax();
    h.deleteMin();
    h.printHeap();
    return 0;
}