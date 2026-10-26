#include<stdio.h>
#include<string.h>

void generate(char *e, char *ops, char *t){
    int i, n, found;
    while(1){
        n=strlen(e);
        found=0;
        for(i=1,i<n-1;i++){
            if(strchr(ops,e[i])){
                printf("%c:=%c%c%c",*t,e[i-1],e[i],e[i+1]);
                e[i-1]=*t;
                found=1;
                memmove(&e[i],&e[i+2],n-i-1);
                break;
            }
        }
        if(!found)
        break;
    }
}
int main(void){


}