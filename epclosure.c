#include <stdio.h>

#define max 20

int n , symbol, transition[max][max], visited[max];

void findepclosure(int state){
    visited[state] = 1;
    int next;

    printf("%d", state);

    next = transition[state][symbol];

    if(next !=1 && !visited[state]){
        findepclosure(next);
    }
}

int main(){
    int i, j;

    printf("enter the no of states: ");
    scanf("%d", &n);

    printf("enter the no.of input symbols: (no epsilon) ");
    scanf("%d", &symbol);

    printf("enter the transition table: \n");

    for(i=0; i<n; i++){
        printf("q%d: ", i);
        for(j=0; j<=symbol; j++){
            scanf("%d", &transition[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            visited[j] = 0;
        }

        printf("q%d: {", i);
        findepclosure(i);

        printf("}\n");

    }
    return 0;
    
}