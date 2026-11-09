#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char op[20], arg1[20][10], arg2[20][10], res[20][10];

    printf("enter the no.of operations\n");
    scanf("%d", &n);

    printf("enter the 3AC code: \n");
    for(i=0; i<n; i++){
        scanf("%s %s %s %s", op[i], arg1[i], arg2[i], res[i]);
    }

    printf("8086 assembly code: \n");
    for(i=0; i<n; i++){
        if(strcmp(op[i], "=") == 0){
            printf( "MOV %s, %s\n ", res[i], arg1[i] );
        }

        else if (strcmp(op[i], "+") == 0){
            printf ("MOV AX, %s\n", arg1[i]);
            printf("ADD AX, %s\n", arg2[i]);
            printf("MOV %s, AX\n", res[i]);
        }

        else if (strcmp(op[i], "-") == 0){
            printf("MOV AX, %s\n", arg1[i]);
            printf("SUB AX, %s\n", arg2[i]);
            printf("MOV %s, AX\n", res[i]);
        }

        else if (strcmp(op[i], "*") == 0){
            printf("MOV AX, %s\n", arg1[i]);
            printf("MUL %s\n", arg2[i]);
            printf("MOV %s\n", res[i]);
        }
        
        else if(strcmp(op[i], "/") == 0){
            printf("MOV AX, %s\n", arg1[i]);
            printf("DIV %S\n", arg2[i]);
            printf("MOV %s, AX\n", res[i]);
        }
        printf("\n");
    }
    return 0;
}