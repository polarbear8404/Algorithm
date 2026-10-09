#include <stdio.h>

typedef struct 
{
    int weight;
    int iq;
    int index;   

}Elephant;

int read(Elephant e[]){
    int weight, iq;
    int count = 0;
    while(scanf("%d", &weight) == 1){ //예외 처리
        if(weight == 0){
            break;
        }
        scanf("%d", &iq);
        e[count].weight = weight;
        e[count].iq = iq;
        e[count].index = count + 1; //코끼리 index는 1부터 시작하기 때문.
        count++;
    }
    return count;
}

void sort(Elephant e[],int p[], int size){//selection sort로 정렬, weight가 증가하는 방향으로 정렬
    //init p[]
    for(int i=0; i<size; i++){
        p[i] = i;
    }
    
    //selection sort
    for(int i=0; i<size; i++){
        int min = e[p[i]].weight;
        int min_index = i;
        for(int j=i; j<size; j++){
            if(min > e[p[j]].weight){
                min = e[p[j]].weight;
                min_index = j;
            }
        }
        int temp = p[i];
        p[i] = p[min_index];
        p[min_index] = temp;
    }
}


int main(void){
    Elephant elephant[1000];
    int sorted[1000]; // weight 순으로 정렬된 배열의 index
    int dp[1000]; //dp 배열
    int prev[1000]; //dp[i]가 참조한 이전 dp의 index
    int dp_max = 0; //dp 최대값
    int dp_max_index = 0; //dp 최대값 index
    int result[1000]; //dp 결과

    int size = read(elephant);
    sort(elephant, sorted, size);

/*     for (int i = 0; i < size; i++) { //입력, 정렬 테스트
    printf("%d: weight=%d, iq=%d, original=%d\n",
           i,
           elephant[sorted[i]].weight,
           elephant[sorted[i]].iq,
           elephant[sorted[i]].index);
    }
 */
 //dp
    for(int i=0; i<size; i++){
        dp[i] = 1;
        prev[i] = -1;
        for(int j=i-1; j>=0; j--){
            if((elephant[sorted[i]].weight > elephant[sorted[j]].weight) && (elephant[sorted[i]].iq < elephant[sorted[j]].iq)){//중복 방지를 위해 weight가 i번째 코끼리보다 작은 경우에만 실시
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if(dp[i] > dp_max){ //dp max를 미리 찾아놔서 불필요한 탐색 줄이기.
            dp_max = dp[i];
            dp_max_index = i;
        }
    }

    printf("%d\n", dp_max);
    int current = dp_max_index;
    int count = 0;
    while(current != -1){//prev의 기본 값이 -1이기 때문에 current의 값이 -1이 되었을 시 종료.
        result[count] = elephant[sorted[current]].index;
        current = prev[current];
        count++;
    }

    for(int i=dp_max-1; i>=0; i--){//수열이 뒤에서부터 저장되었기 때문에 역순으로 출력
        printf("%d\n", result[i]);
    }

    return 0;
}