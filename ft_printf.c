/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:56:39 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/06 21:20:15 by yael-maa         ###   ########.fr       */
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
               ret = ft_putstr(s); 
            }
        }
        else 
        {
            ret += write(1, &str[i++], 1);
        }
        i++;
    }
    va_end(args);
    return (ret);
}
int main()
{
    ft_printf("%c cc %s",'c',"yahya");
}