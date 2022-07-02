// تستخدم للتفريق بين الخصائص الموجودة في هذا الهيكل مع خصائص موجودة في هيكل أخر في ملف رأس آخر إذا كانت هذه الخصائص من نفس الاسم
namespace ds{

    // تستخدم إذا أردنا التبديل بين أنواع البيانات بسهولة عند العمل أو التجريب أي أن نوع بياناتها هو النوع الذي يتم إرساله عند تعريف متغير يراد استخدامه
    template <class T>
    struct Node{

        T val;
        Node* next;

    };

    template <class P>
    class Vector{

        public:
        void add(P Value);
        ~Vector();
        ds::Node<P>* getRoot();
        protected:
        ds::Node<P>* root = nullptr;

    };

    template <class P>
    void Vector<P>::add(P Value){

        ds::Node<P>* newNode = new Node<P>;
        newNode->val = Value;
        newNode->next = nullptr;
        if(root == nullptr){
            newNode->next = nullptr;
            root = newNode;
            return;
        }
        newNode->next = root;
        root = newNode;

    }

    template <class P>
    ds::Node<P>* Vector<P>::getRoot(){

        return root;

    }

    template <class P>
    Vector<P>::~Vector(){
        while(root != nullptr){
            ds::Node<P>* temp = root;
            root = root->next;
            delete temp;
        }
    }

}