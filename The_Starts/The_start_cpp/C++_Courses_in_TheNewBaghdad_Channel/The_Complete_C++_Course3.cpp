#include <iostream>
// getline لاستخدام الدالة
#include <string>
// للتعامل مع الملف
#include <fstream>
// /Linked list لاستخدام الـ
#include <vector>
using namespace std;

// للتنسيق والتجميل ---
#define FILE_NAME "data.txt"
// 
#define BIN_NAME "data.bin"

// للتنسيق والتجميل ---
enum class Options {Add = 1, View = 2};

typedef struct{
    string name;
    double salary;
    string position;
} Employee;

// For text file
// لإدخال النص الذي يريده المستخدم وهي تستقبل معاملان اسم الملف والنص الذي أدخله المستخدم
void AddTextToFile(string text, string filePath){
    // إذا حصل خطأ بهذه الطريقة لا يحدث كراش وإنما يستمر بشكل طبيعي وهذا مهم جدا
    try{
        // لتعريف الملف والسماح بالإدخال عليه
        ofstream MyFile;
        // لفح الملف والسماح بالكتابة عليه والكتابة دون مسح المكتوب
        MyFile.open(filePath, ios::out | ios::app);
        // للكتابة في الملف
        MyFile << text + "\n";
        // لإغلاق الملف وهذا ضروري جدا
        MyFile.close();
    }
    // هي ما ينفذ لو كان هناك خطأ
    catch(exception& e){
        cout << "--> Standard exception: " << e.what() << endl;
    }
}

// تم تعريف هذه الدالة لأنها دالة القراءة والقراءة تكون سطرا سطرا أي أن كل سطر يعبر عن متغير لهذا لزم استخدام هذا النوع لأنه عبارة عن مجموعة من الكائنات متصلة مع بعضها البعض
vector<string> readFromTextFile(string filepath){
    // الكائن الذي سيخزن السطور (الكتئنات)
    vector<string> filelines;
    // يعبر عن السطر
    string line;
    try{
        // لتعريف الملف والسماح بالإخراج  منه
        ifstream MyFile(filepath);
        // لفحص إذا كان هناك ملف أو لا
        if(MyFile.is_open()){
            // للمرور عل كل سطور الملف ونفلها
            while(getline(MyFile, line)){
                // لاستقبال السطور وتخزينها
                filelines.push_back(line);
            }
            MyFile.close();
        }
        else{
            // تعرض إدا لم يكن هناك ملف لإقراءته أي أنه يحدث خطأ
            cout << "--> Unable to open file";
        }
    }
    catch(exception& e){
        cout << "--> Standard exception: " << e.what() << endl;
    }

    return filelines;
}

// دالة العمل
void AddToText(){
    // النص الذي سيدخله المستخدم
    string text;
    // مستقبل اختيار الحالة
    int options;
    while(true){
        cout << "Choose case:\n1- for write\n2- for read\nany other option to exit\n";
        // لاستقبال المدخلات
        cin >> options;
        // فحص الاختيار
        if(options == (int)Options::Add){
            cout << "Write text: " << endl;
            // cin باستقبال الجمل دون التعارض مع قيود الدالة getline للسماح للدالة
            std::cin >> std::ws;
            // لقراءة النص الذي أدخل المستخدم
            getline(cin, text);
            // لإدخال النص في الملف
            AddTextToFile(text, FILE_NAME);
        }
        else if(options == (int)Options::View){
            cout << "\n============= FileContent =============\n";
            // تعريف متغير من هذا النوع لأنه سيستقبل قيمة من نفس النوع وهي السطور المكتوبة في الملف
            vector<string> fileLines = readFromTextFile(FILE_NAME);
            // للمرور على النص سطر سطر من أول سطر مكتوب وحتى آخر سطر
            for(auto line = fileLines.begin(); line != fileLines.end(); line++){
                //
                cout << *line << endl;
            }
        }
        else{
            break;
        }
    }
}

// For binary file
void addToBin(Employee employee, string filePath){
    try{
        ofstream MyFile;
        MyFile.open(filePath, ios::out | ios::binary);
        // 
        MyFile.write((char*)&employee, sizeof(employee));
        MyFile.close();
    }
    catch(exception& e){
        cout << "--> Standard exception: " << e.what() << endl;
    }
}

vector<Employee*> readBinFile(string filePath){
    // الكائن الذي سيخزن السطور (الكتئنات)
    vector<Employee*> fileEmployee;
    // يعبر عن السطر
    string line;
    try{
        // لتعريف الملف والسماح بالإخراج منه ووضع المؤشر في آخر الملف
        ifstream MyFile(filePath, ios::in | ios::binary  | ios::ate);
        // لفحص إذا كان هناك ملف أو لا
        if(MyFile.is_open()){
            // لمعرفة عدد البايت في الملف ios::ate أي أخبرني بمكان المؤشر واستخدمناه مع الأمر
            streampos size = MyFile.tellg();
            // لتخزين جميع بيانات الملف
            char* memblock = new char[size];
            // لإعادة المؤشر إلى بداية الملف
            MyFile.seekg(0, ios::beg);
            // لقراءة جميع بيانات الملف
            MyFile.read(memblock, size);
            MyFile.close();
            long long byteIndex = 0;
            while(byteIndex < size){
                Employee* employee = (Employee*)(memblock + byteIndex);
                fileEmployee.push_back(employee);
                byteIndex += sizeof(Employee);
            }
        }
        else{
            // تعرض إدا لم يكن هناك ملف لإقراءته أي أنه يحدث خطأ
            cout << "--> Unable to open file";
        }
    }
    catch(exception& e){
        cout << "--> Standard exception: " << e.what() << endl;
    }

    return fileEmployee;
}

void addToBin(){
     // النص الذي سيدخله المستخدم
    string text;
    // مستقبل اختيار الحالة
    int options;
    while(true){
        cout << "Choose case:\n1- for write\n2- for read\nany other option to exit\n";
        // لاستقبال المدخلات
        cin >> options;
        // فحص الاختيار
        if(options == (int)Options::Add){
            Employee employee;
            cout << "employee name: " << endl;
            std::cin >> std::ws;
            // لقراءة الاسم الذي أدخل المستخدم
            getline(cin, employee.name);

            cout << "employee position: " << endl;
            // لقراءة الموقع الذي أدخل المستخدم
            getline(cin, employee.position);

            cout << "employee salary: " << endl;
            cin >> employee.salary;

            // لإدخال النص في الملف
            addToBin(employee, BIN_NAME);
        }
        else if(options == (int)Options::View){
            cout << "\n============= FileContent =============\n";
            // تعريف متغير من هذا النوع لأنه سيستقبل قيمة من نفس النوع وهي السطور المكتوبة في الملف
            vector<Employee*> fileLines = readBinFile(BIN_NAME);
            // للمرور على النص سطر سطر من أول سطر مكتوب وحتى آخر سطر
            for(auto line = fileLines.begin(); line != fileLines.end(); line++){
                Employee* employee = *line;
                cout << "employee->name: " << employee->name << endl;
                cout << "employee->position: " << employee->position << endl;
                cout << "employee->salary: " << employee->salary << endl;
                cout << "\n-----------------\n";
            }
        }
        else{
            break;
        }
    }
}

int main(){

    // AddToText();
    addToBin();

    return 0;
}