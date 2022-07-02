#include <iostream>
// هي أمكان لكائنات متعددة  في الذاكرة لكل كائن مؤشران عن يمينه وعن يساره إما يؤشران على لا شيء وإما يؤشران على أمكان أخرى في الذاكرة ومهمتها الربط بين القيم في الذاكرة Double Linked List الـ
// ملاحظة: يجب تحرير(حذف) الذاكرة من الكائنات المنشئة بستخدام هذه الطريقة
// Double Linked List و Binary Tree الفرق بين الـ:
// أما القائمة المزدوجة فهي ليست مرتبة ولا أساس لها والقيم المتصلة بالكائن المنشأ أولا لا يوجد ترتيب لها
// الشجرة تكون مرتبة فأساس الشجرة يجب أن يكون الرقم الأوسط وماعلى يمينه أكبر منه وما على يساره أصفر منه ويتكرر الأمر بنفس الطريقة
#include "3-Double_Linked_List.hh"
using namespace std;

int main(){

   {
        ds::DLinkedList<int> dLinkedList;
        dLinkedList.AddRear(12);
        dLinkedList.AddRear(45);
        dLinkedList.AddRear(71);
        dLinkedList.AddFront(48);
        dLinkedList.AddFront(31);
        dLinkedList.AddFront(61);

        ds::DNode<int>* temp = dLinkedList.getRear();
        while(temp != nullptr){
            cout << temp->val << endl;
            temp = temp->right;
        }

   }

    return 0;
}