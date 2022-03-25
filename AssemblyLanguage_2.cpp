/*
This is an Assembly language program to calculate the value of the function:
sigma(x) (i = -10) : (2i - 3)^2 - i, where -5 <= x <= 10
*/

#include <iostream>
using namespace std;

int x, rez, i = -10;

int main()
{
    printf("Enter the value of variable x: ");
    cin >> x;
    printf("\n-------Result of the calculation-------\r\n");
    if ((x >= -5) && (x <= 10)) {
        cout << "\r\nThe number you entered is: " << x << endl;
    }
    else {
        cout << "\r\nWrong value. Enter value from -5 to 10" << endl;
    }

    __asm
    {
        mov eax, x
        cmp eax, -5         // compare x to -5  
        jl invalid_value    // if x < -5 it is ivalid   
        cmp eax, 10         // compare x to 10
        jg invalid_value    // if x > 10 it is invalid        
        invalid_value :
            mov rez, -1     // display 0 as result

        mov eax, 0          // clear the eax registry
        mov ecx, i          // place the i value in the ecx registry
        mov ebx, 0          // assign initial value for ebx, this will be result 

        while_loop :
            mov eax, ecx    // move i to eax for calculations
            imul eax, 2     // 2*i
            sub eax, 3      // 2i - 3
            mul eax         // (2i - 3)^2
            sub eax, ecx    // (2i - 3)^2 - i

            add ebx, eax    // place the result in ebx
            inc ecx         // increment i by 1 = i++
            cmp ecx, x      // compare i to x
            jg exit_loop    // go to result if i > x
            jmp while_loop  // continue the loop

        exit_loop :
            mov rez, ebx

    }

    printf("\r\nResult: %d\n", rez);

}