// هذا يعني تضمين هذه المكتبة التي تحتوي على عدة وظائف مثل (cout) و (cin)
#include <iostream>
//
using namespace std;

// هذه هي الدالة الرئيسية التي تعمل أولا ولا يعمل أي كود مكتوب خارجها
int main(){

     // هذا هو عامل الإخراج
     cout << "Hello" << endl;
     
     //Data Types and varibles أنواع البيانات و المتغيرات
     //عند تسمية المتغير يجب أن تكون أول خانة حرف أو شرطة سفلية لا غير
     
     // هذا هو النوع الذي يعرف متغيرات تخزن بيانات لأعداد صحيحة فقط
     int age = 18;
     cout << age << endl;
     
     // هذان النوعان يعرفان متغيرات تخزن بينات لأعداد ذات فاصلة عشرية الفرق بين النوع الأول و النوع الثاني هو أن النوع الثاني يمكنه تخزين أعداد أكبر
     float num1 = 1.5683;
     double num2 = 5.8645753;
     cout << num1 << endl << num2 << endl;
     
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
     
     double var1 = 4.0, var2 = 2.0, var3;
     var3 = var1 + var2;
     cout << "the plural: " << var3 << endl;
     var3 = var1 - var2;
     cout << "the proposal: "<< var3 << endl;
     var3 = var1 * var2;
     cout << "beating: "<< var3 << endl;
     var3 = var1 / var2;
     cout << "division: "<< var3 << endl;
     var3 = var1 / ++var2;
     cout << "remainder of the division: "<< var3 << endl;
     
     //conditional and logic operator الشروط و العمليات المنطقية
    //(if)(else if)(else)
     int conditional1;
     cout << "What is your end result? ";
     cin >> conditional1;
     if(conditional1 == 100){
         cout << "Congratulations on your achievement ^_^" << endl;
         }
     else if(conditional1 >= 90 && conditional1 < 100){
         cout << "Congratulation ~_~" << endl;
         }
     else if(conditional1 >= 70 && conditional1 < 90){
         cout << "Congratulations *_*" << endl;
         }
     else if(conditional1 >= 40 && conditional1 < 70){
         cout << "You are successful -_-" << endl;
         }
     else if(conditional1 >= 1 && conditional1 < 40){
         cout << "Unfortunately you fail ¡_¡" << endl;
         }
     else{
         
         if(conditional1 != 0){
             cout << "There is no such value" << endl;
             }
         else{
             cout << "Unfortunately" << endl;
             }
         }
         
         //(switch)(case)(defult)(break)
        int conditional2;
        cout << "Enter number (1-5): ";
        cin >> conditional2;
        switch(conditional2){
            case 1:{
                cout << "Hola" << endl;
            }break;
            case 2:{
                cout << "Hello" << endl;
            }break;
            case 3:{
                cout << "Hi" << endl;
            }break;
            case 4:{
                cout << "bonjor" << endl;
            }break;
            case 5:{
                cout << "Good morning" << endl;
            }break;
            default:{
                cout << "You did not enter a valid number" << endl;
            }break;
        }
        
        //loops التكرار
        //(while)
        int loop1 = 1;
        while(loop1 != 4){
            cout << loop1 << endl;
            loop1++;
        }
        
        //(do)(while)
        int loop2 = 1;
        do{
            cout << loop2 << endl;
        }while(loop2 != 1);
        
        //(for)
        for(int loop3 = 0; loop3 < 5; loop3++){
            cout << loop3 << endl;
        }
        
        //(for{for})
        for(int starLoopFor1 = 0; starLoopFor1 < 5; starLoopFor1++){
            for(int starLoopFor2 = 0; starLoopFor2 <= starLoopFor1; starLoopFor2++){
                cout << "*";
            }
            cout << endl;
        }
        //(while{while})
        int starLoopWhile1 = 5, starLoopWhile2 = 0;
        while(starLoopWhile1 >= 0){
            while(starLoopWhile2 < starLoopWhile1){
                cout << "*";
                starLoopWhile2++;
            }
            starLoopWhile2 = 0;
            starLoopWhile1--;
            cout << endl;
        }
        
        //(break)(continue)
        int loopBreakContinue = 0;
        while(loopBreakContinue < 5){
            if(loopBreakContinue == 1){
                loopBreakContinue++;
                continue;
            }
            if(loopBreakContinue == 4){
                break;
            }
            cout << loopBreakContinue << endl;
            loopBreakContinue++;
        }
        
        //Arrays المصفوفات
        //(array)
        int array1[2];
        array1[0] = 28;
        array1[1] = 38;
        cout << array1[0] << "\t" << array1[1] << endl;
        
        //(array)(for)
        float array2[4] = {4.8, 5.8, 4.8, 2.8};
        for(int array2ForLoop = 0; array2ForLoop < 4; array2ForLoop++){
            cout << array2[array2ForLoop] << "\t";
        }
        cout << endl;
        
        //(array)(constant size)(for)
        //const لجعل قيمة المتغير ثابتة لا يمكن تغيرها
        const int constantSize = 3;
        int array3[constantSize] = {4, 8, 2};
        for(int array3ForLoop = 0; array3ForLoop < constantSize; array3ForLoop++){
            cout << array3[array3ForLoop] << "\t";
        }
        cout << endl;

        // المصفوفات ثنائية الأبعاد
        int array2D1[3][3] = {1,2,3,4,5,6,7,8,9};
        cout << endl;
        for(int array2DForloop = 0; array2DForloop < 3; array2DForloop++){
            for(int array2DForForloop = 0; array2DForForloop < 3; array2DForForloop++){
                cout << array2D1[array2DForloop][array2DForForloop] << "\t";
            }
            cout << endl;
        }
        

    return 0;
}