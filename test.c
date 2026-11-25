
#include "header.h"
#define A 10
#define B 20
#define SUM(x,y) ((x)+(y))
#define SQUARE(x) ((x)*(x))
void fun(void)
{
    printf("Hello world\n");
}

int main()
{
    int a = A;
    int b = B;

    printf("%d\n", SUM(a,b));
    printf("%d\n", SQUARE(5));
    printf("%d\n",MAX);
    fun();

    return 0;
}
