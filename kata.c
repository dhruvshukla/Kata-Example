#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimal2roman(int num);
void add(int roman_1, int roman_2);
void sub(int roman_3, int roman_4);

int main()
{
    int num1, num2, add_sub;
    printf("Enter 1 to add and 2 to subtract: ");
    scanf("%d", &add_sub);

    printf("Enter first decimal number to convert in roman number: ");
    scanf("%d", &num1);
    decimal2roman(num1);

    printf("Enter second decimal number to convert in roman number: ");
    scanf("%d", &num2);
    decimal2roman(num2);

    switch (add_sub)
    {
        case 1 : add(num1, num2);
        	 break;
        case 2 : sub(num1, num2);
        	 break;
        default: 
        	 break;
    }

    return 0;
}

void add(int roman_1, int roman_2)
{
    int result = roman_1 + roman_2;
    printf("Addition: ");
    decimal2roman(result);
}

void sub(int roman_3, int roman_4)
{  
    int result;
    if (roman_3 > roman_4)
    	result = roman_3 - roman_4;
    else
        result = roman_4 - roman_3;
    printf("Subtraction: ");
    decimal2roman(result);
}

void decimal2roman(int num)
{
    int roman[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};     
    char * sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };   
    char result[64] = "\0";         
    int i = 0;                    
    while (num)                  
    {
        while (num/roman[i])        
        {
            strcat(result, sym[i]);  
            num -= roman[i];       
        }
        i++;                  
    }
    printf("%s\n",result);
}

