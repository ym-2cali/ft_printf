#include "ft_printf.h"

int ft_putchar(char c)
{
   return (write(1, &c, 1));
}

int ft_putstr(char  *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(1, &str[i], 1);
    return (i);
}

int ft_putnbr(int nb)
{
    static int ret;

    if (nb == -2147483648)
        ret = write(1, "-2147483648", 12);
    else if (nb < 0)
    {
        ret += write(1, "-", 1);
        ft_putnbr(-nb);
    }
    else if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
    {
        write(1, &(char){nb + '0'}, 1);
        ret++;
    }
    return (ret);
}

int ft_putunbr(unsigned int nb)
{
    int     ret;

    if (nb < 0)
        return (0);
    if (nb >= 10)
    {
        ret += ft_putunbr(nb / 10);
        ret += ft_putunbr(nb % 10);
    }
    else
        ret += write(1, &(char){nb + '0'}, 1);
    return (ret);
}
#include <stdio.h>
int main()
{
    printf("--%d--", ft_putunbr(-1));
}