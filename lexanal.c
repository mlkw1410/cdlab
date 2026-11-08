#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void"
};

void iskeyword(char word[]){
    int i;
    for(i=0; i<9; i++){
        if(strcmp(word, keywords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    char ch, word[50];
    int i;

    printf("enter a string: ");

    while(ch=getchat()!=EOF){

        if(ch == ' ' || ch == '\n' || ch == '\t'){
            continue;
        }

        if (isalpha(ch)){
            i=0;

            while (isalnum(ch)){
                word[i++]= ch;
                ch = getchar();
            }
            word[i]= '\0';

            if(iskeyword(word)){
                printf("%s -> keyword\n", word);
            }
            else{
                printf("%s -> identifier\n", word);
            }
            ungetc(ch, stdin);
        }

        else if(isdigit(ch)){
            i=0;

            while(isdigit(ch)){
                word[i++] = ch;
                ch = getchar();
            }
            word[i]= '\0';
            printf("%s -> number\n", word);

            ungetc(ch, stdin);
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>'){
            printf("%c -> operator\n", ch);
        }

        else if (ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ','){
            printf("%c -> special symbol\n", ch);
        }

        else{
            printf("%c -> unknown\n", ch);
        }

        return 0;

    }
}