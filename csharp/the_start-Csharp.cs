using System;
using System.Linq;
using System.Collections.Generic;

namespace Start_Csharp
{
    public static class  the_start_Csharp
    {         
        public static void Main()
        {
        	//للطباعة فقط
        	Console.Write("1- ");
        	//للطباعة مع سطر جديد
            Console.WriteLine("Hello World!");
            //لإستقبال المدخلات
            	//Console.Read; && Console.ReadLine;
            //(DataType) أنواع البيانات
            //للأرقام الصحيحة
            int age = 19;
            //للأسماء والكلام
            string name = "Ahmed";
            //للأعداد العشرية الصغيرة
            float result = 87.5f;
            //للأعداد العشرية الكبيرة
            double number = 28.5;
            //للأحرف المفردة والرموز
            char resultbychar = 'A';
            //للمنطقية (نعم/لا)
            bool najeh = true;
            //للمتغيرات ذات القيم الغير معروفة
            var varibal = 28;
            Console.WriteLine(name);
            Console.WriteLine(age);
            Console.WriteLine(number);
            Console.WriteLine(result);
            Console.WriteLine(resultbychar);
            Console.WriteLine(najeh);
            Console.WriteLine(varibal);
            //حساب العمر
            DateTime birthday = 2006 10 30;
            int day;
            
            string strnum = "38";
            int intgernum = Convert.ToInt16(strnum);
            Console.Write("the number is: ");
            Console.WriteLine(intgernum);
            
            double donumber = 5.1;
            int intdonumber = (int) donumber;
            Console.WriteLine(intdonumber);
            
            
            //math operator العمليات الرياضية
            double math = 100;
            Console.Write("\nnumber is : ");
            Console.WriteLine(math);
            Console.Write("number + 50 = ");
            //الجمع
            Console.WriteLine(math + 50);
            Console.Write("number - 50 = ");
            //الطرح
            Console.WriteLine(math - 50);
            Console.Write("number * 5 = ");
            //الضرب
            Console.WriteLine(math * 5);
            Console.Write("number / 5 = ");
            //القسمة
            Console.WriteLine(math / 5);
            Console.Write("(number + 1) / 5 = ");
            //باقي القسمة
            Console.WriteLine(++math / 5);
            
            //conditions and logic operator الشروط والعمليات المنطقية
            //if condition تعمل إذا تحقق الشرط
            int logic = 5;
            if(logic == 1){
            	Console.WriteLine("\nnumber 1");
            }
            else if(logic == 2){
            	Console.WriteLine("\nnumber 2");
            }
            else if(logic == 3){
            	Console.WriteLine("\nnumber 3");
            }
            else{
            	Console.WriteLine("\nI don't know your number");
            }
            
            //switch condition الشرط المحقق هو الذي يعمل
            logic = 2;
            switch(logic){
            	case 1: 
            		Console.WriteLine("\nnumber 1");
            	break;
            	case 2: 
            		Console.WriteLine("\nnumber 2");
            	break;
            	case 3: 
            		Console.WriteLine("\nnumber 3");
            	break;
            	default : 
            		Console.WriteLine("\nI don't know your number");
            	break;
            }
            
            //loop التكرار
            //while loop تفحص الشرط ثم تعمل
            int loop1 = 2;
            while(loop1 != 5){
            	Console.WriteLine(loop1);
            	loop1++;
            }
            Console.WriteLine(" ");
            
            //do_while loop تعمل مرة ثم تفحص الشرط
            int loop2 = 3;
            do{
            	Console.WriteLine(loop2);
            }while(loop2 != 3);
            Console.WriteLine(" ");
            
            //for loop تفحص الشرط ثم تعمل وهي مختصرة
            for(int i = 0; i < 5; i++){
            	Console.WriteLine(i);
            }
            Console.WriteLine(" ");
            
            //for{for} loop1
            for(int i = 0; i < 5; i++){
            	for(int j = 0; j <= i; j++){
            		Console.Write("*");
            	}
            	Console.WriteLine(" ");
            }
            
            for(int i = 5; i > 0; i--){
            	for(int j = 0; j < i; j++){
            		Console.Write("*");
            	}
            	Console.WriteLine(" ");
            }
            Console.WriteLine(" ");
            
            //if{while{if}}
            int conditionLoop = 17;
            if(conditionLoop != 30){
            	while(conditionLoop != 25){
            		conditionLoop++;
            		Console.WriteLine("^_^");
            		if(conditionLoop == 25){
            			break;
            		}
            		if(conditionLoop == 21){
            			continue;
            		}
            	}
            }
            Console.WriteLine(" ");
            
            //arrays المصفوفات
            //هي متغير يمل أكثر من قيمة
            int [] arr_1 = new int[3];
            arr_1[0] = 1;
            arr_1[1] = 2;
            arr_1[2] = 3;
            Console.WriteLine(arr_1[0]);
            Console.WriteLine(arr_1[1]);
            Console.WriteLine(arr_1[2]);
            
            Console.WriteLine(" ");
            
            //const datatype varibal متغير معرف بنوع بيانات ولكنه ثابت لا يتغير بعد تعريفه
            //array for
            const int size = 3;
            int [] arr_2 = new int[size] {2, 8, 5};
            for(int i = 0; i < size; i++){
            	Console.WriteLine(arr_2[i]);
            }
            
            Console.WriteLine(" ");
            
            //function الدوال
            void fun_1(){
            	Console.WriteLine("Hello, world");
            }
            fun_1();
            
            Console.WriteLine(" ");
            
            int fun_2(){
            	int var_1 = 6;
            	int var_2 = 3;
            	
            	return var_1 + var_2;
            }
            int var_fun_2 = fun_2();
            Console.WriteLine(var_fun_2);
            
            Console.WriteLine(" ");
            
            double fun_3(){
            	double var_1 = 5.9;
            	double var_2 = 4.1;
            	
            	return var_1 - var_2;
            }
            double var_fun_3 = fun_3();
            Console.WriteLine(var_fun_3);
            
            Console.WriteLine(" ");
            
            string fun_4(){
            	string name_1 = "Ahmed";
            	string name_2 = " Ali";
            	
            	return name_1 + name_2;
            }
            string var_fun_4 = fun_4();
            Console.WriteLine(var_fun_4);
            
            Console.WriteLine(" ");
            
            //
            //static = const
            
            
            
            
            
            
            
            
            
            //لإبقاء التطبيق قيد العمل
        	//Console.ReadLine();
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}