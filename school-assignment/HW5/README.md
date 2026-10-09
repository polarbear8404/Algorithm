Saving ink
▪ Susan likes to make a line drawing with ink.
There‘re several dots on drawing paper.
Your job is to tell how to connect the dots
to minimize the amount of ink used.
▪ Susan connects the dots by drawing straight lines between pairs,
possibly lifting the pen between lines.
▪ When Susan is done there must be a
sequence of connected lines from any dot to any other dot.

▪ Input
▪ The input begins with a single positive integer on a line by itself
indicating the number of dots (0<n<30) on drawing paper.
For each dots, a line follows;
each following line contains two real numbers
indicating the (x, y) coordinates of the dots.
▪ Output
▪ Your program must print a single real number to two decimal places:
the minimum total length of ink lines that can connect all the dots. 

구현 아이디어:
minimum spanning tree를 구하는 문제라고 생각됐습니다..
주어진 점들의 거리를 weight로 생각하고, 최소 weight를 가지는 spanning tree를 구하는 방식으로 문제를 접근했습니다.
mst를 구하기 위해 prim algorithm 사용했습니다..
prim algorithm의 경우 binary heap을 사용하면 O(ElogV)의 시간복잡도를 가지지만 이번 케이스의 경우 완전 그래프이므로 O(n^2)으로 구현했습니다.

시간 복잡도
O(n^2)
