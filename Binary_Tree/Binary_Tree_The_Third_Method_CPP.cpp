#include <iostream>
using namespace std;

// هي أمكان لكائنات متعددة  في الذاكرة لكل كائن مؤشران عن يمينه وعن يساره إما يؤشران على لا شيء وإما يؤشران على أمكان أخرى في الذاكرة ومهمتها الربط بين القيم في الذاكرة Binary Tree الـ
// ملاحظة: يجب تحرير(حذف) الذاكرة من الكائنات المنشئة بستخدام هذه الطريقة
// Double Linked List و Binary Tree الفرق بين الـ:
// الشجرة تكون مرتبة فأساس الشجرة يجب أن يكون الرقم الأوسط وماعلى يمينه أكبر منه وما على يساره أصفر منه ويتكرر الأمر بنفس الطريقة
// أما القائمة المزدوجة فهي ليست مرتبة ولا أساس لها والقيم المتصلة بالكائن المنشأ أولا لا يوجد ترتيب لها

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

struct Node* root = nullptr;

// لتنظيم الكود وسهولة القراءة
#define newNode(val) (new Node(val))
#define getLeftChild(node) (node->left)
#define getRightChild(node) (node->right)
#define getValue(node) (node->val)

void addNodeToTree(struct Node* startNode, struct Node* newNode){
    if(root == nullptr){
        root = newNode;
        return;
    }
    if(newNode->val < startNode->val){
        // add to left side the terr
        if(startNode->left == nullptr){
            startNode->left = newNode;
            return;
        }
        addNodeToTree(startNode->left, newNode);
    }
    if(newNode->val > startNode->val){
        // add to right side the terr
        if(startNode->right == nullptr){
            startNode->right = newNode;
            return;
        }
        addNodeToTree(startNode->right, newNode);
    }
}

void BuildTreeFromArray(int* arrayOfValue, int size){
    cout << "Start Build Tree.\n";
    for(int i = 0; i < size; i++){
        addNodeToTree(root, newNode(arrayOfValue[i]));
    }
    cout << "Finish Build Tree.\n";
}

void printTree1(struct Node* node){
    if(node == NULL){
        return;
    }
    printTree1(getLeftChild(node));
    cout << getValue(node) << "\t";
    printTree1(getRightChild(node));
}
void printTree2(struct Node* node){
    if(node == NULL){
        return;
    }
    cout << getValue(node) << "\t";
    printTree2(getLeftChild(node));
    printTree2(getRightChild(node));
}
void printTree3(struct Node* node){
    if(node == NULL){
        return;
    }
    printTree3(getLeftChild(node));
    printTree3(getRightChild(node));
    cout << getValue(node) << "\t";
}

void clearTree(struct Node* node){
    if(node == NULL){
        return;
    }
    clearTree(getLeftChild(node));
    clearTree(getRightChild(node));
    cout << "Delete: " << getValue(node) << endl;
    if(node == root){
        delete root;
    }
    delete node;
}

int main(){

    BuildTreeFromArray(new int[]{5, 3, 2, 4, 9, 7, 10}, 7);
    cout << "Start print:" << endl;
    cout << "First printing method:" << endl;
    printTree1(root);
    cout << endl;
    cout << "Second printing method:" << endl;
    printTree2(root);
    cout << endl;
    cout << "Third printing method:" << endl;
    printTree3(root);
    cout << endl;

    cout << "Start delete: " << endl;
    clearTree(root);


    return 0;
}