#include <stdio.h>

int main (void)
{
    int choice = 0;
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
}
 return (0);
}