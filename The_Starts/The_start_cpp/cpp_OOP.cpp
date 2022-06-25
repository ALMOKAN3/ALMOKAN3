#include <iostream>
#include <string.h>
using namespace std;

/*
    _ OOP ماهي وما فائدتها?
        هي طريقة لترتيب الكود الخاص بك عبر إنشاء مجموعة من الفئات والهياكل
        من فوائدها أنها تجعل البرنامج أسهل في القراءة والتعديل وهذا يساعد على عمل الفريق أكثر
    _ (Object) ما هو الكائن وعلى ماذا يحتوي?
        كل شيء بمعنى شيء يعتبر كائن
    _ مثلا السيارة (Properties) كل كائن له خصائص معينة وهذا يسمى بالـ:
        لها نوع وسعر ومالك ومسافة قد سارتها كل هذه الأمور تعتبر خصائص
        Type = "BMW"
        Price = 10000$
        MilesDrive = 105
        Owner = "Ahmed"
    _ مثلا السبارة أيضا (Methodes) وأيضا لكل كائن طرق أو مناهج يسير عليها:
        لها طرق عدة منها طباعة السعر واسم المالك
        GetPrice();
        GetOwner();
    _ شكل مثال السيارة بالأكواد:
        public class Car{
            string Type;
            double Price;
            double MilesDrive;
            string Owner;
            double GetPrice(){
                double NewPrice = Price - (MilesDrive * 100);
                return NewPrice;
            }
            string GetOwner(){
                return Owner;
            }
        }
    _ لتعريف كائن باستخدام هذه الفئة بالكود: 
        Car car1 = new Car();
            car1.Type = "BMW";
            car1.Price = 10000;
            car1.MilesDrive = 105;
            car1.Owner = "Ahmed";
*/
/* structures يتم استخدام الهياكل إذا أردنا إنشاء كائنات لها نفس الخصائص */
// مثال على السيارة باستخدام الهياكل:
struct Car{
    int number;
    int year;
    char name[8];
    string Owner;
}BMWCar; // ملاحظة يجب وضع فاصلة منقوطة بعد الأقواس المجعدة للهياكل والبيانات

// مثال على فئة الطالب البيانات العامة والخاصة:
class Student{
    // تعني أن كل البيانات التي تأتي بعدها لا يمكن الوصول إليها من خارج هذه الفئة private
    private:
    int Password;
    void AddPassword(int Password){
        this->Password = Password;
    }

    // تعني أن كل البيانات التي تأتي بعدها يمكن الوصول إليها من خارج هذه الفئة public
    public:
    // الخصائص
    int StuID;
    string StuName;

    // الطرق
    void AddIDName(int StuID, string StuName){
        // تعني أن هذا المتغير هو ليس في هذه الدالة وإنما هو موجود في الفئة بشكل عام this->
        this->StuID = StuID;
        this->StuName = StuName;

        // encapsulation التغليف
        AddPassword(000000000);
    }
};

// construction(constructuer) and destroy(distractuer) البناء والتدمير
class constdes{
    public:
    int number;
    double price;
    // تستخدم لتجعل استقبال القيم يكون مترافقا مع إنشاء الكائن (name of class اسم الفئة)
    constdes(int number, double price){
        this->number = number;
        this->price = price;
    }
    // تستخدم لتدمير الكائن ~ (name of class اسم الفئة)
    ~ constdes(){
        cout << number << "\t/\t" << price << "\t/\tthe class deid" << endl;
    }
};

// inheritance الوراثة
// تسنخدم الوراثة لترث إحدى الفئات خواص فئة أخرى
// مثال على فئة ترث الخواص العامة فقط لفئة أخرى:
class school{
    public:
    string NameOfSchool;
};
class teacher : public school{
    public:
    int TeacherAge;
    int TeacherYearExper;
};

// overwriting
// تستخدم عندما ترث فئة من فئة أخرى ونريد إنشاء طريقة لها نفس اسم الطريقة التي موجودة في الفئة المورثة
class mother{
    public:
    string MotherColorHair;
    void PrintColorHair(){
        cout << MotherColorHair << endl;
    }
};
class girl : public mother{
    public:
    int GirlAge;
    string GirlColorHair;
    void PrintColorHair(){ // overwriting
        cout << GirlColorHair << endl;
    }
};

// aggregation التجميع
// يستخدم عند تعريف متغير داخل فئة من نوع فئة تم إنشاؤها سابقا

class adminType{
    public:
    string adminTypeName;
};
class users{
    public:
    string userName;
    string userpassword;
    adminType type;
};

// الدوال والفئات

class divresult{
    public:
    int div;
    int divRemain;
};
divresult Div(int number1, int number2){
    divresult result;
    result.div = number1 / number2;
    result.divRemain = number1 % number2;

    return result;
}

// static varibals and static methods المتغيرات الثابتة والطرق الثابتة
// تستخدم في الفئات عندما يكون هناك متغير ثابت أو طريقة ثابتة بالنسبة لكل الكائنات الننشأ من هذه الفئة

class men{
    public:
    int age;
    static string type;
    static void print(){
        cout << " => I'm man" << endl;
    }
};
string men::type = "man";

int main(){
    // Car BMWarr[any value] أيضا على الشكل Car ويمكن تعريف مصفوفة بنوع البيانات الجديد (Car BMW) الآن بالشكل Car يمكن تعريف متغير من نوع البيانات
    BMWCar.number = 5197;
    BMWCar.year = 2020;
    strcpy(BMWCar.name, "BMW");
    BMWCar.Owner = "Ahmed";
    cout << BMWCar.number << "\t/\t" << BMWCar.name << "  " << BMWCar.year << "  /\t" << BMWCar.Owner << endl;

    Student Student1;
    int ID = 28;
    string name = "Ahmed";
    Student1.AddIDName(ID, name);
    cout << Student1.StuID << "\t/\t" << Student1.StuName << endl;

    constdes constructiondestroy = constdes(15, 15.789);

    teacher teacher1;
    teacher1.TeacherAge = 35;
    teacher1.TeacherYearExper = 8;
    teacher1.NameOfSchool = "Almotanabi";
    cout << teacher1.TeacherAge << "\t/\t" << teacher1.TeacherYearExper << "\t/\t" << teacher1.NameOfSchool << endl;

    girl Girl1;
    Girl1.GirlAge = 14;
    Girl1.GirlColorHair = "red";
    Girl1.MotherColorHair = "black";
    Girl1.PrintColorHair();

    users myUser;
    myUser.userName = "Ahmed";
    myUser.userpassword = "123456";
    myUser.type.adminTypeName = "admin";
    cout <<"Username is: " << myUser.userName <<  ", type is: " << myUser.type.adminTypeName << endl;

    divresult myresult = Div(50, 3);
    cout << "Div: " << myresult.div << " , Remain: " << myresult.divRemain << "\t=>\t" << myresult.div << "." << myresult.divRemain << endl;
    
    men man1;
    man1.age = 24;
    cout << "age is: " << man1.age << "type is: " << man1.type;
    men::print();
    men man2;
    man2.age = 29;
    cout << "age is: " << man2.age << "type is: " << man2.type;
    men::print();




    return 0;
}