#include <iostream>
// المكتبة المسؤولة عن التعامل مع الملفات
#include <fstream>
using namespace std;

int main(){

    //لإنشاء ملف والكتابة فيه
    ofstream fout;
    fout.open("test_file.txt");
    fout << "Hello How are you?";
    fout.close();

    // لقراءة ملف
    ifstream fin;
    fin.open("test_file.txt");
    char line[100];
    // لمعرفة إذا انتهى الملف أم لا
    while(!fin.eof()){
    // لنفل السطر المكتوبة في الملف ثم طباعتها
        fin.get(line, 100);
        cout << line << endl;
    }

    return 0;
}