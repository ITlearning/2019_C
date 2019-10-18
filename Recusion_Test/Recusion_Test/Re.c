#include <stdio.h>
//팩토리얼 구하기
int factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

// X의 N승 구하기
double power(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return x * power(x, n - 1);
	}
}

//피보나치 수열 구하기
int fibonacci(int n) {
	if (n < 2) {
		return n;
	}
	else
		return fibonacci( n - 1) + fibonacci( n - 2);
}


//최대공약수 구하기
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

//문자열 길이 계산하기
int length(char *str) {
	if (*str == '\0')
		return 0;
	else
		return 1 + length(str + 1);
}

//문자열 출력하기
void printChars(char *str) {
	if (*str == '\0')
		return;
	else {
		printf("%c", *str);
		printChars(str + 1);
	}
}


//문자열 거꾸로 출력하기
void printCharsReverse(char *str) {
	if (*str == '\0')
		return;
	else {
		printCharsReverse(str + 1);
		printf("%c", *str);
	}
}

//순차 탐색하기
int search(int data[], int n, int target) {
	if (n <= 0) {
		return -1;
	}
	else if (target == data[n - 1])
		return n - 1;
	else search(data, n - 1, target);
}

int MAX(int x, int y) {
	if (x < y) {
		return y;
	}
	else{
		return x;
	}
}

int findMax(int n, int data[]) {
	if (n == 1)
		return data[0];
	else
		return MAX(data[n - 1], findMax(n - 1, data));
}

void printInBinary(int n) {
	if (n < 2)
		printf("%d", n);
	else {
		printInBinary(n / 2);
		printf("%d", n % 2);
	}
}

int binarySearch(int data[], int target, int begin, int end) {
	if (begin > end)
		return -1;
	else {
		int mid = (begin + end) / 2;
		if (data[mid] < target)
			return binarySearch(data, target, begin, mid - 1);
		else if (data[mid] == target)
			return mid;
		else return binarySearch(data, target, mid + 1, end);
	}
}

int main() {
	int a[5] = { 4, 5,3, 2,1 };
	printf("%d ",factorial(5));
	printf("\n");
	printf("%.f", power(4, 3));
	printf("\n");
	printf("%d", fibonacci(10));
	printf("\n");
	printf("%d", gcd(55, 20));
	printf("\n");
	printf("%d", length("HEllo"));
	printf("\n");
	printChars("HELLLO");
	printf("\n");
	printCharsReverse("HELWOD");
	printf("%d", search(a, 5, 5));
	printf("\n");
	printf("%d", findMax(5, a));
	printf("\n");
	printInBinary(134);
	printf("\n");
	printf("%d", binarySearch(a, 2, 0, 4));
}