/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_outil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:57:06 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 15:13:45 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
	len++;
	return (len);
}

int	ft_putnbr_exa_long(unsigned long int nb_long)
{
	unsigned long int	len_base;
	unsigned long int	temp_res;
	char				*base;
	int					len;

	if (nb_long == 0)
	{
		ft_putchar('0');
		return (1);
	}
	len_base = 16;
	len = 0;
	base = "0123456789abcdef";
	temp_res = 0;
	if (nb_long >= len_base)
		len += ft_putnbr_exa_long((nb_long / len_base));
	temp_res = nb_long % len_base;
	ft_putchar(base[temp_res]);
	len++;
	return (len);
}

int	ft_putnbr_exa(unsigned long int nb_long, char *base)
{
	unsigned long int	len_base;
	unsigned long int	temp_res;
	int					len;

	len = 0;
	len_base = 16;
	temp_res = 0;
	if (nb_long >= len_base)
		len += ft_putnbr_exa((nb_long / len_base), base);
	temp_res = nb_long % len_base;
	ft_putchar(base[temp_res]);
	len++;
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int					len;
	unsigned long int	addr;

	len = 0;
	addr = (unsigned long int)ptr;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += ft_putnbr_exa_long(addr);
	return (len);
}
