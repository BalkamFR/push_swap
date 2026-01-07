/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:12:31 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 15:13:36 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

int	ft_print_arg(char type, va_list ap)
{
	if (type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (type == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (type == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (type == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (type == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (type == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	if (type == 'x')
		return (ft_putnbr_exa((unsigned int)va_arg(ap, int),
				"0123456789abcdef"));
	if (type == 'X')
		return (ft_putnbr_exa((unsigned int)va_arg(ap, int),
				"0123456789ABCDEF"));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf_arg(va_list ap, const char *list)
{
	int	i;
	int	compt;
	int	ret;

	i = 0;
	compt = 0;
	while (list[i])
	{
		if (list[i] == '%')
		{
			if (list[i + 1] == '\0')
				return (-1);
			ret = ft_print_arg(list[i + 1], ap);
			if (ret == -1)
				return (-1);
			compt += ret;
			i++;
		}
		else
			compt += ft_putchar(list[i]);
		i++;
	}
	return (compt);
}

int	ft_printf(const char *list, ...)
{
	int		i;
	va_list	ap;
	
	if (list == NULL)
		return(-1);	
	va_start(ap, list);
	i = ft_printf_arg(ap, list);
	va_end(ap);
	return (i);
}
