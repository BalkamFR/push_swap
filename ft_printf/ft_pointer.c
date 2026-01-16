/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:51:22 by ajeloyan          #+#    #+#             */
/*   Updated: 2025/12/09 16:57:16 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_print_conv_nbr(unsigned long long nb, int *count)
{
	char	*hexa_base;
	int		ret;

	hexa_base = "0123456789abcdef";
	if (nb >= 16)
	{
		ret = ft_print_conv_nbr(nb / 16, count);
		if (ret == -1)
			return (-1);
		if (ft_print_char(hexa_base[nb % 16], count) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_char(hexa_base[nb], count) == -1)
			return (-1);
	}
	return (0);
}

int	ft_pointer(int *count, va_list *args)
{
	uintptr_t	p;

	p = (uintptr_t)va_arg(*args, void *);
	if (p == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		(*count) += 5;
		return (1);
	}
	if (ft_print_str("0x", count) == -1)
		return (-1);
	ft_print_conv_nbr(p, count);
	return (1);
}
