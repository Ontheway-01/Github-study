#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void sixteen_to_ten(char* a, char* b, int* result);
//16������ 10������ �ٲٴ� �Լ�
void output(int* result, char o);
//�ٲۼ��� �����ڿ� ���� ����ϰ� �˸��� char������ ����ϴ� �Լ�
int main(void) {
    int result[2];
    //a��b�� 10������ �ٲ� �� ����
    char a[2];
    char b[2];
    char o;


    while (1) {
        printf("������� �Է��Ͻÿ� >> ");
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
    //0�� �ƽ�Ű �ڵ�� 48 �� 1-9������ �ƽ�Ű �ڵ�� 0�� 48�� ���� ���� ������ ����
    //7�� �ƽ�ũ �ڵ�� 55 �� 10������ �ƽ�Ű �ڵ�� 7�� 55�� ���� ���� ���� ����(10������ �ƽ�Ű�ڵ忡 55�� ���� ���� ����)

    result[0] = a0 * 16 + a1;
    result[1] = b0 * 16 + b1;
    //16�����̹Ƿ� ù��°�ڸ��� a0�� b0�� 16�� ���ϰ� a1�� b1����

}
void output(int* result, char o) {
    int total;
    //10���� ��� ��
    int ascii_num1 = 0, ascii_num2 = 0;
    //�ƽ�Ű �ڵ� ���� �����ϴ� ���� 2��
    int sub_ascii_num2 = 0;
    //�ƽ�Ű �ڵ� �ι�° ���� ���� �� ������ �ִ� ����
    switch (o) {
   
    case '+':
        total = 0;
        total = result[0] + result[1];
        ascii_num1 = total / 16 + '0';
        //total�� 16���� ���� �� �ƽ�Ű �ڵ� 0�� 48�� ���ϸ� char������ ��½� �˸��� �ƽ�Ű�ڵ� ���
        sub_ascii_num2 = total % 16;
        if (sub_ascii_num2 < 10) {
            ascii_num2 = total / 16 + '0';
        }
        //���� �������� 10���� ������ ascii_num1�� ���� ������� ����
        else {
            ascii_num2 = total % 16 + '7';
        }
        //���� �������� 10���� ũ�� �ƽ�Ű �ڵ尡 7�� 55�� ���ϸ� char������ ��½� �˸��� �ƽ�Ű�ڵ� ���
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
        printf("����� ����\n");
    }
    //�����ڿ� ���� ��°� ������ �޶���
}

