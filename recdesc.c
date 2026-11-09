#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char input[50];
int pos =0 ;

char lookahead(){
    return input[pos];
}

void match(char c){
    if(input[pos] == c){
        pos++;
    }
    else{
        printf("error at %d expected %c, got %c\n", pos, c, input[pos]);
        exit(1);
    }
}

void E();
void EP();
void T();
void TP();
void F();


void E(){
    printf("E -> TE'\n");
    T();
    EP();
}

void EP(){
    if(lookahead() == '+'){
        printf("E' -> +TE'\n");
        match('+');
        T();
        EP();
    }
    else{
        printf("E' -> #\n");
    }
}

void T(){
    printf("T -> FT'\n");
    F();
    TP();
}

void TP(){
    if(lookahead() == '*'){
        printf("T' -> *FT'\n");
        match('*');
        F();
        TP();
    }
    else{
        printf("T' -> #\n");
    }
}

void F(){
    if(lookahead() == '('){
        printf("F -> (E)\n");
        match('(');
        E();
        match(')');
    }
    else if(isalpha(lookahead())){
        printf("F -> %c\n", lookahead());
        pos++;
    }
    else{
        printf("error at %d unexpected %c", pos, lookahead());
        exit(1);
    }
}

int main(){
    printf("enter an expression: (end with $)");
    scanf("%s", input);

    E();

    if(input[pos] == '$'){
        printf("valid\n");
    }
    else{
        printf("invalid\n");
    }
}