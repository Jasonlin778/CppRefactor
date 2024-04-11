#include <stdio.h>
#include <string.h>
#include <ctype.h>
int compare(char *a,char *b,int len){
    char aa = '\0';
    char bb = '\0';
    if(strlen(a)>=len){
        aa = a[len];
        a[len] = '\0';
    }
    if(strlen(b)>=len){
        bb = b[len];
        b[len] = '\0';
    }
    int ans = strcmp(a,b);
    if (aa != '\0') a[len] = aa;
    if (bb != '\0') b[len] = bb;
    return ans;
}
int find(char *ptr, char set[50][50],int len){
    for(int i = 0;i<len;i++)
        if(compare(ptr,set[i],24)==0)
            return i;
    return -1;
}
int main(){
    char reserve[12][10] = {"if","else","while","for",
    "switch","case","break","return","void","int","float","char"};
    char mark[] = "+-*/%>=<(){}[],;!?:\"\' ";
    char name[50][50];
    int len = 0;
    int fre[50] = {0};
    char code[1000];
    char copy[1000];
    int add = 0;
    while(scanf("%s",code)!=EOF){
        strcpy(copy,code);
        char *ptr = strtok(code,mark);
        while(ptr!=NULL){
            int index = find(ptr,name,len);
            if(index != -1) fre[index]++;
            
            int check = 0;
            for(int j = 0;j<12;j++) if(compare(ptr,reserve[j],strlen(reserve[j]))==0) check = 1;
 
            if(add == 1){
                if((ptr[0] - '0'<=9)&&(ptr[0] - '0'>=0)) add = 0;
                int n = strlen(ptr);
                for(int k = 0;k<strlen(ptr);k++)
                    if( !isalnum(ptr[k]) &&  ptr[k]!='_' ) add = 0;
                if(add==1 && index == -1  && check != 1){
                        strcpy(name[len],ptr);
                        fre[len]++;
                        len++;
                }
                add = 0;
            }
            int r = (code - ptr)+strlen(ptr);
            if(check == 1 || copy[r] == ',') add = 1;
            ptr = strtok(NULL,mark);
        }
    }
 
    for(int i = 0;i<len;i++){
        name[i][24] = '\0';
        printf("%s %d\n",name[i],fre[i]);
    }
}