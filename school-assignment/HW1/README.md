Problem: Cooking delicious pancakes

Write a program for stacks of the delicious pancakes with the task.
▪ Cooking the perfect stack of pancakes on a grill is a tricky business,
  because no matter how hard you try all pancakes in any stack
  have different diameters.
▪ For neatness’s sake, however,
  you can sort the stack by size such that
  each pancake is smaller than all the pancakes below it.
▪ The size of pancake is given by its diameter.
▪ Write a program to help her with the task.
▪ Test Using 3 Different Data Sets.

=============Input=============
▪ Ex) 5 1 2 3 4
▪ The input consist of a sequence of stacks of pancakes.
▪ Each stack will consist of between 1 and 30 pancakes
and each pancake will have an integer diameter between 1 and 10.
▪ The input is terminated by end-of-file.
▪ Each stack is given as a single line of input
with the top pancake on a stack appearing first on a line,
the bottom pancake appearing last,
and all pancakes separated by a space.
================================

=============Output=============
▪ Ex) 5 1 2 3 4 (1 2 3 4 5) 1 2 0
▪ Original (sorted) flip 0
▪ For each stack of pancakes,
your program should echo the original stack on one line, followed by
a sequence of flips that results in sorting the stack of pancakes
so that the largest pancake is on the bottom and the smallest on top.
▪ The sequence of flips for each stack should be terminated by a 0,
indicating no more flips necessary.
▪ Once a stack is sorted, no more flips should be made.
================================

Solution: 

 기본 아이디어: 정렬되지 않은 구간에서 가장 큰 값을 찾고 맨 위로 오게 한번 뒤집고, 다시 정렬 되지 않은 구간의 맨 밑으로 가도록 한번더 뒤집는다. 이렇게 밑에서부터 정렬해나간다.


 =================구현 디테일=================
 입력값의 크기가 주어지지 않았기 때문에 최대 크기를 30으로 설정하고 입력값을 문자열로 받은 뒤 파싱.
 readArray는 EOF를 만나면 -1을 반환하고, main함수에서 -1을 반환받기 전까지 while문 돌림.
 for문으로 전체 탐색 하며 max값과 index 찾기. 이때 max의 위치가 이미 정렬되어야 할 위치라면 continue.
 정렬되지 않은 부분 중 max값이 가장 위로 오도록 뒤집기.
 그 후 max값이 정렬되지 않은 부분 중 가장 밑으로 가도록 한번더 뒤집고, 정렬된 횟수 + 1

 위 과정 반복하며 정렬.
 ===========================================

 시간 복잡도: O(n^2)
 findMax 함수에서 정렬되지 않은 구간을 n번 탐색하고, n번의 정렬단계를 거치며 최대 2번의 flip을 하기때문에 전체 시간 복잡도는 O(n^2)

 구현 함수

 int readArray(int[], int): 입력값 읽고 파싱
 int findMax(int, int, int): max 값의 index 찾기
 void flip(int[], int): 뒤집기 함수
