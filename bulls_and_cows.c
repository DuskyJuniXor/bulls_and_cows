#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

int briefIntroduction(void);
//界面

int briefIntroduction(void){
    printf("************************************************\n");
    printf("*game rule: 4 different numbers are waiting for*\n");
    printf("*you to guess; if you guess out the right num- *\n");
    printf("*ber in the right position, you will get an 'A'*\n");
    printf("*if you guess out the right number in the wrong*\n");
    printf("*position, you will get a 'B'. Goodluck, player*\n");
    printf("************************************************\n");
}

int main(){

    briefIntroduction();

    int a[N], b[N];
    int counta, countb, c = 0;
    int mid;

    srand((unsigned)time(NULL));

    for(int i = 0; i < N; i++){
        mid = rand() % 10;
        c = 0;
        for(int j = 0; j < i; j++){
            if(a[j] == mid) c = 1;
        }
        if(c != 1) a[i] = mid;
        if(c == 1) i--;
    }
    
    //for(int y = 0; y < 4; y++){      //调试用
    //    printf("%d", a[y]);
    //}
    //printf("\n");
    
    while(1){
        counta = 0, countb = 0;

        scan:printf("Please enter 4 different numbers (0 ~ 9, divided by space): \n");
        
        for(int k = 0; k < N; k++){
            scanf("%d", &b[k]);
        }

        for(int o = 0; o < N; o++){
            for(int p = 0; p < o; p++){
                if(b[p] == b[o] && o != p){
                    printf("Error: Please Enter Different Numbers! \n");
                    goto scan;
                }
                if(b[p] < 0 || b[p] > 9){
                    printf("Error: Outranged Numbers!");
                    goto scan;
                }
            }
        }

        //for(int z = 0; z < 4; z++){      //调试用
        //    printf("%d", b[z]);
        //}
        //printf("\n");

        for(int l = 0; l < N; l++){
            if(b[l] == a[l]) counta++;
        }
        
        for(int m = 0; m < N; m++){
            for(int n = 0; n < N; n++){
                if(b[m] == a[n] && m != n) countb++;
            }
        }

        if(counta == 4) break;
        printf("You've got %dA%dB\n", counta, countb);
    }

    printf("Congratulations!You've made it all right! \n");

    return 0;
}
