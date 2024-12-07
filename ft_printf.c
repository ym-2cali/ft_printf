/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:56:39 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/07 21:34:53 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int ret;
    int i;
    char c;
    char    *s;
    
    i = 0;
    ret = 0;
    va_start(args, str); // printf("ajhfjkahfjk %% %d %c")
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'c')
            {
                c = va_arg(args, int);
                ret += write(1, &c, 1);
            }
            else if (str[i] == 's')
            {
               s = va_arg(args, char *);
               ret += ft_putstr(s); 
            }
            else if (str[i] == 'd' || str[i] == 'i')
                ret += ft_putnbr(va_arg(args, int));
            else if (str[i] == 'u')
            {
                ret += ft_putunbr(va_arg(args, unsigned int));
            }
            else if (str[i] == 'x')
                ret += ft_puthexa(va_arg(args, unsigned long));
            else if (str[i] == 'X')
                ret += FT_PUTHEXA(va_arg(args, unsigned long));
            else if (str[i] == 'p')
                ret += ft_put_address(va_arg(args, void *));
        }
        else 
        {
            ret += write(1, &str[i], 1);
        }
        i++;
    }
    va_end(args);
    return (ret);
}
// #include <stdio.h>

// int main()
// {
    // char *str;

    // str = "ab";
    // // printf("--%d--", ft_putnbr(-1));
    // // printf("--%d--", ft_puthexa(-1));
    // // ft_puthexa(18446744073709551615UL);
    // // printf("%lu\n", -1)
    // ft_printf("%d\n", printf("hello world %p\n", &str[1]));
    // printf("%d\n", ft_printf("hello world %p\n", &str[1]));
//     ft_printf("--%d--", ft_printf("NULL %s NULL", NULL));
// } 