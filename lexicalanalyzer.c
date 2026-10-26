#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    FILE *fp;
    int ch;
    char str[50];
    int i,j,flag;
    char keyword[][6]={"int", "char", "for","while","if"};

    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("unable to open, error");
        return 0;
    }
    while((ch=fgetc(fp))!=EOF){
        //SPACE AND COMMENT
        if(ch==' '|| ch=='\t'|| ch=='\n')
            continue;
        if(ch=='/'){
            char next=fgetc(fp);
            if(next=='/'){
                while((ch=fgetc(fp))!='\n' && ch!=EOF);
                continue;
            }else if(next=='*'){
                int prev=0;
                while((ch=fgetc(fp))!=EOF){
                    if(prev=='*' && ch=='/' )
                     break;
                    prev=ch;
                }
                continue;
            }
            else{
                printf("/\t\tOperator\n");
                ungetc(next,fp);
                continue;
            }
        }
        //ALPHABET
        if(isalpha(ch) ||ch=='_'){
            i=0;
            str[i++]=ch;
            while((ch=fgetc(fp))!=EOF && (isalnum(ch)|| ch=='_')){
                str[i++]=ch;
            }
            str[i]='\0';
            if(ch!=EOF)
                ungetc(ch,fp);
            flag=0;
            for(j=0;j<6;j++){
                if(strcmp(str,keyword[j])==0){
                    flag=1;
                    break;
                }
            }
            if(flag)
                printf("%s\t\tKeyword\n",str);
            else
                printf("%s\t\tIdentifier\n",str);
        //DIGIT

        }else if(isdigit(ch)){
            i=0;
            str[i++]=ch;
            while((ch=fgetc(fp))!=EOF || (isdigit(ch)) || ch=='.'){
                str[i++]=ch;
            }
            str[i]="\0";
            if(ch!=EOF)
                ungetc(ch,fp);
            printf("%s\t\tNumber\n",str);
        }else if(strchr("+-*=<>!&|^",ch)!=NULL){
            printf("%c\t\tOperator",ch);
        }else if(strchr("(){}[];,",ch)!=NULL){
            printf("%c\t\tDelimiter\n",ch);
        }
    }
    fclose(fp);
    return 0;

}