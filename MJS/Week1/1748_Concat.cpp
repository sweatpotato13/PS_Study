/*
   3. https://www.acmicpc.net/problem/1748
   수 이어 쓰기 1
*/

/*
   1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
   
   1234567891011121314151617181920212223...
   
   이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.
*/

/*
   입력
   첫째 줄에 N(1≤N≤100,000,000)이 주어진다.
   
   출력
   첫째 줄에 새로운 수의 자릿수를 출력한다.
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    char inputNumber[10] = { NULL, };
    int number = 0;
    int count = 0;
    int length = 0;
    int powNum = 0;

    scanf("%s", inputNumber);
    number = atoi(inputNumber);
    length = strlen(inputNumber);
    powNum = pow(10, (9 - (length - 1)));

    if (number < 1 || number>100000000) {
        return 0;
    }

    if (number < 10) {
        count = number;
    }
    else {
        count = (number * length) - (9 * (123456789 / powNum));
    }
    
    printf("%d", count);

	return 0;
}