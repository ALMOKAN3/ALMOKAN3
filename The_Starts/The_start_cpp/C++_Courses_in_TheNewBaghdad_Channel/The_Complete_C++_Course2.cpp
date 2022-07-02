#include <iostream>
using namespace std;

class Shape{
    
    public:
    Shape(int width, int height){
        cout << "Shape 1 created" << endl;
        this->width = width;
        this->height = height;
    }
    // في فئة واحدة constructor ملاحظة: يمكن أن يكون هناك أكثر من
    Shape(int width){
        cout << "Shape 2 created" << endl;
        this->width = width;
    }
    // هذا يعني أن أي فئة ترث هذه الفئة عليها أن يعدلها ويجب إعطاؤها قيمة هنا
    virtual int area() = 0;
    // أي أنه لايمكن لأحدالوصول لما بعدها إلا من داخل الفئة الأساسية أو فئة أخرى ورثة من هذه الفئة
    protected:
    int width, height;

};
// الوراثة تتم عندما تتشابه فئتين بالأعضاء
// المقصود بالأعضاء هو (الخصائص والطرق)
// عندما ترث فئة عن فئة أخرى يجب إعطاء الحالة التي سيتم وراثة الأعضاء عليها
// public: تورث الأعضاء كما هم في الفئة الأساسية
// protected: تورث الأعضاء على أنهم لا يمكن الوصول لهم من خارج الفئة إلا من فئة أخرى ورثتها
// ملاحظة: الخصائص التي تم تقييدها لا تورث
// عندما ترث فئة فئة أخرى يجب وضع نقطتان(:) بعد اسم الفئة ثم الحالة التي ستحدد كيف ستصل الأعضاء وما هي حالتهم وأخيرا اسم الفئة التي سترث أعضاءها
class Rectangle: public Shape{
    public:
    int area(){
        return this->height * this->width;
    }
    // وتمرير قيم أو متغيرات تحوي قيم لها constructor يأخذ معاملات يجب تحديد اسم الفئة الذي هو نفسه اسم الـ constructor عندما ترث فئة فئة أخرى لديها
    Rectangle(int width, int height):Shape(width, height){
        cout << "Rectangle created" << endl;
    }
};

class Triangle: public Shape{
    public:
    int area(){
        return this->height * this->width / 2;
    }
    Triangle(int width, int height):Shape(width, height){
        cout << "Triangle created" << endl;
    }
};

class Square: public Shape{
    public:
    int area(){
        return this->width * this->width;
    }
    Square(int width):Shape(width){
        cout << "Square created" << endl;
    }
};

// Design Pattern used enum
// وهي حلول لمشكلات متكررة مثل أننا لا نريد إنشاء الفئات ثم حذفها كلها نريد فقط إنشاء الفئة التي نحن نحتاجها ثم حذفها
enum class ShapeDraw{Rectangle = 1, Triangle = 2, Square = 3};
class ShapeFactory{
    public:
    Shape* getShape(ShapeDraw shapeDraw, int height, int width){
        Shape* shape = nullptr;
        switch(shapeDraw){
            case ShapeDraw::Rectangle:
            shape = new Rectangle(height, width);
            break;
            case ShapeDraw::Triangle:
            shape = new Triangle(height, width);
            break;
            case ShapeDraw::Square:
            shape = new Square(width);
            break;
            default:
            shape = nullptr;
            break;
        }
        return shape;
    }
};

// 
class circal{
    double r;
    public:
    circal(){
        cout << "constructor" << endl;
    }
    double area(double r){
        this->r = r * (22/7) / 2;
        return this->r;
    }
    ~circal(){
        cout << "destructor" << endl;
    }
};

int main(){

    ShapeFactory shapeFactory;
    int drawIndex = 0;
    while(true){
        cout << "Choose Case:\n1- for Rectangle\n2- for Triangle\n3- for Square\nOr choose any nother number to exit";
        cin >> drawIndex;
        Shape* shape = shapeFactory.getShape((ShapeDraw)drawIndex, 10, 15);
        if(shape == nullptr){
            break;
        }
        cout << shape->area() << endl;
        delete shape;
    }

    // تعريف كائن عادي بواسطة الفئة
    {
        circal c;
        double cArea = c.area(7);
        cout << "area of circal is: " << cArea << endl;
        // تعمل دالتا البناء والهدم بشكل طبيعي ودون أي تدخل في الكائن
    }

    // تعريف مؤشر بواسطة الفئة
    {
        circal* cir = new circal;
        double cArea = cir->area(6);
        cout << "area of circal is: " << cArea << endl;
        // دالة البناء تعمل بشكل طبيعي أما دالة الهدم فهي لا تعمل مع المؤشرات بشكل طبيعي لأن المؤشرات يتم تخزينها في مكان في الذاكرة على المستخدم محوه يدويا منها على الشكل التالي:
        delete cir;
        // الآن أصبحت دالة الهدم تعمل
    }


    return 0;
}