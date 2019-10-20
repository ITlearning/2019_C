#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ���丮�� ���ϱ�
int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

// x�� n�� ���ϱ�
double power(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return (double)x * (double)power(x, n - 1);
}

// �Ǻ���ġ ���� ���ϱ�
int fibonacci(int n)
{
	if (n < 2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// �ִ����� ���ϱ�
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

// ���ڿ� ���� ����ϱ�
int length(char *str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + length(str + 1);
}

// ���ڿ� ����ϱ�
void printChars(char *str)
{
	if (*str == '\0')
		return;
	else {
		printf("%c", *str);
		printChars(str + 1);
	}
}

// ���ڿ� �Ųٷ� ����ϱ�
void printCharsReverse(char *str)
{
	if (*str == '\0')
		return;
	else {
		printCharsReverse(str + 1);
		printf("%c", *str);
	}
}

// ���� Ž���ϱ�
int search(int data[], int n, int target)
{
	if (n <= 0)
		return -1;
	else if (target == data[n - 1])
		return n - 1;
	else
		return search(data, n - 1, target);
}

int MAX(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}

// �ִ밪 ã��
int findMax(int n, int data[])
{
	if (n == 1)
		return data[0];
	else
		return MAX(data[n - 1], findMax(n - 1, data));
}

// ������ ����ϱ�
void printInBinary(int n)
{
	if (n < 2)
		printf("%d", n);
	else {
		printInBinary(n / 2);
		printf("%d", n % 2);
	}
}

int main() {

	srand(time(NULL));

	int data[20];
	data[14] = 3;

	int data2[5];
	
	for (int i = 0; i < 5; i++) {

		int num = (rand() % 60) + 1;
		data2[i] = num;
	}


	printf("���丮�� ���ϱ� \t: %d\n", factorial(5));
	printf("x�� n�� ���ϱ� \t\t: %.f\n", power(3, 4));
	printf("�Ǻ���ġ ���� ���ϱ� \t: %d\n", fibonacci(15));
	printf("�ִ����� ���ϱ� \t: %d\n", gcd(50, 4));
	printf("���ڿ� ���� ����ϱ� \t: %d\n", length("hhhhhhh"));
	printf("���ڿ� ����ϱ� \t: "); printChars("Hello"); 
	printf("\n���ڿ� �Ųٷ� ����ϱ� \t: "); printCharsReverse("Hello");
	printf("\n���� Ž���ϱ� \t\t: %d\n", search(data, 20, 3));
	printf("�ִ밪 ã��(1~60����) \t: %d \n", findMax(5, data2));
	printf("������ ����ϱ� \t: "); printInBinary(555);

}