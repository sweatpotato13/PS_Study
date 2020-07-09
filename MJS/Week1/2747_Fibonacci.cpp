/*
   1. https://www.acmicpc.net/problem/2747
   피보나치 수
*/

/*
   피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
   
   이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.
   
   n=17일때 까지 피보나치 수를 써보면 다음과 같다.
   
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
   
   n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
*/

/*
   입력
   첫째 줄에 n이 주어진다. n은 45보다 작거나 같은 자연수이다.
   
   출력
   첫째 줄에 n번째 피보나치 수를 출력한다.
*/

#pragma warning(disable:4996)
#include <stdio.h>

int Fibonacci(int maxCount, int nowCount, int preNum, int nowNum) {
    if (nowCount++ < maxCount) {
        Fibonacci(maxCount, nowCount, nowNum, preNum + nowNum);
    }
    else {
        return preNum + nowNum;
    }
}

int main(void) {
	int fiboNumber = 0;
	int result = 0;
	
    scanf("%d", &fiboNumber);

    if(fiboNumber <= 45){
        if (fiboNumber == 0) {
            printf("%d", result);
        }
        else if (fiboNumber == 1) {
            printf("%d", result + 1);
        }
        else {
            result = Fibonacci(fiboNumber, 2, 0, 1);
            printf("%d", result);
        }
    }

       return 0;
}