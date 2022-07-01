#include <iostream>
// هي أمكان لكائنات متعددة  في الذاكرة لكل كائن مؤشر إما يؤشر على لا شيء وإما يؤشر على أمكان أخرى في الذاكرة ومهمتها الربط بين القيم في الذاكرة Linked List & Stack الـ
// ملاحظة: يجب تحرير(حذف) الذاكرة من الكائنات المنشئة بستخدام هذه الطريقة
// يتم ترتيب الكائنات على حسب أولويتها في التعريف أي الكائن الذي عرف أولا هو الأساس
#include "2-Stack_by_Inheritance.hh"
using namespace std;

int main(){

    ds::Stack<int> st;
    st.push(46);
    st.push(15);
    st.push(61);

    cout << st.pop() << "\t" << st.getSize() << endl;
    cout << st.pop() << "\t" << st.getSize() << endl;
    cout << st.pop() << "\t" << st.getSize() << endl;

    return 0;
}