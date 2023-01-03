#include "txtfind.h"

//a function that scans chars from standart input to a line and returns the number of chars received
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

//a function that scans chars from standart input to a word and returns the number of chars received
int getword(char w[]){
    char c = '\0';
    int counter = 0;
    scanf("%c", &c);
    while (c != '\n' && c != ' ' && c != '\t' && c!='\0' && c!=EOF){		//indication that the word ends
        w[counter] = c;
        counter++;
        scanf("%c", &c);}
    return counter;
}    

//a function that checks if str2 is a substring of str1
int substring(char * str1, char * str2){					
    int result = 0; 
    int i =0; int j =0;
    char char1 = str1[0]; char char2 = str2[0];
    if (strlen(str1)<strlen(str2)){				//if len of str2 is greater then len of str1 then it cannot be a substring of str1
        return result;}
    while(char1 != '\0' && char2 != '\0'){
        if(char1 == char2){
            i++;
            j++;
            if (i == strlen(str2)){				//if we have reached the point where we found all the chars of str2 in str1, this is a substring
                result = 1;
                break;}
            char1 = str1[j];
            char2 = str2[i];}
        else {
            j++;						//even if we found previous smaller substring but the siguiente char is different, start over e.g. cacats for cat
            char1 = str1[j];
            i = 0;
            char2 = str2[i];}
    }
    return result; 
}

//checking if t is similar to s by omitting exactly n chars from s
int similar(char *s, char *t, int n){
    if (strlen(s)<strlen(t)){					//if t is larger then s, we cannot omit chars from s to get to t
        return 0;
    }
    if (strlen(s)-strlen(t)>n){					//if the size of t is bigger then s by N>n chars, it cannot be similar
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
    if(i == strlen(s)-n2){				//at the end of the loop, i needs to be exactly the len of s minus the reduction if n2 chars
        flag =1; 
    }
    
    return flag;
}

//user's decision 'a' - printing all the lines contains the given string
void print_lines(char *str){
    char word[WORD]={'\0'}; char s[LINE]={'\0'};
    int flag=1, a=0, i=0, j=0;
    while (flag){
        a = get_line(s);			//using get line to fetch the line
        if (a == 0){				// no more line fetched 
            flag = 0;}
        else {
            while (j<=a){
                if (j==a){
                    if (substring(word, str)){ 		//checking the last word in line
                        puts(s);}
                    i=0;
                    j++;
                    }
                else if (s[j]!= ' '){			//slicing the words from each line 
                    word[i] = s[j];
                    i++; 
                    j++;}
                else {
                    if (substring(word, str)){		//checking if our string is a substring of word
                        puts(s);
                        i=0; 
                        j=a+1;}				//skipping the rest of the words
                    else {
                        i = 0;
                        memset(word, 0, sizeof(word));
                        j++;}
                }
            }}
        j = 0;
        memset(word, '\0', sizeof(word));			//getting ready to get another line
        memset(s, '\0', sizeof(s));
        
    }
}

//user's decesion 'b' - print the words that is similar up to 1 extra different chars
void print_similar_words(char * str){
    int flag=1, a=0;
    while(flag){
        char s[WORD]={'\0'};
        //memset(s, 0, sizeof(s));
        a = getword(s);
        if (a <= 0){			//end of the file
            flag = 0;}
        else if (similar(s,str,0) || similar(s,str,1)){
            printf("%s\n",s);}
            }
}


int main(){
    char word[WORD]={'\0'};
    getword(word);		//getting the first word
    char c = '\0';	
    scanf("%c", &c); 		//getting the space between the word and user's decision
    getchar();                  //skipping the empty line
    getchar();                      
    if (c == 'a'){		//checking what is the user's desicion
        print_lines(word);}	
    else {print_similar_words(word);}

    return 0;
}
