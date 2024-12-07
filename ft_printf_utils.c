/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:56:10 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/07 18:49:19 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int ret;

    ret = 0;
    if (nb == -2147483648)
        ret += write(1, "-2147483648", 12);
    else if (nb < 0)
    {
        ret += write(1, "-", 1);
        ret +=ft_putnbr(-nb);
    }
    else if (nb >= 10)
    {
        ret += ft_putnbr(nb / 10);
        ret += ft_putnbr(nb % 10);
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

    ret = 0;
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
int ft_puthexa(unsigned long nb)
{
    char *str;
    int ret;

    ret = 0;
    str = "0123456789abcdef";
    if (nb < 16)
        ret += write(1, &str[nb], 1);
    else
    {
        ret += ft_puthexa(nb / 16);
        ret += ft_puthexa(nb % 16);
    }
    return (ret);
}
int FT_PUTHEXA(unsigned long nb)
{
    char *str;
    int ret;
    
    ret = 0;
    str = "0123456789ABCDEF";
    if (nb < 16)
        ret += write(1, &str[nb], 1);
    else
    {
        ret += FT_PUTHEXA(nb / 16);
        ret += FT_PUTHEXA(nb % 16);
    }
    return (ret);
}
int ft_put_address(void *ptr)
{
    int ret;
    
    ret = 0;
    ret += write(1, "0x", 2);
    ret += ft_puthexa((unsigned long)ptr);
    return (ret);
}