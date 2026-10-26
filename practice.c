#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    FILE *fp;
    int i,flag,j,ch;
    char str[50];
    char kw[][6]={"for","int","else","while","if"};

    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("File not found");
        return 0;
    }
    while((ch=fgetc(fp))!=EOF){
        if(ch==' '|| ch=='\t'||ch=='\n')
            continue;
        if(ch=='/'){
            char next=fgetc(fp);
            if(next=='/'){
                while((ch=fgetc(fp))!='\n'&&ch!=EOF);
                continue;
            }else if(next=='*'){
                int prev=0;
                while((ch=fgetc(fp))!=EOF){
                    if(prev=='*' && ch=='/')
                        break;
                    prev=ch;
                }
                continue;
            }else{
                printf("/\tOperator");
                ungetc(next,fp);
                continue;
            }
        }
        if(isalpha(ch) || ch=='_'){
            i=0;
            str[i++]=ch;
            while((ch=fgetc(fp))!=EOF && (isalpha(ch)||ch=='_')){
                str[i++]=ch;
            }
            str[i]='\0';
            if(ch!=EOF)
                ungetc(ch,fp);
            flag=0;
            for(j=0;j<5;j++){
                if(strcmp(str,kw[j])==0){
                    flag=1;
                    break;
                }       
            }
            if(!flag)
                printf("%s\tIdentifier\n",str);
            else
                printf("%s\tKeyword\n",str);
        }else if(isdigit(ch)){
            i=0;
            str[i++]=ch;
            while((ch=fgetc(fp))!=EOF && (isdigit(ch)||ch=='.')){
                str[i++]=ch;
            }
            str[i]='\0';
            if(ch!=EOF){
                ungetc(ch,fp);
            }
            printf("%s\tNumber\n",str);

        }else if(strchr("+-*/%",ch)!=NULL){
            printf("%c\tOperator\n",ch);
        }else if(strchr("(){}[];,",ch)!=NULL){
            printf("%c\t\tDelimiter\n",ch);
        }
    }
    fclose(fp);
    return 0;
}