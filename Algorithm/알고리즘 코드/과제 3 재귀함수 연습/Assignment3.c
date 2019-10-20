#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 팩토리얼 구하기
int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

// x의 n승 구하기
double power(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return (double)x * (double)power(x, n - 1);
}

// 피보나치 수열 구하기
int fibonacci(int n)
{
	if (n < 2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// 최대공약수 구하기
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

// 문자열 길이 계산하기
int length(char *str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + length(str + 1);
}

// 문자열 출력하기
void printChars(char *str)
{
	if (*str == '\0')
		return;
	else {
		printf("%c", *str);
		printChars(str + 1);
	}
}

// 문자열 거꾸로 출력하기
void printCharsReverse(char *str)
{
	if (*str == '\0')
		return;
	else {
		printCharsReverse(str + 1);
		printf("%c", *str);
	}
}

// 순차 탐색하기
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

// 최대값 찾기
int findMax(int n, int data[])
{
	if (n == 1)
		return data[0];
	else
		return MAX(data[n - 1], findMax(n - 1, data));
}

// 이진수 출력하기
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


	printf("팩토리얼 구하기 \t: %d\n", factorial(5));
	printf("x의 n승 구하기 \t\t: %.f\n", power(3, 4));
	printf("피보나치 수열 구하기 \t: %d\n", fibonacci(15));
	printf("최대공약수 구하기 \t: %d\n", gcd(50, 4));
	printf("문자열 길이 계산하기 \t: %d\n", length("hhhhhhh"));
	printf("문자열 출력하기 \t: "); printChars("Hello"); 
	printf("\n문자열 거꾸로 출력하기 \t: "); printCharsReverse("Hello");
	printf("\n순차 탐색하기 \t\t: %d\n", search(data, 20, 3));
	printf("최대값 찾기(1~60랜덤) \t: %d \n", findMax(5, data2));
	printf("이진수 출력하기 \t: "); printInBinary(555);

}