// #include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
// int sum(int count, ...)
// {
//     va_list args;
//     int i;
//     int s = 0;

//     va_start(args, count);
//     for(i = 0; i < count; i++)
//     {
//         s += va_arg(args, int);
//     }
//     va_end(args);
//     return (s);
// }
#include <limits.h>

// int ft_putnbr(int nb)
// {
//     static int ret;

//     if (nb == -2147483648)
//         ret = write(1, "-2147483648", 12);
//     else if (nb < 0)
//     {
//         write(1, "-", 1);
//         ft_putnbr(-nb);
//     }
//     else if (nb >= 10)
//     {
//         ft_putnbr(nb / 10);
//         ft_putnbr(nb % 10);
//     }
//     else
//     {
//         write(1, &(char){nb + '0'}, 1);
//         ret++;
//     }
//     return (ret);
// }
int main()
{
    printf("--%d--", printf("%u\n", -1));
} 