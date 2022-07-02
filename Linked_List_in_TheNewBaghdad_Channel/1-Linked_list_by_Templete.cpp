#include <iostream>
// هي أمكان لكائنات متعددة  في الذاكرة لكل كائن مؤشر إما يؤشر على لا شيء وإما يؤشر على أمكان أخرى في الذاكرة ومهمتها الربط بين القيم في الذاكرة Linked List & Stack الـ
// ملاحظة: يجب تحرير(حذف) الذاكرة من الكائنات المنشئة بستخدام هذه الطريقة
// يتم ترتيب الكائنات على حسب أولويتها في التعريف أي الكائن الذي عرف أولا هو الأساس
#include "1-LinkedList.hh"
using namespace std;

int main(){

    ds::Vector<int> vec;
    vec.add(45);
    vec.add(84);
    vec.add(61);

    ds::Node<int>* currentNode = vec.getRoot();
    while(currentNode != nullptr){
        cout << currentNode->val << endl;
        currentNode = currentNode->next; 
    }

    return 0;
}