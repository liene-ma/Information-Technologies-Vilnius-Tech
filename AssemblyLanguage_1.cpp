/*
This is an Assembly language program to calculate the value of the function:
f(x) = 50 - 4x      ,when x < 9
f(x) = ((x-5)^3)/16 ,when x = 9
f(x) = 3x - (2x)    ,when x > 9
*/

#include <iostream>
using namespace std;

int x, rez;

int main()
{
    printf("Enter the value of variable x: ");
    cin >> x;

    printf("\n-------------------Results of the calculation-------------------\r\n");
    printf("\nWhen x < 9, the arithmetical operation is f(x) = 50 - 4x");
    printf("\nWhen x = 9, the arithmetical operation is f(x) = ((x-5)^3)/16");
    printf("\nWhen x > 9, the arithmetical operation is f(x) = 3x - (2x)\r\n");


    __asm 
    {
        mov eax, x     // move the value of x in eax

        cmp eax, 9     // 9 is the breaking point for this calculation
        jl less9
        je equal9
        jg more9

    less9:              // 50-4x
        imul eax, -4    // x * -4
        add eax, 50     // add 50
        jmp endIfThenStatement

    equal9:             // ((x-5)^3)/16
        sub eax, 5      // x - 5  
        mov ebx, eax    // move the result of eax in ebx for power operation
        imul eax, ebx   // (x - 5) * (x - 5)
        imul eax, ebx   // ((x - 5) * (x - 5)) * (x - 5)
        mov ecx, 16
        cdq;            // clear the register        
        idiv ecx        // divide eax with 16
        jmp endIfThenStatement

    more9:              // 3x-2x
        mov ebx, eax    // eax = x
        imul eax, 3     // 3x
        imul ebx, 2     // 2x
        sub eax, ebx    // 3x-2x
        jmp endIfThenStatement

    endIfThenStatement:
        mov rez, eax    // put the result in rez

    }


    printf("\nThe value entered for variable x: %d\n", x);
    printf("\nResult of the arithmetical operation: f(%d) = %d\r\n", x, rez);
}

