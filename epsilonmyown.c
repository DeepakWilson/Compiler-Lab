#include<stdio.h>
#include<string.h>
char states[20][20],closure[20][20];
char from[100][20],symbol[100][20],to[100][20];
int count,transitions;

void epsilonclosure(char state[]){
    for(int i=0;i<transitions;i++){
        if(strcmp(from[i],state)==0 && strcmp(symbol[i],"e")==0){
            int found=0;
            for(int j=0;j<count;j++){
                if(strcmp(closure[j],to[i])==0){
                    found=1;
                    break;
                }
            }
            if(!found){
                strcpy(closure[count++],to[i]);
                epsilonclosure(to[i]);
            }
        }
    }
}
int main(){
    int n;
    transitions=0;
    FILE *fp=fopen("input.dat","r");
    if(fp==NULL){
        printf("Error!");
        return 0;
    }
    while(transitions<100 && fscanf(fp,"%19s%19s%19s",from[transitions],symbol[transitions],to[transitions])==3)
        transitions++;
    fclose(fp);
    printf("Enter the number of states");
    scanf("%d",&n);
    printf("Enter the states");
    for(int i=0;i<n;i++){
        scanf("%s",&states[i]);  
    }
    for(int i=0;i<n;i++){
        count=0;
        strcpy(closure[count++],states[i]);
        epsilonclosure(states[i]);
        printf("The Epsilon Closures of %s ={",states[i]);
        for(int j=0;j<count;j++)
            printf("%s",closure[j]);
        printf("}\n");
        
    }
    return 0;
}