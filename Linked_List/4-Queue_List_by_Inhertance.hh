#include "3-Double_Linked_List.hh"
namespace ds{
    template <class P>
    class Queue:protected DLinkedList<P>{
        public:
        void push(P value);
        P pull();
    };
    template <class P>
    void Queue<P>::push(P value){
        this->AddFront(value);
    }
    template <class P>
    P Queue<P>::pull(){
        DNode<P>* node = this->getRear();
        if(node == nullptr){
            return -1;
        }
        P value = node->val;
        this->rear = this->rear->right;
        if(this->rear == nullptr){
            this->rear = nullptr;
            this->front = nullptr;
            }
        this->rear->left = nullptr;
        delete node;
        return value;
    }
}