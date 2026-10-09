Problem: Fashionable dressmaker’s problem
▪ A fashionable dressmaker has N orders from customers which she must satisfy.
▪ The dressmaker can work on only one job in each day, and jobs usually take several days.
▪ For the ith job, the integer T_i (1 <= T_i <= 1,000) denotes the number of days it takes the dressmaker to finish the job.
▪ But popularity has its price.
▪ For each day of delay before starting to work on the ith job, the dressmaker has agreed to pay a fine of S_i (1 <= Si <= 10,000) cents per day.
▪ Help the dressmaker by writing a program to find the sequence of jobs with minimum total fine.

Input
▪ The input begins with a single positive integer on a line by itself indicating the number of the test cases, followed by a blank line.
▪ There is also a blank line between two consecutive cases.
▪ The first line of each contains an integer reporting the number of jobs N, where 1 <= N <= 1,000.
▪ The ith subsequent line contains the completion time T_iand daily penalty S_i for the ith job.

Output
▪ For each test case, your program should print the sequence of jobs with minimal fine.
▪ Each job should be represented by its position in the input.
▪ All integers should be placed on only one output line and each pair separated by one space.
▪ If multiple solutions are possible, print the first one in lexicographic order.
▪ The output of two consecutive cases must be separated by a blank line.

구현 아이디어:
골랐을 때 가장 이득이 큰 것을 고르는 식으로 그리디하게 풀면 되지 않을까 생각했습니다.
현재는 day와 fine 두 값에 따라 값이 의존적이기 때문에 한가지 값으로 줄이고자 하루당 비용을 생각했습니다.
하루당 비용을 계산해 큰 순서대로 정렬하고 고르면 답일거라고 생각했습니다.
하지만 부동소수점 문제 때문에 나누는 것보단 곱하는 것이 정확할거라고 생각했고 두 일의 하루당 비용을 비교할 때 식을 변형하면 T_a * S_b ? T_b * S_a 입니다.
따라서 정렬 하면서 정렬의 조건을 위 식의 결과로 하면 된다고 생각하고 풀었습니다.
정렬 알고리즘은 시간복잡도를 위해 qsort를 사용했고, compare 함수를 통해 문제에 맞는 정렬 기준을 적용했습니다.

시간 복잡도:
정렬 O(nlogn)
출력 O(n)
총 O(nlogn)
