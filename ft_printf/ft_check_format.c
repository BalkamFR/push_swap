/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:16:04 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/01/14 14:51:31 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_handle_numerics(char type, va_list *args, int *count)
{
	int	ret;

	ret = 0;
	if (type == 'd' || type == 'i')
		ret = ft_print_nbr(va_arg(*args, int), count, 10, "0123456789");
	else if (type == 'u')
		ret = ft_print_nbr(va_arg(*args, unsigned int), count, 10,
				"0123456789");
	else if (type == 'x')
		ret = ft_print_nbr(va_arg(*args, unsigned int), count, 16,
				"0123456789abcdef");
	else if (type == 'X')
		ret = ft_print_nbr(va_arg(*args, unsigned int), count, 16,
				"0123456789ABCDEF");
	return (ret);
}

int	ft_check_format(const char **format, int *count, va_list *args)
{
	int	ret;

	ret = 0;
	if (**format == '%')
	{
		(*format)++;
		if (**format == '%')
			ret = ft_print_char('%', count);
		else if (**format == 'c')
			ret = ft_print_char((char)va_arg(*args, int), count);
		else if (**format == 's')
			ret = ft_print_str((char *)va_arg(*args, char *), count);
		else if (**format == 'p')
			ret = ft_pointer(count, args);
		else
			ret = ft_handle_numerics(**format, args, count);
		if (ret == -1)
			return (-1);
		(*format)++;
		return (1);
	}
	return (0);
}
