/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:56:39 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/08 21:13:31 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address(void *ptr)
{
	int	ret;

	ret = 0;
	ret += write(1, "0x", 2);
	if (ptr == NULL)
		ret += write(1, "0", 1);
	else
		ret += ft_puthexa((unsigned long)ptr);
	return (ret);
}

int	check_format(char c, va_list args)
{
	int	ret;

	ret = 0;
	if (c == 'c')
	{
		c = va_arg(args, int);
		ret += write(1, &c, 1);
	}
	else if (c == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ret += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		ret += ft_puthexa(va_arg(args, unsigned int));
	else if (c == 'X')
		ret += ft_upper_hexa(va_arg(args, unsigned int));
	else if (c == 'p')
		ret += ft_put_address(va_arg(args, void *));
	else if (c == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;
	int		i;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ret += check_format(str[++i], args);
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}
