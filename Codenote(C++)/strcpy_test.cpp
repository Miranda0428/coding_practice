#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


int char_max_test() {

	char a = -128;                        // 출력이 뭘까요?
	unsigned char ua = 128;

	printf("char a is %d\n", a);
	printf("unsigned char a is %d\n", ua);

	return 0;

}

int strcopy_test() {

	char* str_test;                  // char* str_test = "Hello world!"; 불가!
	char sub[100] = "Hello world!";
	char result[100] = { 0, };

	printf("1. %s\n", sub);
	str_test = sub;
	printf("2. %s\n", str_test);

	strcpy(result, str_test);         // destination, source 순서!

	printf("3. %s\n", result);

	return 0;

}

int main() {

	char_max_test();
	strcopy_test();

	return 0;
}