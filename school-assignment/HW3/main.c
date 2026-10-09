#include <stdio.h>
#include <string.h>

typedef struct{
    int digit[101];//최대 10^100이기 때문에 101자리 저장.
}Bigint;

void add(Bigint *a, Bigint *b){
    int carry = 0;
    for(int i=0; i<101; i++){
        int sum = a->digit[i] + b->digit[i] + carry;
        
        a->digit[i] = sum % 10;
        carry = sum / 10;
    }
}

int main(void){
    int N = 0;
    char x[10001];
    char z[101];

    scanf("%d", &N);
    
    for(int k=0; k<N; k++){
        scanf("%10000s", x);
        scanf("%100s", z);
        int x_len = strlen(x);
        int z_len = strlen(z);
        Bigint dp[z_len+1];
        for(int i=0; i<=z_len; i++){
            for(int j = 0; j<101; j++){
                dp[i].digit[j] = 0;//add 계산을 위해 모든 자리를 0으로 초기화.
            }
        }
        dp[0].digit[0] = 1;//빈 문자열을 만드는 개수
        for(int i=1; i<=x_len; i++){
            for(int j=z_len;j>0; j--){
                if(x[i-1] == z[j-1]){//현재 x[i-1] == z[j-1]인 경우, z의 앞 j-1개 문자를 만들었던 경우의 수(dp[j-1])만큼 z의 앞 j개 문자를 만드는 새로운 경우가 생기므로 dp[j]에 더함.
                    add(&dp[j], &dp[j-1]);
                }
            }
        }
        int count = 100;
        while(count>0 && dp[z_len].digit[count] == 0){//0이 아닌 숫자가 처음 나오는 위치 찾기. dp 값이 0인 경우가 있을 수도 있으므로 count>0 조건 추가.
            count--;
        }
        for(int i=count; i>=0; i--){
            printf("%d", dp[z_len].digit[i]);
        }
        printf("\n");
    }
    return 0;
}