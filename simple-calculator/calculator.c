#include <stdio.h>

int main (void)
{
    int choice = 0;
    float a;
    float b;
    float sum;
    printf("Simple Calculator\n");

while(1)
{
    printf("1) Add \n");
    printf("2) Subtract\n");
    printf("3) Multiply\n");
    printf("4) Divide\n");
    printf("0) Quit\n"); 

    scanf("%d", &choice);

    printf("choice:%d\n", choice);

    if (choice > 4 || choice < 0)
        printf("invalid choice\n");
    else if (choice == 0)
    {
        printf("Bye!\n");
        break;
    }
    if (choice == 1)
    {
        printf("a: \n");
        scanf("%f", &a);
        printf("b: \n");
        scanf("%f", &b);

        printf("a:%f\nb:%f\n", a, b);
        
        sum = a + b;
        printf("Result: %f\n", sum); 
    }
    
        if (choice == 2)
    {    
        printf("a: \n");
        scanf("%f", &a);
        printf("b: \n");
        scanf("%f", &b);

        printf("a:%f\nb:%f\n", a, b);

        sum = a - b;
        printf("Result: %.2f\n", sum);

    }
}
 return (0);
}