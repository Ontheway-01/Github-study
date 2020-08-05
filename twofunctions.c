#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void sixteen_to_ten(char* a, char* b, int* result);
//16진수를 10진수로 바꾸는 함수
void output(int* result, char o);
//바꾼수를 연산자에 따라 계산하고 알맞은 char형으로 출력하는 함수
int main(void) {
    int result[2];
    //a와b를 10진수로 바꾼 값 저장
    char a[2];
    char b[2];
    char o;


    while (1) {
        printf("연산식을 입력하시오 >> ");
        scanf("%c%c %c %c%c", &a[0], &a[1], &o, &b[0], &b[1]);
        sixteen_to_ten(a, b, result);
        output(result, o);
    }


}
void sixteen_to_ten(char* a, char* b, int* result) {
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    a0 = a[0] - '0';
    a1 = a[1] - '7';
    b0 = b[0] - '0';
    b1 = b[1] - '7';
    //0은 아스키 코드로 48 즉 1-9까지의 아스키 코드는 0인 48을 빼면 원래 정수로 나옴
    //7은 아스크 코드로 55 즉 10부터의 아스키 코드는 7인 55를 빼면 원래 정수 나옴(10부터의 아스키코드에 55를 빼야 원래 정수)

    result[0] = a0 * 16 + a1;
    result[1] = b0 * 16 + b1;
    //16진법이므로 첫번째자리인 a0와 b0에 16을 곱하고 a1과 b1더함

}
void output(int* result, char o) {
    int total;
    //10진수 결과 값
    int ascii_num1 = 0, ascii_num2 = 0;
    //아스키 코드 값을 저장하는 정수 2개
    int sub_ascii_num2 = 0;
    //아스키 코드 두번째 값을 구할 때 도움을 주는 정수
    switch (o) {
   
    case '+':
        total = 0;
        total = result[0] + result[1];
        ascii_num1 = total / 16 + '0';
        //total을 16으로 나눈 몫에 아스키 코드 0인 48을 더하면 char혀으로 출력시 알맞은 아스키코드 출력
        sub_ascii_num2 = total % 16;
        if (sub_ascii_num2 < 10) {
            ascii_num2 = total / 16 + '0';
        }
        //나눈 나머지가 10보다 작으면 ascii_num1과 같은 방법으로 실행
        else {
            ascii_num2 = total % 16 + '7';
        }
        //나눈 나머지가 10보다 크면 아스키 코드가 7인 55를 더하면 char형으로 출력시 알맞은 아스키코드 출력
        printf("%c%c\n", ascii_num1, ascii_num2);
        break;
   
    case '-':
        total = 0;
        total = result[0] - result[1];
        ascii_num1 = total / 16 + '0';
        sub_ascii_num2 = total % 16;
        if (sub_ascii_num2 < 10) {
            ascii_num2 = total % 16 + '0';
        }
        else {
            ascii_num2 = total % 16 + '7';
        }
        printf("%c%c\n", ascii_num1, ascii_num2);
        break;
   
    case '/':
        total = 0;
        total = result[0] * result[1];
        ascii_num1 = total / 16 + '0';
        sub_ascii_num2 = total % 16;
        if (sub_ascii_num2 < 10) {
            ascii_num2 = total % 16 + '0';
        }
        else {
            ascii_num2 = total % 16 + '7';
        }
        printf("%c%c\n", ascii_num1, ascii_num2);
        break;
   
    case '*':
        total = 0;
        total = result[0] / result[1];
        ascii_num1 = total / 16 + '0';

        printf("%c\n", ascii_num1);
        break;
    
    default:
        printf("연산식 오류\n");
    }
    //연산자에 따라 출력과 연산이 달라짐
}

