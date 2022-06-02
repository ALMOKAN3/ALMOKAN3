// هذا يعني تضمين هذه المكتبة التي تحتوي على عدة وظائف مثل (cout) و (cin)
#include <iostream>
//
using namespace std;

// هذه هي الدالة الرئيسية التي تعمل أولا ولا يعمل أي كود مكتوب خارجها
int main(){

     // هذا هو عامل الإخراج
     cout << "مرحبا" << endl;
     
     //Data Types and varibles أنواع البيانات و المتغيرات
     //عند تسمية المتغير يجب أن تكون أول خانة حرف أو شرطة سفلية لا غير
     
     // هذا هو النوع الذي يعرف متغيرات تخزن بيانات لأعداد صحيحة فقط
     int age = 18;
     cout << age << endl;
     
     // هذان النوعان يعرفان متغيرات تخزن بينات لأعداد ذات فاصلة عشرية الفرق بين النوع الأول و النوع الثاني هو أن النوع الثاني يمكنه تخزين أعداد أكبر
     float num1 = 1.5683;
     double num2 = 5.86457537;
     cout << num1 << endl << num2;
     
     //هذا النوع يعرف متغيرات تخزن بيانات قيمتين (نعم/لا)
     bool result = true;
     cout << result << endl;
     
     // هذا النوع يعرف متقيرات تخزن بيانات لرموز و أخرف و هذه القيم توضع بين علامات تنصيص مفردة
     char character = 'a';
     cout << character << endl;
     
     // هذا ليس نوع رسمي و إنما هو عبارة عن "مصفوفة" من الأخرف و هي تعرف متغيرات تخزن نصوص و هذه القيم توضع بين علامات تنصيص مزدوجة
     string name = "mohmed";
     cout << name << endl;
     
     int input;
     // معامل الإدخال يأخذ قيمة من المستخدم و يحفظها في المتغير
     cout << "Enter number: ";
     cin >> input;
     cout << "your number is:  " << input << endl;
     
     //Math operators العمليات الحسابية
     
     double j = 4.0, k = 2.0, l;
     l = j + k;
     cout << "the plural: " << l << endl;
     l = j - k;
     cout << "the proposal: "<< l << endl;
     l = j * k;
     cout << "beating: "<< l << endl;
     l = j / k;
     cout << "division: "<< l << endl;
     l = j / ++k;
     cout << "remainder of the division: "<< l << endl;
     
     //conditional and logic operator الشروط و العمليات المنطقية
    //(if)(else if)(else)
     int m;
     cout << "What is your end result? ";
     cin >> m;
     if(m == 100){
         cout << "Congratulations on your achievement ^_^" << endl;
         }
     else if(m >= 90 && m < 100){
         cout << "Congratulation ~_~" << endl;
         }
     else if(m >= 70 && m < 90){
         cout << "Congratulations *_*" << endl;
         }
     else if(m >= 40 && m < 70){
         cout << "You are successful -_-" << endl;
         }
     else if(m >= 1 && m < 40){
         cout << "Unfortunately you fail ¡_¡" << endl;
         }
     else{
         
         if(m != 0){
             cout << "There is no such value" << endl;
             }
         else{
             cout << "Unfortunately" << endl;
             }
         }
         
         //(switch)(case)(defult)(break)
        int n;
        cout << "Enter number (1-5): ";
        cin >> n;
        switch(n){
            case 1:{
                cout << endl << "Hola" << endl;
            }break;
            case 2:{
                cout << endl << "Hello" << endl;
            }break;
            case 3:{
                cout << endl << "Hi" << endl;
            }break;
            case 4:{
                cout << endl << "bonjor" << endl;
            }break;
            case 5:{
                cout << endl << "Good morning" << endl;
            }break;
            defult:{
                cout << endl << "You did not enter a valid number" << endl;
            }break;
        }
        
        //loops التكرار
        //(while)
        int o = 1;
        while(o != 4){
            cout << o << endl;
            o++;
        }
        
        //(do)(while)
        int p = 1;
        do{
            cout << p << endl;
        }while(p != 1);
        
        //(for)
        for(int q = 0; q < 5; q++){
            cout << q << endl;
        }
        
        //(for{for})
        for(int r = 0; r < 5; r++){
            for(int s = 0; s <= r; s++){
                cout << "*";
            }
            cout << endl;
        }
        int t = 5, u = 0;
        while(t >= 0){
            while(u < t){
                cout << "*";
                u++;
            }
            u = 0;
            t--;
            cout << endl;
        }
        
        //(break)(continue)
        int v = 0;
        while(v < 5){
            if(v == 1){
                v++;
                continue;
            }
            if(v == 4){
                break;
            }
            cout << v << endl;
            v++;
        }
        
        //Arrays المصفوفات
        //(array)
        int w[2];
        w[0] = 28;
        w[1] = 38;
        cout << w[0] << "\t" << w[1] << endl;
        
        //(array)(for)
        float x[4] = {4.8, 5.8, 4.8, 2.8};
        for(int x1 = 0; x1 < 4; x1++){
            cout << x[x1] << "\t";
        }
        cout << endl;
        
        //(array)(constant size)(for)
        //const لجعل قيمة المتغير ثابتة لا يمكن تغيرها
        const int y = 3;
        int z[y] = {4, 8, 2};
        for(int z1 = 0; z1 < y; z1++){
            cout << z[z1] << "\t";
        }
        cout << endl;
        

    return 0;
}