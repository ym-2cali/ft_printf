/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:41 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/08 20:12:22 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
#include <stdio.h>
int	ft_printf(const char *, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int nb);
int ft_putunbr(unsigned int nb);
int ft_puthexa(unsigned long nb);
int FT_PUTHEXA(unsigned long nb);
int ft_put_address(void *ptr);

#endif
