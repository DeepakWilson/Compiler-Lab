#include<stdio.h>
#include<time.h>
int main(){
    clock_t start,end;
    int i;
    double normal,constant;
    int a=5;
    int b=10;
    int c,d;
    start=clock();
    for(i=0;i<10000000;i++){
    c=a+b;
    }
    printf("The result is %d",c);
    end=clock();
    normal=(double)(end-start)/CLOCKS_PER_SEC;
    start=clock();
    for(i=0;i<10000000;i++){
    d=5+10;
    }
    printf("\nThe result is %d",d);
    end=clock();
    constant=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nNormal time is %f",normal);
    printf("\nConstant Folding is %f",constant);
    if(normal>constant)
    printf("\nConstant Folding better");
    else
    printf("\nNormal better");
}