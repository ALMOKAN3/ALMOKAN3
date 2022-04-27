/*
#include <لتضمين المكتبات>
(function) المكتبات تحوي على عدة أوامر
أنواع المتغيرات في السي:
  1-(char) = 1 bytes للأحرف و الرموز
  2-(bool) = 1 bytes نعم أو لا
  3-(int) = 4 bytes للأعداد الصحيحة القصيرة
  4-(float) = 4 bytes للأعداد العشرية القصيرة
  5-(double) = 8 bytes للأعداد العشرية الطويلة
  6-(long) = 8 bytes للأعداد الصحيحة الطويلة

مكتبات السي:
  1-(stdio.h)
    (functions):
      1-(printf(""),;) للطباعة
        لطباعة متغير نكتب:
        %i or %d (int and long)
        %c (char)
        %s (string)
        %f (float and double)
        %b (bool)
        تكتب بين علامات التنصيص و يكتب اسم المتغير بعد الأقواس بعد وضع فاصلة
      2-(scanf(""),;) للإستقبال من المستخدم
        لإستقبال متغير من المستخدم نكتب:
        %i or %d (int and long)
        %c (char)
        %s (string)
        %f (float and double)
        %b (bool)
        تكتب بين علامات التنصيص و يكتب اسم المتغير بعد الأقواس بعد وضع فاصلة
  3-(string.h)
    (functions):
      1-(strlen();) (string) لحساب طول
      2-(strcmd();) (string) للمقارنة بين متغيرين من النوع
  4-(strings.h)
    (functions):
  5-(ctype.h)
    (functions):
      1-(islower();) لتحقق مما إذا كان الحرف صفيرا
      2-(isupper();) لتحقق مما إذا كان الحرف كبيرا
      3-(tolower();) لتحويل الأحرف إلى أحرف صفيرة
      4-(toupper();) لتحويل الأحرف إلى أحرف كبيرة
  6-(stdlib.h)
    (functions):
  7-(math.h)
    (functions):
  8-(time.h)
    (functions):

(mathematical calculations) العمليات الحسابية:
  1-(+) للجمع
  2-(++) لزيادة (1)
  3-(+=) للزيادة على القيمة
  4-(-) للطرح
  5-(--) لطرح (1)
  6-(-=) للطرح على القيمة
  7-(*) للضرب
  8-(*=) للضرب على القيمة
  9-(/) للقسمة
  10-(/=) للقسمة على القيمة

(conditional sentence) الجملة الشرطية:
  (if(conditional الشرط){الأمر} else if(conditional الشرط){الأمر} else{الأمر})
  عمليات الجملة الشرطية:
    ((&&) and و (||) or أو (==) equal equal? هل يساوي (!=) not equal? هل لا يساوي (<) younger than أصغر من (>) bigger than أكبر من (<= || =<) smaller and equal أصغر و يساوي(>= || =>) bigger and equal أكبر و يساوي)

(loops sentence) الجمل الدورانية:
  1-(while(الشرط){الأمر}) تقوم بفحص الشرط ثم العمل
  2-(do{الأمر}while(الشرط)) تعمل مرة واحدة ثم تفحص الشرط
  3-(for(المتغير و يمكن عدم وضعه؛ الشرط؛ تغير قيمة المتغير){الأمر}) تقوم بفحص الشرط ثم العمل

(functions) الدوال:
    أنواع الدوال:
      مرجعة                                                     غير مرجعة
     ترجع قيمة                                                  لا ترجع قيمة
       أنواعها                                                       أنواعها
                                                                 1-(int)
                                                                 2-(float)
                                                                 3-(double)
      (void)                                                     4-(long)
                                                                 5-(bool)
                                                                 6-(char)
  (main) الدالة الرئيسية:
    هي الدالة المسؤولة عن عمل البرنامج ويقرأ المترجم ما يوجد داخل هذه الدالة فقط
    ملحقات الدوال:

(arrays) المصفوفات :
  ((نوع المصفوفة) (اسم المصفوفة) [حجم المصفوفة] = {قيم المصفوفة})
  حالات المصفوفات :
    1-يمكن تحديد حجم المصفوفة و إعطائها قيم لاحقا
    2-يمكن عدم تحديد حجم المصفوفة مع شرط إعطائها القيم مباشرة

(struct) الهياكل :
  و يمكن أن يكون النوع الجديد فيه نوعين أساسين...(char) أو مثل ال(int) تستخدم الهياكل لإنشاء (نوع متغير) أي مثل ال
  (struct) أشكال ال :
    1-(struct (اسم النوع الجديد){معلمومات النوع الجديد};)
      لإنشاء متغير من النوع الجديد و إعطاءه قيم في هذه الحالة نقوم بكتابة :
      struct (اسم النوع الجديد) (اسم المتغير);
      (اسم المتغير).(إحدى المعلومات(النوع الأساسي)) = (القيمة);
    2-(typedef struct{معلمومات النوع الجديد}(اسم النوع الجديد);)
      لإنشاء متغير من النوع الجديد و إعطاءه قيم في هذه الحالة نقوم بكتابة :
      (اسم النوع الجديد) (اسم المتغير);
      (اسم المتغير).(إحدى المعلومات(النوع الأساسي)) = (القيمة);

*/
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

bool conditional();
bool loop();

int main(){

  conditional();
  loop();

}

bool conditional(){

  int num = 1;
  int number = 5;

  if(num != number){
    printf("obs, they're not equal\n");
    return 1;
  }
  else{
    printf("yes, they're equal\n");
  }

}

typedef struct{

  char* name;
  char* number;

}ss;

bool loop(){

  ss people[2];
  people[0].name = "ahmed";
  people[0].number = "123456";

  people[1].name = "ali";
  people[1].number = "098745";

  for(int i = 0, i < 2, i++){
    if(strcmd(people[i].name, "ali") == 0){
      printf("Found %s", people[i].number);
      return 0;
    }
  }
  printf("Not found");
  return 1;

}
