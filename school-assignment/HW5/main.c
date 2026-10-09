#include <stdio.h>
#include <math.h>
#define MAX_DOTS 30

typedef struct{
    double x;
    double y;
}Vertex;

double dis(double x1, double y1, double x2, double y2){
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double min(double a, double b) {
    return a < b ? a : b;
}

int main(void){
    int n;
    Vertex vertex[MAX_DOTS];
    double total_dis = 0;
    double w[MAX_DOTS];//현재 집합에서 각 vertex로 가는 weight
    int visited[MAX_DOTS];//선택된 vertex라면 1, 아니면 0
    int last_added = 0;
    if(scanf("%d", &n) != 1){
        return -1;
    }
    if (n <= 0 || n > MAX_DOTS) {//n 예외처리
    return -1;
    }
    for(int i=0; i<n; i++){
        if(scanf("%lf %lf", &vertex[i].x, &vertex[i].y) != 2){
            return -1;
        }
    }
    
/*     for(int i=0; i<n; i++){//입력값 확인
        printf("%.1f %.1f\n",vertex[i].x, vertex[i].y);
    } */
     for(int i=0; i<n; i++){//초기 w 첫번째 입력값으로 init
        w[i] = dis(vertex[i].x,vertex[i].y,vertex[0].x,vertex[0].y);
        visited[i] = 0;
     }
     visited[0] = 1;//첫번 째 입력값을 초기 점으로 설정.
     for(int i=1; i<n; i++){
        int min_index = -1;
        double min_dis = INFINITY;
        for(int j=0; j<n; j++){
            if(visited[j]){//set에 추가된 점은 skip
                continue;
            }
            w[j] = min(w[j], dis(vertex[j].x,vertex[j].y,vertex[last_added].x,vertex[last_added].y));//j번째 점과 직전 선택된 점과의 거리를 계산하고, w[j]와 비교 후 더 작은 값으로 초기화.
            if(w[j] < min_dis){//현재 집합에서의 최소 w찾기
                min_dis = w[j];
                min_index = j;
            }
        }
        if(min_index != -1){//예외 처리
            visited[min_index] = 1;
            last_added = min_index;
            total_dis += min_dis;
        }
     }
     printf("%.2f", total_dis);
    return 0;
}