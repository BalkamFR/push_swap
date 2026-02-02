/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armenag <armenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:00:38 by ajeloyan          #+#    #+#             */
/*   Updated: 2025/12/12 21:39:16 by armenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_formats(const char *format, va_list *args)
{
	int		count;
	int		check_ret;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		check_ret = ft_check_format(&format, &count, args);
		if (check_ret == -1)
			return (-1);
		else if (check_ret == 0)
		{
			if (ft_print_char(*format, &count) == -1)
				return (-1);
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	count = ft_formats(format, &args);
	va_end(args);
	return (count);
}
