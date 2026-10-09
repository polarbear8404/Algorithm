
Smart elephant
problem:
▪ Some people think that
 the bigger an elephant is, the smarter it is.
▪ To disprove this, you want to analyze a collection of elephants
 and place as large a subset of elephants as possible into a
 sequence whose weights are increasing but IQ’s are
 decreasing.

 Input: 
▪ The input will consist of data for a bunch of elephants, at on
 elephant per line terminated by the end-of-file.
▪ The data for each particular elephant will consist of a pair of
 integers: the first representing its size in kilograms and the second
 representing its IQ in the hundredths of IQ points.
▪ Both integers are between 1 and 10,000.
▪ The data contains information on at most 1,000 elephants.
▪ Two elephants may have the same weight, the same IQ, or even the
 same weight and IQ.
▪ A single line containing 0 follows the information for the last
 elephant.

 Output:
▪ The first output line should contain an integer n, the length of
 elephant sequence found.
▪ The remaining n lines should each contain a single positive integer
 representing an elephant
▪ Denote the numbers on the ith data line as W[i] and S[i].
▪ If these sequence of n elephants are a[1], a[2], …, a[n] then it
 must be the case that
▪ W[a[1]] < W[a[2]]< … < W[a[n]]
▪ S[a[1]] > S[a[2]] > … > S[a[n]]

알고리즘 아이디어:
1. 우선 weight 오름차순으로 코끼리 정렬합니다. 정렬을 하는 이유는 weight나 iq 둘 중 하나가 정렬이 되어있어야 dp를 했을 때 앞의 값을 이용할 수 있기 때문입니다.
2. 정렬된 상태에서 w[i]가 수열의 마지막일 때 생기는 수열의 길이를 구하는 식으로 dp를 합니다.
3. 이 때 문제 조건 상 중복값은 포함하지 않기 때문에 weight가 중복되는 값을 거르기 위해 현재 코끼리의 weight가 이전 코끼리보다 큰 경우에만 비교합니다.
4. 모든 코끼리는 기본적으로 자기 자신만을 포함한 길이 1을 가지기 때문에 dp[i] = 1로 초기화합니다.
5. 현재 코끼리 위치가 i라고 했을 때 앞에서부터 i까지의 코끼리들을 탐색하면서, j번째 코끼리 iq가 i번째 코끼리보다 클 경우에 dp[i] = dp[j] + 1로 초기화하고, 큰 코끼리가 없다면 dp[i]로 유지합니다.
6. 점화식으로 표현한다면 dp[i] = max(dp[i], dp[j]+1)입니다.

구현 디테일 설명:
1. 코끼리 한 마리당 weight, iq, index 정보를 포함해야하므로 struct로 선언했습니다. 코끼리는 최대 1000마리이므로 배열의 크기 1000으로 선언하였습니다.
2. 이번 문제의 경우, 입력값의 사이즈가 한 줄당 2개로 정해져있기 때문에 scanf로 받는 것이 간편함. 마지막 줄에는 0이 오기 때문에 weight 자리에 0이 온다면 break가 되도록 설계했습니다.
3. dp를 하기 위해서 먼저 weight값을 정렬하는데 이때 dp가 어차피 O(n^2)의 시간복잡도이므로 구현이 간단하면서 같은 시간복잡도의 selection sort로 구현하였습니다.
4. 정렬을 할 때는 기존의 elephant를 수정하고 싶지 않아서 원본 배열은 지키면서 정렬된 배열의 index만 저장하는 방식으로 정렬했습니다.
5. 최대 수열의 길이만 구하는 것 뿐만 아니라 수열의 값도 출력해야하기 때문에 dp가 값을 받아온 경로를 기록하는 prev배열도 선언하였습니다.
6. 값을 출력할 때는 dp의 값이 최대인 i로 prev[i]부터 시작해 역추적하면서 실제 값을 찾고 출력하면 됩니다.
7. 문제 조건 상 가장 큰 값을 만족하는 수열 하나만 찾으면 되므로 dp의 값이 중복이 되는 경우는 고려하지 않았습니다.
8. 여러 케이스를 반복적으로 처리하는 것이 아니라 한 케이스만 구하고 프로그램이 종료되기 때문에 함수로 구현하지 않았고 알고리즘 자체도 복잡하지 않아서 main 안에 구현하였습니다.

전체 시간 복잡도: O(n^2)
sort = O(n^2) n번의 단계를 거치며 각 단계마다 정렬되지 않은 구간을 탐색하기 때문에 n(n-1)/2라서 n^2입니다.
dp = O(n^2) 배열을 n번 탐색하면서 각 단계마다 앞쪽 i개를 탐색하기 때문에 n(n-1)/2라서 n^2입니다.
result 저장 = O(n) 최대 n번 반복하며 저장하기 때문입니다.
출력 = O(n) 최대 n번 반복하며 출력하기 때문입니다.
따라서 전체 시간 복잡도는 O(n^2)입니다.
