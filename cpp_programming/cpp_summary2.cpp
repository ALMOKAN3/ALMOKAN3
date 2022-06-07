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
void function(){
    for(int B1 = 0; B1 < 3; B1++){
        cout << "Hello" << endl;
    }
}

// (operators, arguments, parameters) يمكن لأي دالة أن تقوم باستقبال معاملات أو مشغلات وهذه تسمى بالـ
// ملاحظة المعاملات يتم إنتهاء حياتها بنتهاء الدالة
// مثال على دالة مرجعة تستقبل معاملات
int parameterFunction(int C1, int C2){
    return C1 + C2;
}

// (overloading in function) ويكون هذا الأمر عند إنشاء مجموعة من الدوال لها نفس الاسم والوظيفة وتختلف في عدد المعاملات التي تستقبلها
// (overloading) مثال على
double overLoading(double overLoading1, double overLoading2){
    return overLoading1 + overLoading2;
}

double overLoading(double overLoading1, double overLoading2, double overLoading3){
    return overLoading1 + overLoading2 + overLoading3;
}

double overLoading(double overLoading1, double overLoading2, double overLoading3, double overLoading4){
    return overLoading1 + overLoading2 + overLoading3 + overLoading4;
}

// (polymorphism in function) يكون هذا الأمر عند إنشاء مجموعة من الدوال لها نفس الاسم والوظيفة وتختلف في نوع البيانات التي تعرف المعاملات
// (polymorphism) مثال على
int polymorphism(int polymorphismInt){
    return polymorphismInt + 5;
}

int polymorphism(double polymorphismDouble){
    return polymorphismDouble + 5;
}

// وهذا المتغير يمكن تعديل قيمتة أو استدعائه من أي مكان في البرنامج (global) هذا المتغير يسمى
int globalVar = 9;

int globalLocalVar(){
    // وهذا المتغير لا يمكن التعديل عليه من أي مكان في البرنامج وإنما يتم التعديل عليه من الدالة التي أنشئ فيها فقط (local) هذا المتغير يسمى
    int localVar = 1;
    cout << "Var local: " << localVar << "\t" << "var global: " << globalVar << endl;
    return 0;
}

void changeByValue(int number1);
void changeByRefrence(int &number2);

int arrayWithFunction(int arr[]);

int main(){

    function();
    cout << endl;

    int valueOfReturn = parameterFunction(5, 6);
    cout << valueOfReturn << endl;
    cout << parameterFunction(5, 6) << endl;
    cout << endl;

    cout << overLoading(1.5, 5, 9.4, 46) << endl;
    cout << overLoading(9.4, 46) << endl;
    cout << overLoading(1.5, 5, 46) << endl;
    cout << endl;

    cout << polymorphism(6.4) << endl;
    cout << polymorphism(13) << endl;
    cout << endl;

    globalLocalVar();
    cout << endl;

    int ByValueByRefrence = 5;
    changeByValue(ByValueByRefrence);
    cout << "By value: " << ByValueByRefrence << endl;
    changeByRefrence(ByValueByRefrence);
    cout << "By refrence: " << ByValueByRefrence << endl;
    cout << endl;

    int arr1[3] = {5, 9, 8};
    int arr2[3] = {6, 10, 81};
    cout << "arr1 max value: " << arrayWithFunction(arr1) << endl;
    cout << "arr2 max value: " << arrayWithFunction(arr2) << endl;
    cout << endl;

    int number = 5;
    // نضع الرمز (&) لتأشير على موقع المتغير في الذاكرة
    cout << "addres: " << &number << "\t" << "value: " << number << endl;
    int numberPointer = 8;
    // هذا المتغير يعتبر مؤشر فهو لا يملك قيمة خاصة وإنما يؤشر على موقع المتغير الثاني وباستعماله يمكن طباعة واستدعاء موقع وقيمة المتغير الثاني والتعديل على قيمته
    /*int *ptr*/int* ptr = &numberPointer;
    cout << "addres: " << ptr << "\t" << "value: " << *ptr << endl;
    *ptr = *ptr + 9;
    cout << "value after edit by pointer: " << numberPointer << endl;
    // يمكن عرض قيم أي مصفوفة باستخدام المؤشر لأن المصفوفات يتم ترتيب قيمهم بالترتيب فعند إضافة واحد لقيمة المؤشر ينتقل إلى التأشير إلى القيمة الثانية من المصفوفة
    int arrayPointer[3] = {46, 59, 78};
    int *pointerArray = &arrayPointer[0];
    cout << "array[0] = " << *pointerArray << "\t" << "array[1] = " << *(pointerArray+1) << "\t" << "array[3] = " << *(pointerArray+2) << endl;
    cout << endl;
    // أخيرا من الخطر استخدام المؤ شر بكثرة لأنه يعمل بشكل مباشر مع الذاكرة

    return 0;
}

// بواسطة هذه الدالة يتم أخذ نسخة من المتغير الممرر والتعديل غلى النسخة فقط
void changeByValue(int number1){
    number1 = number1 + 5;
    cout << number1 << endl;
}

// بواسطة هذه الدالة يتم الإشارة على مكان المتغير الممرر والتعديل على قيمته
void changeByRefrence(int &number2){
    number2 = number2 + 5;
    cout << number2 << endl;
}

// (function(array[]){array})
int arrayWithFunction(int arr[]){
    int max = arr[0];
    for(int i = 0; i < 3; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}