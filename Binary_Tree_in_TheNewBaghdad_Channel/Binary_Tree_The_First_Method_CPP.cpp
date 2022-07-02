#include <iostream>
using namespace std;

struct Node{

    int val;
    struct Node *left;
    struct Node *right;

};

int main(){

    struct Node* root5 = new Node;
    root5->val = 5;
    struct Node* root3 = new Node;
    root3->val = 3;
    struct Node* root9 = new Node;
    root9->val = 9;
    root5->left = root3;
    root5->right = root9;
    struct Node* root2 = new Node;
    root2->val = 2;
    struct Node* root4 = new Node;
    root4->val = 4;
    root3->left = root2;
    root3->right = root4;
    struct Node* root7 = new Node;
    root7->val = 7;
    struct Node* root10 = new Node;
    root10->val = 10;
    root9->left = root7;
    root9->right = root10;

    root2->left = nullptr;
    root2->right = nullptr;
    root4->left = nullptr;
    root4->right = nullptr;
    root7->left = nullptr;
    root7->right = nullptr;
    root10->left = nullptr;
    root10->right = nullptr;

    cout << "\t\t\t" << root5->val << endl 
         << "\t" << root3->val << "\t\t\t\t" << root9->val << endl 
         << root2->val << "\t\t" << root4->val << "\t\t" << root7->val << "\t\t" << root10->val << endl;

    return 0;
}