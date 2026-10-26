#include<stdio.h>
#include<time.h>
int main(){
    clock_t start, end;
    double normal, unrolled;
    int i;
    start=clock();
    for(i=0;i<5;i++){
        printf("Hello\n");
    }
    end=clock();
    normal=(double)(end-start)/CLOCKS_PER_SEC;
    //
    start=clock();
    printf("Hello\n");
    printf("Hello\n");
    printf("Hello\n");
    printf("Hello\n");
    printf("Hello\n");
    end=clock();
    unrolled=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Normal= %f",normal);
    printf("Unrolled= %f",unrolled);
    if(unrolled>normal)
        printf("Normal is better");
    else
        printf("Loop Unrolling is better");


}