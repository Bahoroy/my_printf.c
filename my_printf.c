#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

char* reverseString(char* str) {
    int length = strlen(str);
    int middle = length / 2;
    for (int i = 0; i < middle; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    return str;
}

char* reverse(char* str, int flag) {
    int length = strlen(str);
    char* reversing = (char*)malloc(sizeof(char) * (length + 1));
    int i = 0;

    if (flag == 1) {
        reversing[i] = '-';
        i++;
    }

    for (int j = length - 1; j >= 0; j--) {
        reversing[i] = str[j];
        i++;
    }
    reversing[i] = '\0';
    return reversing;
}

int myputstr(char* str) {
    int length = strlen(str);
    write(1, str, length);
    return length;
}

char* decimalToOctal(int number) {
    char temp;
    char* octal = (char*)malloc(sizeof(char) * 20);
    int index = 0;

    if (number == 0) {
        octal[index] = '0';
        index++;
    }

    while (number != 0) {
        temp = number % 8 + '0';
        number = number / 8;
        octal[index] = temp;
        index++;
    }
    octal[index] = '\0';
    octal = reverseString(octal);
    return octal;
}

char* decimalToString(int num) {
    if (num == 0) {
        return "0";
    }

    char temp;
    int flag = 0;

    if (num < 0) {
        flag = 1;
        num = num * -1;
    }

    char* str = (char*)malloc(sizeof(char) * 20);
    int index = 0;

    while (num != 0) {
        temp = num % 10 + '0';
        num = num / 10;
        str[index] = temp;
        index++;
    }
    str[index] = '\0';
    str = reverse(str, flag);
    return str;
}

int decimalToHexadecimal(unsigned long number) {
    int i = 0;

    if (number == 0) {
        return '0';
    }

    char* hexChars = "0123456789abcdef";
    char* heex = malloc(sizeof(char) * 15);
    char hexDigit;

    while (number) {
        hexDigit = hexChars[number % 16];
        heex[i++] = hexDigit;
        number = number / 16;
    }
    // heex[i] = '\0';
    char* words = reverseString(heex);
    // free(heex);
    int length = myputstr(words);
    return length;
}

int decimalToHexadecimal_a(unsigned long number) {
    unsigned long decimalNumber = number;
    int index = 0, temp, b, win;
    char* hexNum = malloc(20);

    while (decimalNumber) {
        temp = decimalNumber % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hexNum[index++] = temp;
        decimalNumber = decimalNumber / 16;
    }
    hexNum[index] = '\0';

    for (win = index - 1; win >= 0; win--) {
        write(1, &hexNum[win], 1);
    }
    b = strlen(hexNum);
    // free(hexNum);
    return b;
}

int my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int num1, oct, res = 0, i = 0;
    char* decimalStr = NULL;
    // char* tempStr;
    char tempChar;
    unsigned int unsignedNum;
    unsigned long hex_a;
    unsigned long hex_b;
    char* octal = NULL;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'c') {
                tempChar = (char)va_arg(args, int);
                write(1, &tempChar, 1);
                res++;
            }
            if (format[i] == 's') {
                decimalStr = va_arg(args, char*);
                if (decimalStr == NULL) {
                    decimalStr = "(null)";
                }
                res += myputstr(decimalStr);
            }
            if (format[i] == 'd' || format[i] == 'i') {
                num1 = va_arg(args, int);
                decimalStr = decimalToString(num1);
                res += myputstr(decimalStr);
                // free(decimalStr);
            }
            if (format[i] == 'o') {
                oct = va_arg(args, int);
                octal = decimalToOctal(oct);
                res += myputstr(octal);
                free(octal);
            }
            if (format[i] == 'u') {
                unsignedNum = va_arg(args, unsigned int);
                decimalStr = decimalToString(unsignedNum);
                res += myputstr(decimalStr);
                free(decimalStr);
            }
            if (format[i] == 'x') {
                hex_a = va_arg(args, unsigned long);
                res += decimalToHexadecimal_a(hex_a);
            }
            if (format[i] == 'p') {
                hex_b = va_arg(args, long int);
                myputstr("0x");
                res+=2;
                res += decimalToHexadecimal(hex_b);
            }
        } else {
            write(1, &format[i], 1);
            res++;
        }
        i++;
    }
    va_end(args);
    return res;
}

int main() { 
    //char m[] = "hello";
    char c = 'a';
    printf("%d\n", c);
    my_printf("%p\n", c); 
    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'); 
    my_printf("Hello %s!\n", "QWASAR.IO"); 
    my_printf("Hello %s %s!\n", "Mr", "Gaetan"); 
    my_printf("%p\n", &c); 
    printf("%p\n", &c); 
    my_printf("%x!\n", 14); 
    return 0; 
}