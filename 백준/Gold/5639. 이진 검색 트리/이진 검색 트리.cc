#include <bits/stdc++.h>
using namespace std;

typedef struct Tree{
    struct Tree* left = NULL;
    int data;
    struct Tree* right = NULL;
} Tree;

void make_tree(struct Tree* next, int x){
    if(x < next->data){
        if(next->left == NULL){
            struct Tree* leaf = new Tree;
            leaf->data = x;
            next->left = leaf;
        }
        else make_tree(next->left, x);
    }
    else{
        if(next->right == NULL){
            struct Tree* leaf = new Tree;
            leaf->data = x;
            next->right = leaf;
        }
        else make_tree(next->right, x);
    }
}

void search(struct Tree* next){
    if(next == NULL) return;

    search(next->left);
    search(next->right);
    cout << next->data << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    struct Tree* root = new Tree;
    cin >> root->data;


    int x;
    while(cin >> x){
        make_tree(root, x);
    }

    search(root);

    return 0;
}