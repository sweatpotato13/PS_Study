/*
   1. https://www.acmicpc.net/problem/2747
   �Ǻ���ġ ��
*/

/*
   �Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.
   
   �̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n>=2)�� �ȴ�.
   
   n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.
   
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
   
   n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

/*
   �Է�
   ù° �ٿ� n�� �־�����. n�� 45���� �۰ų� ���� �ڿ����̴�.
   
   ���
   ù° �ٿ� n��° �Ǻ���ġ ���� ����Ѵ�.
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