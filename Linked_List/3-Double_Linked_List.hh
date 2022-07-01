#include <iostream>
using namespace std;
namespace ds{
    template <class T>
    struct DNode{
        
        T val;
        DNode* right;
        DNode* left;

        DNode(T data){
            val = data;
            right = nullptr;
            left = nullptr;
        }

    };

    template <class P>
    class DLinkedList{
        public:
        void AddFront(P value);
        void AddRear(P value);
        DNode<P>* getFront();
        DNode<P>* getRear();
        ~DLinkedList();

        protected:
        DNode<P>* front = nullptr;
        DNode<P>* rear = nullptr;

    };
    template <class P>
    void DLinkedList<P>::AddFront(P value){
        DNode<P>* newNode = new DNode<P>(value);
        if(front == nullptr && rear == nullptr){
            front = newNode;
            rear = newNode;
            return;
        }
        newNode->left = front;
        front->right = newNode;
        front = newNode;
    }
    template <class P>
    void DLinkedList<P>::AddRear(P value){
        DNode<P>* newNode = new DNode<P>(value);
        if(front == nullptr && rear == nullptr){
            front = newNode;
            rear = newNode;
            return;
        }
        newNode->right = rear;
        rear->left = newNode;
        rear = newNode;
    }
    template <class P>
    DNode<P>* DLinkedList<P>::getFront(){
        return front;
    }
    template <class P>
    DNode<P>* DLinkedList<P>::getRear(){
        return rear;
    }
    template <class P>
    DLinkedList<P>::~DLinkedList(){
        while(rear != nullptr){
            DNode<P>* temp = rear;
            rear = rear->right;
            if(rear != nullptr){
                rear->left = nullptr;
            }
            cout << "Delete: " << temp->val << endl;
            delete temp;
            temp = rear;
        }
    }

}