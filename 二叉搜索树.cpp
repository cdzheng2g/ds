#include <iostream>
#include <vector>
using namespace std;


struct treeNode{
    int key;
    treeNode* right;
    treeNode* left;
    int size;
    int count;
    treeNode(int key):key(key),size(1),count(1),right(nullptr),left(nullptr){};
};

treeNode* insert(treeNode* node,int key){
    if (node==nullptr) return new treeNode(key);
    if(node->key<key) node->right=insert(node->right,key);
    else if(node->key>key) node->left=insert(node->left,key);
    return node;
}


void search(treeNode* node,int key){
    if(node== nullptr){
        cout<<"未找到";
        return;
    }
    if(key==node->key){
        cout<<"找到";
        return;
    }
    if(key<node->key)search(node->left,key);
    else search(node->right,key);
    return;
}




void pre(treeNode* node){
    if(node== nullptr) return;
    cout<<node->key<<" ";
    pre(node->left);
    pre(node->right);
}
void mid(treeNode* node){
    if(node== nullptr) return;
//    cout<<node->key<<" ";
    mid(node->left);
    cout<<node->key<<" ";
    mid(node->right);
}
void suf(treeNode* node){
    if(node== nullptr) return;
//    cout<<node->key<<" ";
    suf(node->left);
    suf(node->right);
    cout<<node->key<<" ";
}

int main(){
    treeNode* root= nullptr;
    vector<int> v={15,6,23,4,7,5,19,71,17,50,75};
    for (auto &s:v) {
            root= insert(root,s);
    }
    search(root,17);

}