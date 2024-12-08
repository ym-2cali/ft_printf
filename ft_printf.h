/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:41 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/08 21:12:51 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	check_format(char c, va_list args);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthexa(unsigned long nb);
int	ft_upper_hexa(unsigned long nb);
int	ft_put_address(void *ptr);

#endif
