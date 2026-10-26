#include<stdio.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];
int main(){
        FILE *fp1, *fp2;
    char f[100];

    printf("Enter the filename to open");
    scanf("%s",f);
    
    fp1=fopen(f,"r");
    fp2=fopen("output1.txt","w");
    if(fp1==NULL){
        printf("Error");
        return 0;
    }

    while(fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result)==4){
        if(strcmp(op,"+")==0){
            fprintf(fp2,"MOV AX, %s\n",arg1);
            fprintf(fp2,"ADD AX, %s\n",arg2);
            fprintf(fp2,"MOV %s, AX\n",result);            
        }else if(strcmp(op,"-")==0){
            fprintf(fp2,"MOV AX, %s\n",arg1);
            fprintf(fp2,"SUB AX, %s\n",arg2);
            fprintf(fp2,"MOV %s, AX\n",result);            
        }else if(strcmp(op,"*")==0){
            fprintf(fp2,"MOV AX, %s\n",arg1);
            fprintf(fp2,"MUL %s\n",arg2);
            fprintf(fp2,"MOV %s, AX\n",result);         
        }else if(strcmp(op,"/")==0){
            fprintf(fp2,"MOV AX, %s\n",arg1);
            fprintf(fp2,"DIV %s\n",arg2);
            fprintf(fp2,"MOV %s, AX\n",result);            
        }else if(strcmp(op,"=")==0){
            fprintf(fp2,"MOV AX, %s\n",arg1);
            fprintf(fp2,"MOV %s, AX\n",result);            
        }
    }
    fclose(fp1);
    fclose(fp2);
    printf("\nTarget code generated successfully.\n");
    printf("Check output1.txt\n");

    return 0;



}