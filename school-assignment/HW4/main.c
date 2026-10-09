#include <stdio.h>
#include <stdlib.h>
#define MAXJOBS 1000
typedef struct{
    int day;
    int fine;
    int index;
}Job;

int compare(const void *a, const void *b){//T_a * S_b와 T_b * S_a 값 비교. 둘 중 작은 것이 앞으로
    const Job *A = (const Job *)a;
    const Job *B = (const Job *)b;
    int i = A->day * B->fine;
    int j = B->day * A->fine;
    if(j > i) return -1;//이미 앞에 있었던게 비용이 작음.
    if(i > j) return 1;//뒤에 있었던게 비용이 더 작기 때문에 위치 바꿔야함.
    if(A->index < B->index) return -1;//값이 같은 경우 index가 작은 것을 앞으로.
    if(A->index > B->index) return 1;
    return 0;
}

int main(void){
    int tc = 0;
    if(scanf("%d", &tc) != 1){
        return -1;
    }
    for(tc; tc>0; tc--){
        int n = 0;
        Job job[MAXJOBS];

        scanf("%d", &n);
        for(int i=0; i<n; i++){
            if(scanf("%d %d", &job[i].day, &job[i].fine) != 2){
                return -1;
            }
            job[i].index = i + 1;
        }
        /* for(int i=0; i<n; i++){ //입력값 확인
            printf("jobs %d: %d fine%d: %d\n", i,job[i].day,i,job[i].fine);
        } */
        qsort(job, n, sizeof(Job), compare);
        for(int i=0; i<n; i++){
            printf("%d",job[i].index); //정렬된 순서대로 출력.
            if(i < n-1) printf(" ");
        }
        printf("\n");
        if(tc>1) printf("\n");//케이스 사이에 blank line 추가
    }
    return 0;
}