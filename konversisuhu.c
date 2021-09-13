#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    double f;
    scanf("%d", &c);

    f = ( c * 9 / 5) + 32;
    printf("%.2f", f);
    return 0;
}
