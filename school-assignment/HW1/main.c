#include <stdio.h>
#include <stdlib.h>

int readArray(int arr[], int maxSize) {
    char line[10000];

    if (fgets(line, sizeof(line), stdin) == NULL) //EOF 만났을 때 입력 종료
        return -1;

    int count = 0;
    char *p = line;

    while (count < maxSize) {
        char *end;
        long value = strtol(p, &end, 10); //문자열에서 long으로 변환

        if (p == end){//숫자를 읽지 못했을 때 탈출
            break;
        }
        arr[count++] = (int)value;//정수형 배열로 초기화
        p = end; //마지막으로 읽은 위치로 배열 업데이트
    }

    return count;
}

int findMax(int arr[], int n, int sortedCount){
    int size = n - sortedCount;
    if(size <= 0){//예외 처리
        return -1;
    }
    int max = arr[0];
    int max_index = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}

void flip(int arr[], int flipIndex)
{
    for (int i = 0; i < (flipIndex + 1) / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[flipIndex - i];
        arr[flipIndex - i] = temp;
    }
}



int main(void) {
    //EOF 받을 때까지 반복
    while(1){
        int arr[30];
        int flippedIndex[100];//플립을 여러번 할 가능성 있으므로 크게 잡기
        int flipCount = 0;
        int flipIndex = 0;
        int sortedCount = 0;
        int n = readArray(arr, 30); // 입력 사이즈
        if(n == -1){
            break;
        }
        //입력값 출력
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

    /* findmax 작동 확인 
        int test = findMax(arr, n, sortedCount);
        printf("Max index: %d", test);
    */
        while(sortedCount != n){
            int flipIndex = findMax(arr, n, sortedCount); //max값의 위치 탐색
            //max 값의 위치가 이미 정렬이 되었다면 스킵
            if(flipIndex == n - 1 - sortedCount){
                sortedCount++;
                continue;
            }
            //맨 위에 max값이 있지 않을 경우 맨위로 가도록 flip
            if(flipIndex != 0){
                flip(arr, flipIndex); //max 값을 맨 위로 가도록 flip
                flippedIndex[flipCount++] = n - 1 - flipIndex; // flip한 위치 저장
            }
            flipIndex = n - 1 - sortedCount; //이미 정렬된 부분의 위로 flip 할 위치 초기화
            flip(arr, flipIndex); // max값이 정렬된 부분 위로 가도록 flip
            flippedIndex[flipCount++] = n - 1 - flipIndex; // flip한 위치 저장
            sortedCount++;
        }
        
    // 뒤집은 결과 출력
        printf("(");
        for (int i = 0; i < n; i++) {
            if(i > 0) printf(" ");//공백 출력
            printf("%d", arr[i]);
        }
        printf(") ");

        for(int i = 0; i < flipCount; i++){
            printf("%d ", flippedIndex[i] + 1);
        }
        printf("0\n");

    }
    return 0;
}