/*
   3. https://www.acmicpc.net/problem/1748
   �� �̾� ���� 1
*/

/*
   1���� N������ ���� �̾ ���� ������ ���� ���ο� �ϳ��� ���� ���� �� �ִ�.
   
   1234567891011121314151617181920212223...
   
   �̷��� ������� ���ο� ���� �� �ڸ� ���ϱ�? �� ���� �ڸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

/*
   �Է�
   ù° �ٿ� N(1��N��100,000,000)�� �־�����.
   
   ���
   ù° �ٿ� ���ο� ���� �ڸ����� ����Ѵ�.
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