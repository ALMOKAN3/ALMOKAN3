#include "1-LinkedList.hh"
namespace ds{
    template <class P>
    class Stack:public Vector<P>{
        public:
        void push(P value);
        P pop();
        int getSize();
        private:
        int size = 0;
    };

    template <class P>
    void Stack<P>::push(P value){
        this->add(value);
        size = size + 1;
    }

    template <class P>
    P Stack<P>::pop(){
        if(size == 0){
            return 1;
        }
        ds::Node<P>* temp = this->root;
        this->root = this->root->next;
        P val = temp->val;
        delete temp;
        size = size - 1;

        return val;
    }

    template <class P>
    int Stack<P>::getSize(){
        return size;
    }
}