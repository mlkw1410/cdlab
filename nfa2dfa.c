#include <stdio.h>
#define max 10


int n, trans[max][2][max];
int visited[100], queue[100];

int front =0, rear =0;
int i, j, k;

int main()
{
    printf("enter the no.of states: ");
    scanf("%d", &n);

    printf("enter the transition table: \n");
    for (i=0; i<n; i++){
        for(j=0; i<2; i++){
            printf("state %d, input %d: \n", i, j);
            for(k=0; k<n; k++){
                scanf("%d", &trans[i][j][k]);
            }
        }
    }

    queue[rear++]=1;

    while(front<rear){
        int current = queue[front++];
        if(visited[current]){
            continue;
        }
        visited[current]=1;
        printf("\nsubsset %d\n, current");

        for(j=0; j<2; j++){
            int next = 0;
            for(i =0; i<n; i++){
                if(current&(1<<i)){
                    for(k=0; k<n; k++){
                        if(trans[i][j][k]){
                            next|=(1<<k);
                        }
                    }
                }
            }
            printf("input %d -> %d", j, next);
            if(!visited[next]){
                queue[rear++] = next;
            }
        }
    }
}



