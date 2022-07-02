#include<stdio.h>

int main(void){
    FILE* f = fopen("file.scv", "r");
    char* name = "Mohamed";
    char* number = "012310";
    fprintf(f, "%s, %s\n", name, number);
    fclose(f);
}