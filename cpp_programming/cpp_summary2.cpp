#include <iostream>
using namespace std;

// function (الدوال) تيم استخدام الدوال لعدة أسباب
// 1- لأنها تجعل المشروع يعمل بكفاء أكبر
// 2- وهذا أمر مهم في كل برنامج (main) تقليل الأسطر في الدالة الرئيسية
// 3- لتسهيل قراءة الكود
// للدوال نوعان دوال مرجعة يتم إنشاؤها بواسطة أنواع البيانات المتنوعة كالدالة الرئيسية
// (void) ودوال غير مرجعة يتم إنشاؤها بواسطة الكلمة الأساسية
// ملاحظة يمكن إنشاء دالة أسفل الدالة الرئيسية لكن بشرط تعريف اسم ونوع الدالة فوق الدالة الرئيسية

// مثال على دالة غير مرجعة
void B(){
    for(int B1 = 0; B1 < 3; B1++){
        cout << "Hello" << endl;
    }
}

// (operators, arguments, parameters) يمكن لأي دالة أن تقوم باستقبال معاملات أو مشغلات وهذه تسمى بالـ
// ملاحظة المعاملات يتم إنتهاء حياتها بنتهاء الدالة
// مثال على دالة مرجعة تستقبل معاملات
int C(int C1, int C2){
    return C1 + C2;
}

// (overloading in function) ويكون هذا الأمر عند إنشاء مجموعة من الدوال لها نفس الاسم والوظيفة وتختلف في عدد المعاملات التي تستقبلها
// (overloading) مثال على
double D(double D1, double D2){
    return D1 + D2;
}

double D(double D1, double D2, double D3){
    return D1 + D2 + D3;
}

double D(double D1, double D2, double D3, double D4){
    return D1 + D2 + D3 + D4;
}

int main(){

    B();

    // int CC = C(5, 6);
    // cout << CC << endl;
    cout << C(5, 6) << endl;

    cout << D(1.5, 5, 9.4, 46) << endl;
    cout << D(9.4, 46) << endl;
    cout << D(1.5, 5, 46) << endl;

    return 0;
}