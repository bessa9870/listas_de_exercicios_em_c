#include <stdio.h>
#include <ctype.h>

void f(char *p){
    int i =0;
    while(*(p+i) != '\0'){
        p[i] = toupper(p[i]);
        i++;
    }
}
int main(){
    char s[] = "Texto de exemplo";
    f(s);
    printf("%s",s);

    return 0;
}
