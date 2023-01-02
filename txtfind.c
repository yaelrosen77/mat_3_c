#include "txtfind.h"

int get_line(char s[]){
    char c = '\n';
    int counter=0; 
    scanf("%c", &c);
    while (c != '\n'){
        s[counter] = c;
        counter++;
        scanf("%c", &c);}
    return counter;
}

int getword(char w[]){
    char c = '\0';
    int counter = 0;
    scanf("%c", &c);
    while (c != '\n' && c != ' ' && c != '\t' && c!='\0' && c!=EOF){
        w[counter] = c;
        counter++;
        scanf("%c", &c);}
    return counter;
}    


int substring(char * str1, char * str2){
    int result = 0; 
    int i =0; int j =0;
    char char1 = str1[0]; char char2 = str2[0];
    if (strlen(str1)<strlen(str2)){
        return result;}
    while(char1 != '\0' && char2 != '\0'){
        if(char1 == char2){
            i++;
            j++;
            if (i == strlen(str2)){
                result = 1;
                break;}
            char1 = str1[j];
            char2 = str2[i];}
        else {
            j++;
            char1 = str1[j];
            i = 0;
            char2 = str2[i];}
    }
    return result; 
}


int similar(char *s, char *t, int n){
    if (strlen(s)<strlen(t)){
        return 0;
    }
    if (strlen(s)-strlen(t)>n){
        return 0;
    }
    int n2 = n,i=0,j=0,flag = 0; 
    char char1 = '\0', char2 = '\0';
    char1 = s[i]; char2 = t[j];
    
    while (char1!='\0'&& char2!='\0'){
        if (char1 == char2){
            i++; 
            j++;
            char1 = s[i];
            char2 = t[j];}
        else {
            i++; 
            char1 = s[i];
            n2--;}
            }
    if(i == strlen(s)-n2){
        flag =1; 
    }
    
    return flag;
}

void print_lines(char *str){
    char word[WORD]={'\0'}; char s[LINE]={'\0'};
    int flag=1, a=0, i=0, j=0;
    while (flag){
        a = get_line(s);
        if (a == 0){
            flag = 0;}
        else {
            while (j<=a){
                if (j==a){
                    if (substring(word, str)){
                        puts(s);}
                    i=0;
                    j++;
                    }
                else if (s[j]!= ' '){
                    word[i] = s[j];
                    i++; 
                    j++;}
                else {
                    if (substring(word, str)){
                        puts(s);
                        i=0; 
                        j=a+1;}
                    else {
                        i = 0;
                        memset(word, 0, sizeof(word));
                        j++;}
                }
            }}
        j = 0;
        memset(word, '\0', sizeof(word));
        memset(s, '\0', sizeof(s));
        
    }
}

void print_similar_words(char * str){
    int flag=1, a=0;
    while(flag){
        char s[WORD]={'\0'};
        //memset(s, 0, sizeof(s));
        a = getword(s);
        if (a <= 0){
            flag = 0;}
        else if (similar(s,str,0) || similar(s,str,1)){
            printf("%s\n",s);}
            }
}


int main(){
    char word[WORD]={'\0'};
    getword(word);
    char c = '\0';
    scanf("%c", &c); 
    getchar();                  
    getchar();                      
    if (c == 'a'){
        print_lines(word);}
    else {print_similar_words(word);}

    return 0;
}