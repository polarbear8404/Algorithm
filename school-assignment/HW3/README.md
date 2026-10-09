Problem: Distinct Subsequences
▪ Input
▪ The first line of the input contains an integer N
indicating the number of test cases to follow.
▪ The first line of each test case contains a string X,
composed entirely of lowercase alphabetic characters
and having length no greater than 10,000.
▪ The second line contains another string Z
having length no greater than 100
and also composed of only lowercase alphabetic characters.
▪ Be assured that neither Z nor any prefix or suffix of Z will
have more than 10^100 distinct occurrences in X as a subsequence. 

▪ Output
▪ For each test case, output
the number of distinct occurrences of Z in X as a subsequence.
▪ Output for each input set must be on a separate line.

구현 디테일:
1. sequence에서 subsequence의 개수를 찾기 위해 dp를 사용했습니다.
2. 처음엔 2차원 dp로 구상하였으나, 문제의 조건 상 int의 범위를 넘어서는 정수 계산이 필요하기 때문에 별도로 큰 정수를 계산을 하는 함수를 구현해야했고, 2차원 dp를 사용할 경우 메모리 사용량이 너무 커지기 때문에 1차원 dp로 최적화했습니다.
3. dp[j]는 현재까지 탐색한 x의 prefix를 이용하여 z의 앞 j개 문자로 만들 수 있는 subsequence의 개수입니다.
4. z를 역순으로 탐색하며, x[i] == z[j]일 때, dp[j+1] += dp[j]로 업데이트 합니다. 이때 dp를 구현할 때 dp[0]에 빈 문자열에 대한 상태를 두었기 때문에 dp[j+1]은 z의 앞 j+1개 문자와 대응됩니다. 
z를 역순으로 탐색하는 이유는 z에 중복되는 문자가 있을 경우 한 x에서 dp를 여러번 더하게 되는데 이미 업데이트 된 dp[j-1] 값을 dp[j]값에 더하게 되는 문제가 생기기 때문입니다.
5. int 범위를 초과하는 정수를 더하기 위해, 숫자를 일의 자릿수부터 각 자릿수 별로 저장하였고, 덧셈하였을 때 10으로 나눈 나머지는 현재 자릿수에 저장, 몫은 다음 자리의 올림으로 계산하는 방식으로 구현하였습니다.
6. 답을 출력할 때는 앞에 불필요한 0을 제거하고 출력하는 방식으로 만들었습니다.

시간 복잡도:
X의 길이 n, Z의 길이 m일 때
O(n) * O(m) * add O(101)
따라서 O(nm)

