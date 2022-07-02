#include <iostream>
using namespace std;

#define size 5 // => static int size = 5; || const int size = 5;

int sub(int x, int y){
    return x - y;
}
// function pointer
typedef int (*funptr)(int, int);
void print(funptr varfunptr){
    int r = varfunptr(45, 94);
    cout << r << endl;
}

// classes
// تتكون الفئات من قسمين:
// 1- header
class Rectangle{
    public:
    // Properties
    double height;
    double width;
    // methods
    double area();
    void setValue(double height, double width);
    //constructor method وهي تعمل مباشرة عند تعريف الكائن
    Rectangle();
    // destructor method وهي لتدمر (لحذف) الكائن
    ~Rectangle();
    // overloading operator
    Rectangle operator+(const Rectangle& rect);
    private:
};
// 2- implementation
double Rectangle::area(){
    // setValue() أو عندما يكون هناك خاصية تملك نفس اسم متغير في إحدى الدوال نستخدمها للتفريق بين خاصية الفئة ومتغير الدالة كما في الدالة area() تستخدم إما عند استدعاء خاصية لفئة معينة من داخل إحدى الدوال كما في الدالة   this->
    double area = this->height * this->width;
    return area;
}
void Rectangle::setValue(double height, double width){
    this->height = height;
    this->width = width;
}
Rectangle::Rectangle(){
    cout << "Rectangle is created \n";
}
Rectangle::~Rectangle(){
    cout << "Rectangle is dectroy \n";
}
Rectangle Rectangle::operator+(const Rectangle& rect){

    Rectangle bigArea; 
    bigArea.width = this->width + rect.width;
    bigArea.height = this->height + rect.height;
    return bigArea;

}

int main(){

    int x = -2147483648, y = 2147483647;
    // تقبل الأرقام الموجبة والسالبة
    signed int z = -48513;
    // تقبل الأرقام الموجبة فقط
    unsigned int r = 4294967295;
    cout << "the biggest value in signed integer data type in C++ is: " << x << endl;
    cout << "the smallest value in integer data type in C++ is: " << y << endl;
    cout << "the biggest value in unsigned integer data type in C++ is: " << r << endl;
    cout << y - r << "\t\t-" << r - y << endl;

    int size1; // 4 bayte
    double size2; // 8 bayte
    float size3; // 4 bayte
    bool size4; // 1 bayte
    char size5; // 1 bayte
    long size6; // 4 bayte
    short size7; // 2 bayte
    wchar_t size8; // big char 2 bayte
    // لطباعة حجم المتغير في الذاكرة ويكون بالبايت
    cout << sizeof(size1) << "\t\t" << sizeof(size2) << "\t\t" << sizeof(size3) << "\t\t" << sizeof(size4) << "\t\t" << sizeof(size5) << "\t\t" << sizeof(size6) << "\t\t" << sizeof(size7) << "\t\t" << sizeof(size8) << endl;

    // لتغير اسم نوع بيانات إلى اسم خاص
    typedef long long llong;
    llong num = 151654;
    cout << num << endl;

    // طرق أخرى لإعطاء المتغير قيمة
    int number1 (5), number2 {9};
    cout << number1 << "\t\t" << number2 << endl;

    // إذا لم يكن نوع المتغير معروف
    auto result = number1 + number2;
    // typeid(name of varibal).name() لمعرفة نوع بيابات المتغير
    cout << result << "  DataType is =>  " << typeid(result).name() << endl;

    // decltype(name of varibal) لتعريف متغير بنفس نوع البيانات لمتغير آخر
    decltype(number1) number3 = 8;
    cout << number3 << "  DataType is =>  " << typeid(number3).name() << endl;

    // يمكن تخزين قيم في متغير غبر نظام العد السادس عشري
    int data1 = 0xb5a1;
    cout << data1 /* لطباعة القيمة السادس عشرية << "  it's value by hexadecimal =>  0x" << std::hex << data1*/ << endl;

    // يمكن تخزين قيم في متغير غبر نظام العد الثنائي
    // int data2 = 0b1101;
    // cout << std::hex << data2 << endl;

    // 16 Bit
    char16_t text1 = u'H';
    cout << text1;
    // 32 Bit
    char32_t text2 = U'I';
    cout << text2 << endl;

    int numbers[size] = {15, 78, 21, 64, 74};
    for(int i = 0; i < size; i++){
        cout << numbers[i];
        if(i < size-1){
            cout << "\t-\t";
        }
    }
    cout << endl;

    // Dynamic memory
    // عند تعريف مؤشر أو متغير بهذه الطريقة يجب حذفه عند انتهاء البرنامج لكي لايبقى في الذاكرة
    int* ptr = new int[1];
    *ptr = 5;
    cout << "ptr = " << ptr << "\t*ptr = " << *ptr << "\t&ptr = " << &ptr << endl;
    // لحذف المؤشر
    delete ptr;
    int* pptr = new int[5];
    pptr[0] = 48;
    pptr[1] = 488;
    pptr[2] = 653;
    pptr[3] = 54;
    pptr[4] = 531;
    for(int i = 0; i < 5; i++){
        cout << "pptr[" << i << "] = " << pptr[i];
        if(i < 4){
            cout << " - ";
        }
    }
    // لحذف المصفوفات
    delete[] pptr;
    cout << endl;

    // lambda function
    auto add = [/*call by vallre write (=), call br refrence write (&), one call by value and other by refrence write (name of the one varibal, &name of the other varibal)*/](int a, int b) -> int{
        return a + b;
    };
    int varfun = add(48, 654);
    cout << varfun << endl;


    print(&sub);


    // ملاحظة:
    // إذا كان لدينا كائن وهو معرف من فئة أو من هيكل فعند استدعاء خواصه أو طرقه نكتب بعد اسمه (.) ثم اسم الخاصية أو الطريقة
    // إذا كان لدينا مؤشر وهو معرف من فئة أو من هيكل فعند استدعاء خواصه أو طرقه نكتب بعد اسمه (<-) ثم اسم الخاصية أو الطريقة

    // classes
    // لتأخير عملية التدمير حتى الخروج إلى خارج الأقواس
    {

        double areaResult = 0.0;
        Rectangle rect1;
        rect1.setValue(4.5, 9.5);
        areaResult = rect1.area();
        cout << "area of rectangle1: " << areaResult << endl;

        Rectangle rect2;
        rect2.setValue(8.4, 7.6);
        areaResult = rect2.area();
        cout << "area of rectangle2: " << areaResult << endl;
        
        // ولاستخدامه يجب تعريفه كدالة من نوع الفئة تستقبل متغير ثابت من نوع الفئة نفسها بإضافة (&) بعد نوع الفئة ويكون بعده رمز العملية التي سيقوم بها (operator) ولهذا لإجراء العمليات على الكائنات نحن بحاجة لاستخدام الـ overLoading لا يمكن إجراء العمليات على الكائنات وهذا الأمر يسمى
        Rectangle rect3;
        rect3 = rect1 + rect2;
        areaResult = rect3.area();
        cout << "area of rectangle1 + rectangle2: " << areaResult << endl;

        // (this->) هم المؤشر المعرف من فئة معينة عند استدعاء إحدى خواصه أو طرقه والـ overloading أمثال على الـ
        Rectangle* rectptr = new Rectangle;
        rectptr->setValue(4.1, 9.4);
        areaResult = rectptr->area();
        cout << "area of pointer rectangle: " << areaResult << endl;


    }

    





    // لإيقاء البرنامج شغالا عند التشغيل كي لا يغلق
    // system("pause");

    return 0;
}