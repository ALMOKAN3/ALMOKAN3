#include <iostream>
using namespace std;

struct Node{

    int val;
    struct Node *left;
    struct Node *right;

    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }

};

int main(){

    struct Node* root5 = new Node(5);
    struct Node* root3 = new Node(3);
    struct Node* root9 = new Node(9);
    root5->left = root3;
    root5->right = root9;
    struct Node* root2 = new Node(2);
    struct Node* root4 = new Node(4);
    root3->left = root2;
    root3->right = root4;
    struct Node* root7 = new Node(7);
    struct Node* root10 = new Node(10);
    root9->left = root7;
    root9->right = root10;

    cout << "\t\t\t" << root5->val << endl 
         << "\t" << root3->val << "\t\t\t\t" << root9->val << endl 
         << root2->val << "\t\t" << root4->val << "\t\t" << root7->val << "\t\t" << root10->val << endl;


    return 0;
}